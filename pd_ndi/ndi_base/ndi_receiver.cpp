//
// file ndi_receiver.cpp
// Created by Bartosz Sobol
//

#include <iostream>
#include "ndi_receiver.hpp"

namespace pdndi { namespace base {

    ndi_receiver::ndi_receiver() : source_finder{}, pNDI_recv_(nullptr), NDI_video_frame_{}, NDI_audio_frame_{} {
        if (!NDIlib_initialize()) {
            std::cerr << "Error initializing NDI\n";
        }
        pNDI_recv_ = NDIlib_recv_create_v3();
        if (pNDI_recv_ == nullptr) {
            std::cerr << "Error initializing NDI receiver\n";
        }
    }

    ndi_receiver::~ndi_receiver() {
        NDIlib_recv_free_video_v2(pNDI_recv_, &NDI_video_frame_);
        NDIlib_recv_free_audio_v2(pNDI_recv_, &NDI_audio_frame_);
        NDIlib_recv_destroy(pNDI_recv_);
        NDIlib_destroy();
    }

    bool ndi_receiver::find_sources() noexcept {
        return source_finder.find_sources();
    }

    void ndi_receiver::connect(uint32_t source) noexcept {
        if (source < source_finder.no_sources()) {
            NDIlib_recv_connect(pNDI_recv_, source_finder.p_sources() + source);
        }
    }

    NDIlib_frame_type_e ndi_receiver::receive_frame() noexcept {
        return NDIlib_recv_capture_v2(pNDI_recv_, &NDI_video_frame_, &NDI_audio_frame_, nullptr, 50);
    }

    const NDIlib_video_frame_v2_t &ndi_receiver::NDI_video_frame() noexcept {
        return NDI_video_frame_;
    }

    const NDIlib_audio_frame_v2_t &ndi_receiver::NDI_audio_frame() noexcept {
        return NDI_audio_frame_;
    }

}}