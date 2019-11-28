//
// file ndi_sender.hpp
// Created by Bartosz Sobol
//

#ifndef PD_NDI_NDI_SENDER_HPP
#define PD_NDI_NDI_SENDER_HPP

#include <cstddef>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#define PROCESSINGNDILIB_DEPRECATED
#include <Processing.NDI.Lib.h>

#pragma GCC diagnostic pop

class ndi_sender final {

public:

    ndi_sender(int screen_width, int screen_height, int max_fps = 30);

    ndi_sender() = delete;

    ndi_sender(const ndi_sender &) = delete;

    ndi_sender(const ndi_sender &&) = delete;

    ndi_sender &operator=(const ndi_sender &) = delete;

    ndi_sender &operator=(const ndi_sender &&) = delete;

    ~ndi_sender();

    void send_frame() noexcept ;

    uint8_t *p_video_frame_data() noexcept;

    void resize_screen(int screen_width, int screen_height) noexcept;

    void set_framerate(int max_fps) noexcept;

    int width() const noexcept;

    int height() const noexcept;

private:

    NDIlib_send_instance_t pNDI_send_;
    NDIlib_video_frame_v2_t NDI_video_frame_;

};


#endif //PD_NDI_NDI_SENDER_HPP
