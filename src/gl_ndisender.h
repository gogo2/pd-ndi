//
// file gl_ndisender.h
// Created by Bartosz Sobol
//
#define GLEW_STATIC

#include <memory.h>
#include <cstdlib>
#include <string>
#include "glew/glew.h"
#include "m_pd.h"
#include "NDIBase/NDISender.hpp"

static t_class *gl_ndisender_class;

struct t_gl_ndisender {
    t_object x_obj;
    NDISender *ndi_sender;
};

void *gl_ndisender_new();

void gl_ndisender_delete(t_gl_ndisender *gl_ndisender);

void gl_ndisender_bang(t_gl_ndisender *gl_ndisender);

void gl_ndisender_resize_screen(t_gl_ndisender *gl_ndisender, t_floatarg width, t_floatarg height);

void gl_ndisender_set_framerate(t_gl_ndisender *gl_ndisender, t_floatarg max_fps);

void gl_ndisender_send_texture_2d(t_gl_ndisender *gl_ndisender, t_floatarg tex);
