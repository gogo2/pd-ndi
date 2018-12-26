//
// Created by Bartek on 26.12.2018.
//

#include "GemNDISender.h"

CPPEXTERN_NEW(GemNDISender);

GemNDISender::GemNDISender() : ndi_sender_{800, 600} {

}


void GemNDISender::render(GemState *state) {
    GLuint frame_tex;
    GLint viewport_dimen[4];

    glGetIntegerv(GL_VIEWPORT, viewport_dimen);
    glEnable(GL_TEXTURE_RECTANGLE_EXT);
    glGenTextures(1, &frame_tex);
    glBindTexture(GL_TEXTURE_RECTANGLE_EXT, frame_tex);
    glTexImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, GL_RGBA8, viewport_dimen[2], viewport_dimen[3], 0, GL_BGRA,
                 GL_UNSIGNED_BYTE, nullptr);
    glCopyTexSubImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, 0, 0, viewport_dimen[0], viewport_dimen[1], viewport_dimen[2],
                        viewport_dimen[3]);

    if (frame_tex) {
        ndi_sender_.resize_screen(viewport_dimen[2], viewport_dimen[3]);
        glGetTexImage(GL_TEXTURE_RECTANGLE_EXT, 0, GL_BGRA, GL_UNSIGNED_BYTE, ndi_sender_.p_video_frame_data());
        ndi_sender_.send_frame();
    }


}

void GemNDISender::obj_setupCallback(_class *classPtr) {}

