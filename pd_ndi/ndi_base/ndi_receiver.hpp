//
// file ndi_receiver.hpp
// Created by Bartosz Sobol
//

#ifndef PD_NDI_NDI_RECEIVER_HPP
#define PD_NDI_NDI_RECEIVER_HPP

#include <cstddef>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#define PROCESSINGNDILIB_DEPRECATED

#include <Processing.NDI.Lib.h>

#pragma GCC diagnostic pop

#include "ndi_sourcefinder.hpp"

class ndi_receiver final {
public:

    ndi_receiver();

    ndi_receiver(const ndi_receiver &) = delete;

    ndi_receiver(const ndi_receiver &&) = delete;

    ndi_receiver &operator=(const ndi_receiver &) = delete;

    ndi_receiver &operator=(const ndi_receiver &&) = delete;

    ~ndi_receiver();

    bool find_sources() noexcept;

    void connect(uint32_t source) noexcept;

    NDIlib_frame_type_e receive_frame() noexcept;

    const NDIlib_video_frame_v2_t &NDI_video_frame() noexcept;

    const NDIlib_audio_frame_v2_t &NDI_audio_frame() noexcept;

    ndi_sourcefinder source_finder;

private:

    NDIlib_recv_instance_t pNDI_recv_;
    NDIlib_video_frame_v2_t NDI_video_frame_;
    NDIlib_audio_frame_v2_t NDI_audio_frame_;


};


#endif //PD_NDI_NDI_RECEIVER_HPP
