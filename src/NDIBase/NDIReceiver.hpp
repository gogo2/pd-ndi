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

    bool find_sources();

    void connect(uint32_t source);

    std::pair<bool, bool> receive_frame();

    const NDIlib_video_frame_v2_t & NDI_video_frame() noexcept;

    const NDIlib_audio_frame_v2_t & NDI_audio_frame() noexcept;

    NDISourceFinder source_finder;

private:

    NDIlib_recv_instance_t pNDI_recv_;
    NDIlib_video_frame_v2_t NDI_video_frame_;
    NDIlib_audio_frame_v2_t NDI_audio_frame_;


};


#endif //PD_NDI_NDIRECEIVER_HPP
