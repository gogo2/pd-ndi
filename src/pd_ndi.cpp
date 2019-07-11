//
// file pd_ndi.cpp
// Created by Bartosz Sobol
//

#include "gl_ndisender.h"
#include "sourcefinder.h"

extern "C" void pd_ndi_setup() {
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


    ndisourcefinder_class = class_new(
            gensym("ndisourcefinder"),
            (t_newmethod) ndisourcefinder_new,
            (t_method) ndisourcefinder_delete,
            sizeof(t_ndisourcefinder),
            CLASS_DEFAULT,
            A_GIMME,
            0);

    class_addbang(ndisourcefinder_class, ndisourcefinder_bang);
}
