//
// file NDIReceiver.cpp
// Created by Bartek
//

#include <iostream>
#include "NDIReceiver.hpp"

NDIReceiver::NDIReceiver() : source_finder_{}, pNDI_recv_(nullptr) {
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

void NDIReceiver::find_sources() {
    source_finder_.find_sources();
}

void NDIReceiver::connect(uint32_t source) {
    NDIlib_recv_connect(pNDI_recv_, source_finder_.p_sources() + (source * sizeof(NDIlib_source_t)));
}

void NDIReceiver::receive_frame() {
    NDIlib_video_frame_v2_t NDI_video_frame;
    NDIlib_audio_frame_v2_t NDI_audio_frame;

    switch (NDIlib_recv_capture_v2(pNDI_recv_, &NDI_video_frame, &NDI_audio_frame, nullptr, 5000)) {
        case NDIlib_frame_type_none:
            printf("No data received.\n");
            break;
        case NDIlib_frame_type_video:
            printf("Video data received (%dx%d).\n", NDI_video_frame.xres, NDI_video_frame.yres);
            NDIlib_recv_free_video_v2(pNDI_recv_, &NDI_video_frame);
            break;
        case NDIlib_frame_type_audio:
            printf("Audio data received (%d samples).\n", NDI_audio_frame.no_samples);
            NDIlib_recv_free_audio_v2(pNDI_recv_, &NDI_audio_frame);
            break;
    }

}
