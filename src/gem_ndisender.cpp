//
// file hem_ndisender.cpp
// Created by Bartosz Sobol
//

#include "gem_ndisender.hpp"

namespace pdndi {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

    CPPEXTERN_NEW(ndisender);

#pragma GCC diagnostic pop

    ndisender::ndisender() : ndi_sender_{500, 500} {
        inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("fps"));
        p_pixel_transfer_data = (uint8_t *) malloc(static_cast<unsigned>(500 * 500 * 4));
    }

    ndisender::~ndisender() {
        free(p_pixel_transfer_data);
    }

    void ndisender::render(GemState *state) {
        GLuint frame_tex;
        GLint vport_dim[4];

        glGetIntegerv(GL_VIEWPORT, vport_dim);
        const int vport_width = vport_dim[2];
        const int vport_height = vport_dim[3];
        glGenTextures(1, &frame_tex);
        glBindTexture(GL_TEXTURE_2D, frame_tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, vport_width, vport_height, 0, GL_BGRA, GL_UNSIGNED_BYTE,
                     nullptr);
        glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, vport_dim[0], vport_dim[1], vport_width, vport_height);

        if (frame_tex) {
            resize_screen(vport_width, vport_height);
            glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_BYTE, p_pixel_transfer_data);
            for (int i = 0; i < vport_height; ++i) {
                memcpy((uint8_t *) ndi_sender_.p_video_frame_data() + i * vport_width * 4,
                       p_pixel_transfer_data + vport_width * 4 * (vport_height - i - 1),
                       static_cast<size_t >(vport_width) * 4);
            }
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

    void ndisender::resize_screen(const int screen_width, const int screen_height) {
        if (ndi_sender_.width() * ndi_sender_.height() != screen_width * screen_height) {
            ndi_sender_.resize_screen(screen_width, screen_height);
            p_pixel_transfer_data = (uint8_t *) realloc(p_pixel_transfer_data,
                                                        static_cast<unsigned>(screen_width * screen_height * 4));
        }
    }

    void ndisender::obj_setupCallback(_class *classPtr) {
        CPPEXTERN_MSG1(classPtr, "fps", set_framerate, float);
    }

}
