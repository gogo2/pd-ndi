//
// file sourcefinder.cpp
// Created by Bartek
//

#include "sourcefinder.h"

void *ndisourcefinder_new() {
    auto *ndisourcefinder = (t_ndisourcefinder *) pd_new(ndisourcefinder_class);
    ndisourcefinder->ndi_sourcefinder = new NDISourceFinder();
    return static_cast<void *>(ndisourcefinder);
}

void ndisourcefinder_delete(t_ndisourcefinder *ndisourcefinder) {
    delete ndisourcefinder->ndi_sourcefinder;
}

void ndisourcefinder_bang(t_ndisourcefinder *ndisourcefinder) {
    ndisourcefinder->ndi_sourcefinder->find_sources();
    std::ostringstream osstream;
    osstream << std::endl << ndisourcefinder->ndi_sourcefinder;
    post("ndireceiver sources:");
    post(osstream.str().c_str());
}


