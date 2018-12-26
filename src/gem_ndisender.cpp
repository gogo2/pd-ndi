//
// file hem_ndisender.cpp
// Created by Bartosz Sobol
//

#include "gem_ndisender.hpp"

namespace pdndi {

    CPPEXTERN_NEW(ndisender);

    ndisender::ndisender() : ndi_sender_{800, 600} {}


    void ndisender::render(GemState *state) {
        GLuint frame_tex;
        GLint vport_dim[4];

        glGetIntegerv(GL_VIEWPORT, vport_dim);
        glEnable(GL_TEXTURE_RECTANGLE_EXT);
        glGenTextures(1, &frame_tex);
        glBindTexture(GL_TEXTURE_RECTANGLE_EXT, frame_tex);
        glTexImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, GL_RGBA8, vport_dim[2], vport_dim[3], 0, GL_BGRA, GL_UNSIGNED_BYTE, nullptr);
        glCopyTexSubImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, 0, 0, vport_dim[0], vport_dim[1], vport_dim[2], vport_dim[3]);

        if (frame_tex) {
            ndi_sender_.resize_screen(vport_dim[2], vport_dim[3]);
            glGetTexImage(GL_TEXTURE_RECTANGLE_EXT, 0, GL_BGRA, GL_UNSIGNED_BYTE, ndi_sender_.p_video_frame_data());
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

    void ndisender::obj_setupCallback(_class *classPtr) {}


}
