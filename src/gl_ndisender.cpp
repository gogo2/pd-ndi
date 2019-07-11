//
// file gl_ndisender.cpp
// Created by Bartosz Sobol
//


#include "gl_ndisender.h"
#include <sstream>

void *gl_ndisender_new() {
    auto *gl_ndisender = (t_gl_ndisender *) pd_new(gl_ndisender_class);
    gl_ndisender->ndi_sender = new NDISender(256, 256);
    return static_cast<void *>(gl_ndisender);
}

void gl_ndisender_delete(t_gl_ndisender *gl_ndisender) {
    delete gl_ndisender->ndi_sender;
}

void gl_ndisender_bang(t_gl_ndisender *gl_ndisender) {
    for (int i = 0; i < 30; ++i) {
        gl_ndisender->ndi_sender->send_frame();
        memset(gl_ndisender->ndi_sender->p_video_frame_data(), (i & 1) ? 255 : 0,
               static_cast<unsigned >( gl_ndisender->ndi_sender->width() * gl_ndisender->ndi_sender->height() * 4));
    }
}

void gl_ndisender_resize_screen(t_gl_ndisender *gl_ndisender, t_floatarg width, t_floatarg height) {
    if (gl_ndisender->ndi_sender->width() * gl_ndisender->ndi_sender->height() !=
        static_cast<int> (width) * static_cast<int>(height)) {
        gl_ndisender->ndi_sender->resize_screen(static_cast<int> (width), static_cast<int>(height));
    }
    gl_ndisender_post_size(static_cast<int> (width), static_cast<int> (height));
}

void gl_ndisender_set_framerate(t_gl_ndisender *gl_ndisender, t_floatarg max_fps) {
    gl_ndisender->ndi_sender->set_framerate(static_cast<int> (max_fps));
    post("ndi max_fps:");
    post(std::to_string(static_cast<int>( max_fps)).c_str());
}

void gl_ndisender_send_texture_2d(t_gl_ndisender *gl_ndisender, t_floatarg tex) {
    int width{}, height{};

    glBindTexture(GL_TEXTURE_2D, (GLuint) tex);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);

    if (gl_ndisender->ndi_sender->width() * gl_ndisender->ndi_sender->height() != width * height) {
        gl_ndisender->ndi_sender->resize_screen(width, height);
        gl_ndisender_post_size(width, height);
    }

    glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_BYTE, (void *) (gl_ndisender->ndi_sender->p_video_frame_data()));
    gl_ndisender->ndi_sender->send_frame();
}

void gl_ndisender_post_size(int width, int height) {
    std::ostringstream osstream;
    osstream << std::endl << "width: " << width << std::endl << "height: " << height;
    post("gl_ndisender screen size:");
    post(osstream.str().c_str());
}

