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

class NDIReceiver final {
public:

    NDIReceiver() = default;

    NDIReceiver(const NDIReceiver &) = delete;

    NDIReceiver(const NDIReceiver &&) = delete;

    NDIReceiver &operator=(const NDIReceiver &) = delete;

    NDIReceiver &operator=(const NDIReceiver &&) = delete;

    ~NDIReceiver() = default;

    void find_sources();

    void connect(int source);


private:



};


#endif //PD_NDI_NDIRECEIVER_HPP
