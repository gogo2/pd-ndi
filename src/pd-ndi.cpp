//
// file pd-ndi.c
// Created by Bartek
//
#define GLEW_STATIC

#include <memory.h>
#include <stdlib.h>
#include "glew/glew.h"
#include "m_pd.h"
#include "pd-ndi.hpp"

static t_class *pd_ndi_class;

void *pd_ndi_new() {
    auto *pd_ndi = (t_pd_ndi *) pd_new(pd_ndi_class);
    pd_ndi->ndi_connector = new PdGlNdiConnector(pd_ndi);
    return static_cast<void *>(pd_ndi);
}

void pd_ndi_delete(t_pd_ndi *pd_ndi) {
    delete pd_ndi->ndi_connector;
}

void pd_ndi_bang(t_pd_ndi *x) {
    x->ndi_connector->bang();
}

void pd_ndi_resize_screen(t_pd_ndi *x, t_floatarg width, t_floatarg height) {
    char buff[10];
    x->ndi_connector->resize_screen((int) width, (int) height);
    itoa((int) (width), buff, 10);
    post(buff);
    itoa((int) (height), buff, 10);
    post(buff);
}

void pd_ndi_set_framerate(t_pd_ndi *x, t_floatarg max_fps) {
    char buff[10];
    x->ndi_connector->set_framerate((int) max_fps);
    post("ndi max_fps:");
    itoa((int) (max_fps), buff, 10);
    post(buff);
}

void pd_ndi_send_framebuffer(t_pd_ndi *x, t_floatarg fbo) {
    x->ndi_connector->send_framebuffer((int) fbo);
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

PdGlNdiConnector::PdGlNdiConnector(t_pd_ndi *const pd_ndi) : pd_ndi_(pd_ndi), ndi_sender_{800, 600} {
    post("connector created");
}

void PdGlNdiConnector::bang() {
    for (int i = 0; i < 300; ++i) {
        ndi_sender_.send_frame();
        memset(ndi_sender_.p_data(), (i & 1) ? 255 : 0, 800 * 600 * 4);
    }
}

void PdGlNdiConnector::resize_screen(int screen_width, int screen_height) noexcept {
    ndi_sender_.resize_screen(screen_width, screen_height);
}

void PdGlNdiConnector::set_framerate(int max_fps) noexcept {
    ndi_sender_.set_framerate(max_fps);
}

void PdGlNdiConnector::send_framebuffer(int tex) {
    glBindTexture(GL_TEXTURE_2D, (GLuint) tex);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, ndi_sender_.p_data());
    ndi_sender_.send_frame();
}

