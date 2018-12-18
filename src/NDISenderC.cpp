//
// file NDISenderC.c
// Created by Bartek
//

#include "NDISender.hpp"
#include "NDISenderC.h"


NDISenderC *NDISender_create(int screen_width, int screen_height) {
    return reinterpret_cast<NDISenderC *>(new NDISender(screen_width, screen_height));
}

void NDISender_destroy(NDISenderC *sender_ptr) {
    delete reinterpret_cast<NDISender *>(sender_ptr);
}

void NDISender_send_frame(NDISenderC *sender_ptr) {
    reinterpret_cast<NDISender *>(sender_ptr)->send_frame();
}

void *NDISender_p_data(NDISenderC *sender_ptr) {
    return reinterpret_cast<NDISender *>(sender_ptr)->p_data();
}

void NDISender_resize_frame(NDISenderC *sender_ptr, int screen_width, int screen_height) {
    reinterpret_cast<NDISender *>(sender_ptr)->resize_screen(screen_width, screen_height);
}

void NDISender_set_framerate(NDISenderC *sender_ptr, int max_fps) {
    reinterpret_cast<NDISender *>(sender_ptr)->set_framerate(max_fps);
}
