//
// file NDIReceiver.cpp
// Created by Bartosz Sobol
//

#include <iostream>
#include "NDIReceiver.hpp"

NDIReceiver::NDIReceiver() : source_finder{}, pNDI_recv_(nullptr), NDI_video_frame_{}, NDI_audio_frame_{} {
    if (!NDIlib_initialize()) {
        std::cerr << "Error initializing NDI\n";
    }
    pNDI_recv_ = NDIlib_recv_create_v3();
    if (pNDI_recv_ == nullptr) {
        std::cerr << "Error initializing NDI receiver\n";
    }
}

NDIReceiver::~NDIReceiver() {
    NDIlib_recv_free_video_v2(pNDI_recv_, &NDI_video_frame_);
    NDIlib_recv_free_audio_v2(pNDI_recv_, &NDI_audio_frame_);
    NDIlib_recv_destroy(pNDI_recv_);
    NDIlib_destroy();
}

bool NDIReceiver::find_sources() noexcept {
    return source_finder.find_sources();
}

void NDIReceiver::connect(uint32_t source) noexcept {
    if (source < source_finder.no_sources()) {
        NDIlib_recv_connect(pNDI_recv_, source_finder.p_sources() + source);
    }
}

std::pair<bool, bool> NDIReceiver::receive_frame() noexcept {
    bool video = false, audio = false;
    switch (NDIlib_recv_capture_v2(pNDI_recv_, &NDI_video_frame_, &NDI_audio_frame_, nullptr, 50)) {
        case NDIlib_frame_type_video:
            video = true;
            break;
        case NDIlib_frame_type_audio:
            audio = true;
            break;
        case NDIlib_frame_type_none:
        case NDIlib_frame_type_error:
        case NDIlib_frame_type_metadata:
        case NDIlib_frame_type_status_change:
        case NDIlib_frame_type_max:
            break;
    }
    return {video, audio};
}

const NDIlib_video_frame_v2_t &NDIReceiver::NDI_video_frame() noexcept {
    return NDI_video_frame_;
}

const NDIlib_audio_frame_v2_t &NDIReceiver::NDI_audio_frame() noexcept {
    return NDI_audio_frame_;
}
