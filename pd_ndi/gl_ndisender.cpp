//
// file gl_ndisender.cpp
// Created by Bartosz Sobol
//

#include "gl_ndisender.h"

void *gl_ndisender_new() {
    auto *gl_ndisender = (t_gl_ndisender *) pd_new(gl_ndisender_class);
    gl_ndisender->ndi_sender = new ndi_sender(256, 256);
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
    post("gl_ndisender max_fps: %d", static_cast<int>( max_fps));
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
    post("gl_ndisender screen size:");
    post("width: %d\n height: %d", width, height);
}


void gl_ndisender_setup(){
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
    class_addmethod(gl_ndisender_class, (t_method) gl_ndisender_resize_screen, gensym("dimen"),
                    A_DEFFLOAT, A_DEFFLOAT, 0);
    class_addmethod(gl_ndisender_class, (t_method) gl_ndisender_set_framerate, gensym("fps"),
                    A_DEFFLOAT, 0);
}
