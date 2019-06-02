//
// file NDISender.hpp
// Created by Bartosz Sobol
//

#ifndef PD_NDI_NDISENDER_HPP
#define PD_NDI_NDISENDER_HPP

#include <cstddef>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <NDI/Processing.NDI.Lib.h>

#pragma GCC diagnostic pop

class NDISender final {

public:

    NDISender(int screen_width, int screen_height, int max_fps = 30);

    NDISender() = delete;

    NDISender(const NDISender &) = delete;

    NDISender(const NDISender &&) = delete;

    NDISender &operator=(const NDISender &) = delete;

    NDISender &operator=(const NDISender &&) = delete;

    ~NDISender();

    void send_frame();

    uint8_t *p_video_frame_data() noexcept;

    void resize_screen(int screen_width, int screen_height) noexcept;

    void set_framerate(int max_fps) noexcept;

    int width() const noexcept;

    int height() const noexcept;

private:

    NDIlib_send_instance_t pNDI_send_;
    NDIlib_video_frame_v2_t NDI_video_frame_;

};


#endif //PD_NDI_NDISENDER_HPP
