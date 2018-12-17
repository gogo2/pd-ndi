//
// file NDISenderC.c
// Created by Bartek
//

#include <memory>
#include "NDISender.hpp"
#include "NDISenderC.h"

static std::unique_ptr<NDISenderC> _ndi_sender = nullptr;

int NDISenderC_create() {
    int ret_value = -1;
    try {
        _ndi_sender = std::make_unique<NDISender>();
        ret_value = 0; /* success */
    } catch (...) {}
    return ret_value;
}




