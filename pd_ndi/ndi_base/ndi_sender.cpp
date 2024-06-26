//
// file ndi_sender.cpp
// Created by Bartosz Sobol
//

#include "ndi_sender.hpp"
#include <iostream>
#include <m_pd.h>

namespace pdndi { namespace base {

    ndi_sender::ndi_sender(const int screen_width, const int screen_height, const int max_fps) : pNDI_send_(nullptr),
                                                                                                 NDI_video_frame_{} {
        if (!NDIlib_initialize()) {
            pd_error(nullptr, "Error initializing NDI");
        }
        pNDI_send_ = NDIlib_send_create();
        if (pNDI_send_ == nullptr) {
            pd_error(nullptr, "Error initializing NDI sender");
        }
        NDI_video_frame_.xres = screen_width;
        NDI_video_frame_.yres = screen_height;
        NDI_video_frame_.FourCC = NDIlib_FourCC_type_BGRA;
        NDI_video_frame_.p_data = (uint8_t *) malloc(
                static_cast<unsigned>(NDI_video_frame_.xres * NDI_video_frame_.yres * 4));
        NDI_video_frame_.frame_rate_N = max_fps;
        NDI_video_frame_.frame_rate_D = 1;
    }

    ndi_sender::~ndi_sender() {
        free(NDI_video_frame_.p_data);
        NDIlib_send_destroy(pNDI_send_);
        NDIlib_destroy();
    }

    uint8_t *ndi_sender::p_video_frame_data() noexcept {
        return NDI_video_frame_.p_data;
    }

    void ndi_sender::send_frame() noexcept {
        NDIlib_send_send_video_v2(pNDI_send_, &NDI_video_frame_);
    }

    void ndi_sender::resize_screen(const int screen_width, const int screen_height) noexcept {
        if (NDI_video_frame_.xres * NDI_video_frame_.yres != screen_height * screen_width) {
            NDI_video_frame_.xres = screen_width;
            NDI_video_frame_.yres = screen_height;
            NDI_video_frame_.p_data = (uint8_t *) realloc(NDI_video_frame_.p_data,
                                                          static_cast<unsigned>(NDI_video_frame_.xres *
                                                                                NDI_video_frame_.yres * 4));
        }
    }

    void ndi_sender::set_framerate(const int max_fps) noexcept {
        NDI_video_frame_.frame_rate_N = max_fps;
    }

    int ndi_sender::width() const noexcept {
        return NDI_video_frame_.xres;
    }

    int ndi_sender::height() const noexcept {
        return NDI_video_frame_.yres;
    }

}}