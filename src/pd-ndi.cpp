//
// file pd-ndi.c
// Created by Bartek
//
extern "C" {
#include "m_pd.h"
}

#include "pd-ndi.hpp"


static t_class *pd_ndi_class;

typedef struct _pd_ndi {
    t_object x_obj;

    PdGlNdiConnector ndi_connector{};

} t_pd_ndi;


void ndisender_bang(t_pd_ndi *x) {
    post("Hello world !!");
}

void *ndisender_new() {
    auto *x = (t_pd_ndi *) pd_new(pd_ndi_class);
    return (void *) x;
}


void pd_ndi_setup() {
    printf("ddd");
    pd_ndi_class = class_new(
            gensym("ndisender"),
            (t_newmethod) ndisender_new,
            nullptr,
            sizeof(t_pd_ndi),
            CLASS_DEFAULT,
            A_GIMME,
            0);
    class_addbang(pd_ndi_class, ndisender_bang);
}

