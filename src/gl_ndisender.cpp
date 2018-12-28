//
// file gl_ndisender.cpp
// Created by Bartosz Sobol
//
#define GLEW_STATIC

#include <memory.h>
#include <cstdlib>
#include <string>
#include "glew/glew.h"
#include "m_pd.h"
#include "NDISender.hpp"

static t_class *gl_ndisender_class;

struct t_gl_ndisender {
    t_object x_obj;
    NDISender *ndi_sender;
};

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
    gl_ndisender->ndi_sender->resize_screen(static_cast<int> (width), static_cast<int>(height));
    post(std::to_string(static_cast<int> (width)).c_str());
    post(std::to_string(static_cast<int> (height)).c_str());
}

void gl_ndisender_set_framerate(t_gl_ndisender *gl_ndisender, t_floatarg max_fps) {
    gl_ndisender->ndi_sender->set_framerate(static_cast<int> (max_fps));
    post("ndi max_fps:");
    post(std::to_string(static_cast<int>( max_fps)).c_str());
}

void gl_ndisender_send_texture_2d(t_gl_ndisender *gl_ndisender, t_floatarg tex) {
    glBindTexture(GL_TEXTURE_2D, (GLuint) tex);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_BYTE, gl_ndisender->ndi_sender->p_video_frame_data());
    gl_ndisender->ndi_sender->send_frame();
}

extern "C" void pd_ndi_setup() {
    gl_ndisender_class = class_new(
            gensym("gl_ndisender"),
            (t_newmethod) gl_ndisender_new,
            (t_method) gl_ndisender_delete,
            sizeof(t_gl_ndisender),
            CLASS_DEFAULT,
            A_GIMME,
            0);

    class_addbang(gl_ndisender_class, gl_ndisender_bang);
    class_addfloat(gl_ndisender_class, (t_method) gl_ndisender_send_texture_2d);
    class_addmethod(gl_ndisender_class, (t_method) gl_ndisender_resize_screen, gensym("dimen"), A_DEFFLOAT, A_DEFFLOAT,
                    0);
    class_addmethod(gl_ndisender_class, (t_method) gl_ndisender_set_framerate, gensym("fps"), A_DEFFLOAT, 0);
}

