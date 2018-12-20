//
// file pd-ndi.c
// Created by Bartek
//
#include <memory.h>
#include "m_pd.h"
#include "pd-ndi.hpp"

static t_class *pd_ndi_class;

void *pd_ndi_new() {
    auto *pd_ndi = (t_pd_ndi *) pd_new(pd_ndi_class);
    pd_ndi->ndi_connector = new PdGlNdiConnector(pd_ndi);
    return static_cast<void *>(pd_ndi);
}

void pd_ndi_delete(t_pd_ndi *pd_ndi) {
    delete pd_ndi->ndi_connector;
}

void pd_ndi_bang(t_pd_ndi *x) {
    x->ndi_connector->bang();
}

extern "C" void pd_ndi_setup() {
    printf("ddd");
    pd_ndi_class = class_new(
            gensym("ndisender"),
            (t_newmethod) pd_ndi_new,
            (t_method) pd_ndi_delete,
            sizeof(t_pd_ndi),
            CLASS_DEFAULT,
            A_GIMME,
            0);
    class_addbang(pd_ndi_class, pd_ndi_bang);
}

PdGlNdiConnector::PdGlNdiConnector(t_pd_ndi *const pd_ndi) : pd_ndi_(pd_ndi), ndi_sender_{800, 600} {
    post("connector created");
}

void PdGlNdiConnector::bang() {
    for (int i = 0; i < 300; ++i) {
        ndi_sender_.send_frame();
        memset(ndi_sender_.p_data(), (i & 1) ? 255 : 0, 800 * 600 * 4);
    }
}

