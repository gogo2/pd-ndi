//
// file pd_ndi.cpp
// Created by Bartosz Sobol
//

#include "gl_ndisender.h"
#include "sourcefinder.h"

extern "C" void pd_ndi_setup() {

    setup_gl_ndisender();
    setup_ndisourcefinder();

}

