//
// file pd-ndi.h
// Created by Bartek
//

#ifndef PD_NDI_PD_NDI_H
#define PD_NDI_PD_NDI_H

#include <m_pd.h>


static t_class *ndisender_class;

typedef struct _ndisender {
    t_object x_obj;
} t_ndisender;

void ndisender_bang(t_ndisender *x) {
    post("Hello world !!");
}

void *ndisender_new(void) {
    t_ndisender *x = (t_ndisender *) pd_new(ndisender_class);
    return (void *) x;
}

void ndisender_setup(void) {
    ndisender_class = class_new(gensym("helloworld"), (t_newmethod) ndisender_new, 0, sizeof(t_ndisender),
                                CLASS_DEFAULT, 0);
    class_addbang(ndisender_class, ndisender_bang);
}


#endif //PD_NDI_PD_NDI_H
