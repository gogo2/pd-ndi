//
// file pd-ndi.cpp
// Created by Bartosz Sobol
//
#define GLEW_STATIC

#include <memory.h>
#include <cstdlib>
#include <string>
#include "glew/glew.h"
#include "m_pd.h"
#include "NDISender.hpp"

static t_class *pd_ndi_class;

struct t_pd_ndi {
    t_object x_obj;

    NDISender *ndi_sender;

};

void *pd_ndi_new() {
    auto *pd_ndi = (t_pd_ndi *) pd_new(pd_ndi_class);
    pd_ndi->ndi_sender = new NDISender(256, 256);
    return static_cast<void *>(pd_ndi);
}

void pd_ndi_delete(t_pd_ndi *pd_ndi) {
    delete pd_ndi->ndi_sender;
}

void pd_ndi_bang(t_pd_ndi *pd_ndi) {
    for (int i = 0; i < 30; ++i) {
        pd_ndi->ndi_sender->send_frame();
        memset(pd_ndi->ndi_sender->p_video_frame_data(), (i & 1) ? 255 : 0,
               (unsigned) pd_ndi->ndi_sender->width() * pd_ndi->ndi_sender->height() * 4);
    }
}

void pd_ndi_resize_screen(t_pd_ndi *pd_ndi, t_floatarg width, t_floatarg height) {
    pd_ndi->ndi_sender->resize_screen((int) width, (int) height);
    post(std::to_string((int) width).c_str());
    post(std::to_string((int) height).c_str());
}

void pd_ndi_set_framerate(t_pd_ndi *pd_ndi, t_floatarg max_fps) {
    pd_ndi->ndi_sender->set_framerate((int) max_fps);
    post("ndi max_fps:");
    post(std::to_string((int) max_fps).c_str());
}

void pd_ndi_send_framebuffer(t_pd_ndi *pd_ndi, t_floatarg tex) {
    glBindTexture(GL_TEXTURE_2D, (GLuint) tex);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_BYTE, pd_ndi->ndi_sender->p_video_frame_data());
    pd_ndi->ndi_sender->send_frame();
}

extern "C" void pd_ndi_setup() {
    printf("ddd");
    pd_ndi_class = class_new(
            gensym("ndisender"),
            (t_newmethod) pd_ndi_new,
            (t_method) pd_ndi_delete,
            sizeof(t_pd_ndi),
            CLASS_DEFAULT,
            A_GIMME,
            0);
    class_addbang(pd_ndi_class, pd_ndi_bang);
    class_addfloat(pd_ndi_class, (t_method) pd_ndi_send_framebuffer);
    class_addmethod(pd_ndi_class, (t_method) pd_ndi_resize_screen, gensym("dimen"), A_DEFFLOAT, A_DEFFLOAT, 0);
    class_addmethod(pd_ndi_class, (t_method) pd_ndi_set_framerate, gensym("fps"), A_DEFFLOAT, 0);
}

