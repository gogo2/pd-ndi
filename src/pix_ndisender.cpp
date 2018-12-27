//
// file pix_ndisender.cpp
// Created by Bartosz Sobol
//
#define GLEW_STATIC

#include <memory.h>
#include <cstdlib>
#include <string>
#include "glew/glew.h"
#include "m_pd.h"
#include "NDISender.hpp"

static t_class *pix_ndisender_class;

struct t_pix_ndisender {
    t_object x_obj;
    NDISender *ndi_sender;
};

void *pix_ndisender_new() {
    auto *pix_ndisender = (t_pix_ndisender *) pd_new(pix_ndisender_class);
    pix_ndisender->ndi_sender = new NDISender(256, 256);
    return static_cast<void *>(pix_ndisender);
}

void pix_ndisender_delete(t_pix_ndisender *pix_ndisender) {
    delete pix_ndisender->ndi_sender;
}

void pix_ndisender_bang(t_pix_ndisender *pix_ndisender) {
    for (int i = 0; i < 30; ++i) {
        pix_ndisender->ndi_sender->send_frame();
        memset(pix_ndisender->ndi_sender->p_video_frame_data(), (i & 1) ? 255 : 0,
               static_cast<unsigned >( pix_ndisender->ndi_sender->width() * pix_ndisender->ndi_sender->height() * 4));
    }
}

void pix_ndisender_resize_screen(t_pix_ndisender *pix_ndisender, t_floatarg width, t_floatarg height) {
    pix_ndisender->ndi_sender->resize_screen(static_cast<int> (width), static_cast<int>(height));
    post(std::to_string(static_cast<int> (width)).c_str());
    post(std::to_string(static_cast<int> (height)).c_str());
}

void pix_ndisender_set_framerate(t_pix_ndisender *pix_ndisender, t_floatarg max_fps) {
    pix_ndisender->ndi_sender->set_framerate(static_cast<int> (max_fps));
    post("ndi max_fps:");
    post(std::to_string(static_cast<int>( max_fps)).c_str());
}

void pix_ndisender_send_texture_2d(t_pix_ndisender *pix_ndisender, t_floatarg tex) {
    glBindTexture(GL_TEXTURE_2D, (GLuint) tex);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_BYTE, pix_ndisender->ndi_sender->p_video_frame_data());
    pix_ndisender->ndi_sender->send_frame();
}

extern "C" void pd_ndi_setup() {
    pix_ndisender_class = class_new(
            gensym("pix_ndisender"),
            (t_newmethod) pix_ndisender_new,
            (t_method) pix_ndisender_delete,
            sizeof(t_pix_ndisender),
            CLASS_DEFAULT,
            A_GIMME,
            0);

    class_addbang(pix_ndisender_class, pix_ndisender_bang);
    class_addfloat(pix_ndisender_class, (t_method) pix_ndisender_send_texture_2d);
    class_addmethod(pix_ndisender_class, (t_method) pix_ndisender_resize_screen, gensym("dimen"), A_DEFFLOAT, A_DEFFLOAT, 0);
    class_addmethod(pix_ndisender_class, (t_method) pix_ndisender_set_framerate, gensym("fps"), A_DEFFLOAT, 0);
}

