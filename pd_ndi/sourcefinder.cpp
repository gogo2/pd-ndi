//
// file sourcefinder.cpp
// Created by Bartosz Sobol
//

#include "sourcefinder.h"

void *ndisourcefinder_new() {
    auto *ndisourcefinder = (t_ndisourcefinder *) pd_new(ndisourcefinder_class);
    ndisourcefinder->ndi_sourcefinder = new pdndi::base::ndi_sourcefinder();
    return static_cast<void *>(ndisourcefinder);
}

void ndisourcefinder_delete(t_ndisourcefinder *ndisourcefinder) {
    delete ndisourcefinder->ndi_sourcefinder;
}

void ndisourcefinder_bang(t_ndisourcefinder *ndisourcefinder) {
    ndisourcefinder->ndi_sourcefinder->find_sources();
    std::ostringstream osstream;
    osstream << * ndisourcefinder->ndi_sourcefinder;
    post("ndisourcefinder sources:");
    post(osstream.str().c_str());
}


void ndisourcefinder_setup() {
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
