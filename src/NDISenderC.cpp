//
// file NDISenderC.cpp
// Created by Bartosz Sobol
//

#include "NDISender.hpp"
#include "NDISenderC.h"

#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "OCDFAInspection"

NDISenderC *NDISender_create(const int screen_width, const int screen_height) {
    return reinterpret_cast<NDISenderC *>(new NDISender(screen_width, screen_height));
}

void NDISender_destroy(NDISenderC *const sender_ptr) {
    delete reinterpret_cast<NDISender *>(sender_ptr);
}

void NDISender_send_frame(NDISenderC *const sender_ptr) {
    reinterpret_cast<NDISender *>(sender_ptr)->send_frame();
}

void *NDISender_p_data(NDISenderC *const sender_ptr) {
    return reinterpret_cast<NDISender *>(sender_ptr)->p_data();
}

void NDISender_resize_frame(NDISenderC *const sender_ptr, const int screen_width, const int screen_height) {
    reinterpret_cast<NDISender *>(sender_ptr)->resize_screen(screen_width, screen_height);
}

void NDISender_set_framerate(NDISenderC *const sender_ptr, const int max_fps) {
    reinterpret_cast<NDISender *>(sender_ptr)->set_framerate(max_fps);
}
