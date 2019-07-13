//
// file pd_ndi.cpp
// Created by Bartosz Sobol
//

#include "gl_ndisender.h"
#include "sourcefinder.h"

extern "C" void ndisender_setup();
//
extern "C" void ndireceiver_setup();

extern "C" void pd_ndi_setup() {
    ndisender_setup();
    ndireceiver_setup();
    setup_gl_ndisender();
    setup_ndisourcefinder();

}

