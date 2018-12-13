//
// Created by Bartek on 24.11.2018.
//

#include "NDISender.h"
#include <iostream>
#include <thread>
#include <GL/gl.h>


NDISender::NDISender(int screen_width, int screen_height, int max_fps = 30) : pNDI_send_(nullptr), NDI_video_frame_{} {
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

void *NDISender::p_data() {
    return (void *) NDI_video_frame_.p_data;
}

void NDISender::send_frame() {
    NDIlib_send_send_video_v2(pNDI_send_, &NDI_video_frame_);
}

void NDISender::resize_screen(int screen_width, int screen_height) {
    NDI_video_frame_.xres = screen_width;
    NDI_video_frame_.yres = screen_height;
    realloc(NDI_video_frame_.p_data, static_cast<unsigned>(NDI_video_frame_.xres * NDI_video_frame_.yres * 4));
}
