//
// file gl_ndisender.h
// Created by Bartosz Sobol
//
#define GLEW_STATIC

#include <memory.h>
#include <cstdlib>
#include <string>
#include "GL/glew.h"
#include "m_pd.h"
#include "ndi_base/ndi_sender.hpp"

static t_class *gl_ndisender_class;

struct t_gl_ndisender {
    t_object x_obj;
    pdndi::base::ndi_sender *ndi_sender;
};

void *gl_ndisender_new();

void gl_ndisender_delete(t_gl_ndisender *gl_ndisender);

void gl_ndisender_bang(t_gl_ndisender *gl_ndisender);

void gl_ndisender_resize_screen(t_gl_ndisender *gl_ndisender, t_floatarg width, t_floatarg height);

void gl_ndisender_set_framerate(t_gl_ndisender *gl_ndisender, t_floatarg max_fps);

void gl_ndisender_send_texture_2d(t_gl_ndisender *gl_ndisender, t_floatarg tex);

void gl_ndisender_post_size(int width, int height);

void gl_ndisender_setup();
