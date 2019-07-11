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
    NDIlib_recv_destroy(pNDI_recv_);
    NDIlib_destroy();
}

bool NDIReceiver::find_sources() {
    return source_finder.find_sources();
}

void NDIReceiver::connect(uint32_t source) {
    if (source < source_finder.no_sources()) {
        NDIlib_recv_connect(pNDI_recv_, source_finder.p_sources() + (source * sizeof(NDIlib_source_t)));
    }
}

std::pair<bool, bool> NDIReceiver::receive_frame() {
    bool video = false, audio = false;
    switch (NDIlib_recv_capture_v2(pNDI_recv_, &NDI_video_frame_, &NDI_audio_frame_, nullptr, 5000)) {
        case NDIlib_frame_type_none:
            printf("No data received.\n");
            break;
        case NDIlib_frame_type_video:
            printf("Video data received (%dx%d).\n", NDI_video_frame_.xres, NDI_video_frame_.yres);
            NDIlib_recv_free_video_v2(pNDI_recv_, &NDI_video_frame_);
            video = true;
            break;
        case NDIlib_frame_type_audio:
            printf("Audio data received (%d samples).\n", NDI_audio_frame_.no_samples);
            NDIlib_recv_free_audio_v2(pNDI_recv_, &NDI_audio_frame_);
            audio = true;
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
