//
// file NDISender.cpp
// Created by Bartosz Sobol
//

#include "NDISender.hpp"
#include <iostream>


NDISender::NDISender(const int screen_width, const int screen_height, const int max_fps) : pNDI_send_(nullptr),
                                                                                           NDI_video_frame_{} {
    if (!NDIlib_initialize()) {
        std::cerr << "Error initializing NDI\n";
    }
    if (pNDI_send_ = NDIlib_send_create(); pNDI_send_ == nullptr) {
        std::cerr << "Error initializing NDI sender\n";
    }
    NDI_video_frame_.xres = screen_width;
    NDI_video_frame_.yres = screen_height;
    NDI_video_frame_.FourCC = NDIlib_FourCC_type_RGBA;
    NDI_video_frame_.p_data = (uint8_t *) malloc(
            static_cast<unsigned>(NDI_video_frame_.xres * NDI_video_frame_.yres * 4));
    NDI_video_frame_.frame_rate_N = max_fps;
    NDI_video_frame_.frame_rate_D = 1;
}

NDISender::~NDISender() {
    free(NDI_video_frame_.p_data);
    NDIlib_send_destroy(pNDI_send_);
    NDIlib_destroy();
}

void *NDISender::p_data() noexcept {
    return static_cast<void * >(NDI_video_frame_.p_data);
}

void NDISender::send_frame() {
    NDIlib_send_send_video_v2(pNDI_send_, &NDI_video_frame_);
}

void NDISender::resize_screen(const int screen_width, const int screen_height) noexcept {
    NDI_video_frame_.xres = screen_width;
    NDI_video_frame_.yres = screen_height;
    realloc(NDI_video_frame_.p_data, static_cast<unsigned>(NDI_video_frame_.xres * NDI_video_frame_.yres * 4));
}

void NDISender::set_framerate(const int max_fps) noexcept {
    NDI_video_frame_.frame_rate_N = max_fps;
}
