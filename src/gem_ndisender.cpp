//
// file hem_ndisender.cpp
// Created by Bartosz Sobol
//

#include "gem_ndisender.hpp"

namespace pdndi {

    CPPEXTERN_NEW(ndisender);

    ndisender::ndisender() : ndi_sender_{800, 600} {
        inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("fps"));
    }


    void ndisender::render(GemState *state) {
        GLuint frame_tex;
        GLint vport_dim[4];

        glGetIntegerv(GL_VIEWPORT, vport_dim);
        glGenTextures(1, &frame_tex);
        glBindTexture(GL_TEXTURE_2D, frame_tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, vport_dim[2], vport_dim[3], 0, GL_BGRA, GL_UNSIGNED_BYTE,
                     nullptr);
        glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, vport_dim[0], vport_dim[1], vport_dim[2], vport_dim[3]);

        if (frame_tex) {
            ndi_sender_.resize_screen(vport_dim[2], vport_dim[3]);
            glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_BYTE, ndi_sender_.p_video_frame_data());
            ndi_sender_.send_frame();
            glDeleteTextures(1, &frame_tex);
        }

    }

    void ndisender::startRendering() {
        post("ndisender: start transmission");
    }

    void ndisender::stopRendering() {
        post("ndisender: stop transmission");
    }

    void ndisender::set_framerate(const float max_fps) {
        ndi_sender_.set_framerate(static_cast<int>(max_fps));
    }

    void ndisender::obj_setupCallback(_class *classPtr) {
        CPPEXTERN_MSG1(classPtr, "fps", set_framerate, float);
    }

}
