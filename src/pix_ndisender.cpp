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

static t_class *pix_ndi_class;

struct t_pix_ndi {
    t_object x_obj;

    NDISender *ndi_sender;

};

void *pix_ndi_new() {
    auto *pix_ndi = (t_pix_ndi *) pd_new(pix_ndi_class);
    pix_ndi->ndi_sender = new NDISender(256, 256);
    return static_cast<void *>(pix_ndi);
}

void pix_ndi_delete(t_pix_ndi *pix_ndi) {
    delete pix_ndi->ndi_sender;
}

void pix_ndi_bang(t_pix_ndi *pix_ndi) {
    for (int i = 0; i < 30; ++i) {
        pix_ndi->ndi_sender->send_frame();
        memset(pix_ndi->ndi_sender->p_video_frame_data(), (i & 1) ? 255 : 0,
               (unsigned) pix_ndi->ndi_sender->width() * pix_ndi->ndi_sender->height() * 4);
    }
}

void pix_ndi_resize_screen(t_pix_ndi *pix_ndi, t_floatarg width, t_floatarg height) {
    pix_ndi->ndi_sender->resize_screen((int) width, (int) height);
    post(std::to_string((int) width).c_str());
    post(std::to_string((int) height).c_str());
}

void pix_ndi_set_framerate(t_pix_ndi *pix_ndi, t_floatarg max_fps) {
    pix_ndi->ndi_sender->set_framerate((int) max_fps);
    post("ndi max_fps:");
    post(std::to_string((int) max_fps).c_str());
}

void pix_ndi_send_framebuffer(t_pix_ndi *pix_ndi, t_floatarg tex) {
    glBindTexture(GL_TEXTURE_2D, (GLuint) tex);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_BYTE, pix_ndi->ndi_sender->p_video_frame_data());
    pix_ndi->ndi_sender->send_frame();
}

extern "C" void pd_ndi_setup() {
    printf("ddd");
    pix_ndi_class = class_new(
            gensym("pix_ndisender"),
            (t_newmethod) pix_ndi_new,
            (t_method) pix_ndi_delete,
            sizeof(t_pix_ndi),
            CLASS_DEFAULT,
            A_GIMME,
            0);
    class_addbang(pix_ndi_class, pix_ndi_bang);
    class_addfloat(pix_ndi_class, (t_method) pix_ndi_send_framebuffer);
    class_addmethod(pix_ndi_class, (t_method) pix_ndi_resize_screen, gensym("dimen"), A_DEFFLOAT, A_DEFFLOAT, 0);
    class_addmethod(pix_ndi_class, (t_method) pix_ndi_set_framerate, gensym("fps"), A_DEFFLOAT, 0);
}

