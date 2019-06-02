//
// file gem_ndireceiver.cpp
// Created by Bartek
//

#include "gem_ndireceiver.hpp"
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

}