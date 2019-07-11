//
// file gem_ndireceiver.cpp
// Created by Bartosz Sobol
//

#include "gem_ndireceiver.hpp"
#include "gem_ndisender.hpp"
#include <sstream>

namespace pdndi {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

    CPPEXTERN_NEW_WITH_ONE_ARG(ndireceiver, t_floatarg, A_DEFFLOAT);

#pragma GCC diagnostic pop

    ndireceiver::ndireceiver() {
        inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("source"));
        p_pixel_transfer_data = (uint8_t *) malloc(static_cast<unsigned>(500 * 500 * 4));
    }

    ndireceiver::ndireceiver(t_float source) : ndireceiver{} {
        set_source(static_cast<uint32_t >(source));
    }

    ndireceiver::~ndireceiver() {
        free(p_pixel_transfer_data);
    }

    void ndireceiver::startRendering() {
        post("ndireceiver: start receiving");
    }

    void ndireceiver::stopRendering() {
        post("ndireceiver: stop receiving");
    }

    void ndireceiver::render(GemState *state) {

    }

    void ndireceiver::find_sources() {
        ndi_receiver_.find_sources();
        post_sources();
    }

    void ndireceiver::post_sources() {
        std::ostringstream osstream;
        osstream << std::endl << ndi_receiver_.source_finder;
        post("ndireceiver sources:");
        post(osstream.str().c_str());
    }

    void ndireceiver::set_source(uint32_t source) {
        ndi_receiver_.connect(source);
    }

    void ndireceiver::obj_setupCallback(struct _class *classPtr) {
        CPPEXTERN_MSG0(classPtr, "find_sources", find_sources);
        CPPEXTERN_MSG1(classPtr, "source", set_source, uint32_t);
    }

}