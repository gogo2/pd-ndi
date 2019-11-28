//
// file ndi_sourcefinder.cpp
// Created by Bartosz Sobol
//


#include "ndi_sourcefinder.hpp"

ndi_sourcefinder::ndi_sourcefinder() : pNDI_find_(nullptr), no_sources_(0), p_sources_(nullptr) {
    if (!NDIlib_initialize()) {
        std::cerr << "Error initializing NDI\n";
    }
    pNDI_find_ = NDIlib_find_create_v2();
    if (pNDI_find_ == nullptr) {
        std::cerr << "Error initializing NDI finder\n";
    }
}

ndi_sourcefinder::~ndi_sourcefinder() {
    NDIlib_find_destroy(pNDI_find_);
    NDIlib_destroy();
}

bool ndi_sourcefinder::find_sources() noexcept {
    NDIlib_find_wait_for_sources(pNDI_find_, 1000);
    p_sources_ = NDIlib_find_get_current_sources(pNDI_find_, &no_sources_);
    return no_sources_ > 0;
}

const NDIlib_source_t *ndi_sourcefinder::p_sources() const noexcept {
    return p_sources_;
}

uint32_t ndi_sourcefinder::no_sources() const noexcept {
    return no_sources_;
}

std::ostream &operator<<(std::ostream &ostream, const ndi_sourcefinder &source_finder){
    if (source_finder.no_sources_ > 0) {
        for (uint32_t i = 0; i < source_finder.no_sources_; i++) {
            ostream << i << "\t" << source_finder.p_sources_[i].p_ndi_name << std::endl;
        }
    } else {
        ostream << "No sources detected during last check" << std::endl;
    }
    return ostream;
}

