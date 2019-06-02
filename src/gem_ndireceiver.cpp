//
// file gem_ndireceiver.cpp
// Created by Bartek
//

#include "gem_ndireceiver.hpp"
#include <sstream>
namespace pdndi{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

    CPPEXTERN_NEW(ndireceiver);

#pragma GCC diagnostic pop

    ndireceiver::ndireceiver() {

    }

    ndireceiver::~ndireceiver() {

    }

    void ndireceiver::startRendering() {
        post("ndireceiver: start receiving");
    }

    void ndireceiver::stopRendering() {
        post("ndireceiver: stop receiving");
    }

    void ndireceiver::render(GemState *state) {

    }

    void ndireceiver::obj_setupCallback(struct _class *classPtr) {

    }

    void ndireceiver::find_sources() {
        ndi_receiver_.find_sources();
        post_sources();
    }

    void ndireceiver::post_sources() {
        //ndi_receiver_.find_sources();
        std::ostringstream osstream;
        osstream << ndi_receiver_.source_finder;
        post("ndireceiver sources:");
        post(osstream.str().c_str());
    }

}