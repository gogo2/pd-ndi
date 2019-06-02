//
// file NDIReceiver.hpp
// Created by Bartek
//

#ifndef PD_NDI_NDIRECEIVER_HPP
#define PD_NDI_NDIRECEIVER_HPP

#include <cstddef>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <NDI/Processing.NDI.Lib.h>

#pragma GCC diagnostic pop

#include "NDISourceFinder.hpp"

class NDIReceiver final {
public:

    NDIReceiver();

    NDIReceiver(const NDIReceiver &) = delete;

    NDIReceiver(const NDIReceiver &&) = delete;

    NDIReceiver &operator=(const NDIReceiver &) = delete;

    NDIReceiver &operator=(const NDIReceiver &&) = delete;

    ~NDIReceiver();

    void find_sources();

    void connect(uint32_t source);

    void receive_frame();


private:
    NDISourceFinder source_finder_;
    NDIlib_recv_instance_t pNDI_recv_;


};


#endif //PD_NDI_NDIRECEIVER_HPP
