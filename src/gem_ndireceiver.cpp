//
// file gem_ndireceiver.cpp
// Created by Bartosz Sobol
//

#include <sstream>
#include "gem_ndireceiver.hpp"

namespace pdndi {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

    CPPEXTERN_NEW_WITH_ONE_ARG(ndireceiver, t_floatarg, A_DEFFLOAT);

#pragma GCC diagnostic pop

    ndireceiver::ndireceiver() : pix_block_{}, ndi_receiver_{} {
        pix_block_.image.csize = 4;
        inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("source"));
    }

    ndireceiver::ndireceiver(t_float source) : ndireceiver{} {
        set_source(static_cast<uint32_t >(source));
    }

    void ndireceiver::startRendering() {
        post("ndireceiver: start receiving");
    }

    void ndireceiver::stopRendering() {
        post("ndireceiver: stop receiving");
    }

    void ndireceiver::render(GemState *state) {
        auto result = ndi_receiver_.receive_frame();
        pix_block_.newimage = false;
        if (result == NDIlib_frame_type_video) {
            auto ndi_frame = ndi_receiver_.NDI_video_frame();
            if (ndi_frame.xres != pix_block_.image.xsize || ndi_frame.yres != pix_block_.image.ysize) {
                pix_block_.image.xsize = ndi_frame.xres;
                pix_block_.image.ysize = ndi_frame.yres;
                pix_block_.image.reallocate();
            }

            switch (ndi_frame.FourCC) {
                case NDIlib_FourCC_type_BGRA:
                case NDIlib_FourCC_type_BGRX:
                    pix_block_.image.fromBGRA(ndi_frame.p_data);
                    break;
                case NDIlib_FourCC_type_RGBA:
                case NDIlib_FourCC_type_RGBX:
                    pix_block_.image.fromRGBA(ndi_frame.p_data);
                    break;
                case NDIlib_FourCC_type_UYVY:
                    pix_block_.image.fromUYVY(ndi_frame.p_data);
                    break;
                case NDIlib_FourCC_type_YV12:
                    pix_block_.image.fromYV12(ndi_frame.p_data);
                    break;
                case NDIlib_FourCC_type_UYVA:
                    pix_block_.image.fromUYVY(ndi_frame.p_data);
                    break;
                case NDIlib_FourCC_type_I420:
                    pix_block_.image.fromYUV420P(ndi_frame.p_data);
                    break;
                default:
                    error("ndireceiver: not supported color format");
                    break;
            }

            pix_block_.newimage = true;
        } else {}

        state->set(GemState::_PIX, &pix_block_);
    }

    void ndireceiver::find_sources() {
        ndi_receiver_.find_sources();
        post_sources();
    }

    void ndireceiver::post_sources() {
        std::ostringstream osstream;
        osstream << std::endl << ndi_receiver_.source_finder;
        post("ndireceiver sources:\n %s", osstream.str().c_str());
    }

    void ndireceiver::set_source(uint32_t source) {
        post("ndireceiver: new source: %d", source);
        ndi_receiver_.connect(source);
    }

    void ndireceiver::obj_setupCallback(struct _class *classPtr) {
        CPPEXTERN_MSG0(classPtr, "find_sources", find_sources);
        CPPEXTERN_MSG1(classPtr, "source", set_source, uint32_t);
    }

}