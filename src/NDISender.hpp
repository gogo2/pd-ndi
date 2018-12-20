//
// Created by Bartek on 24.11.2018.
//

#ifndef PROJECT_H_NDISENDER_H
#define PROJECT_H_NDISENDER_H

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

    void *p_data() noexcept;

    void resize_screen(int screen_width, int screen_height) noexcept;

    void set_framerate(int max_fps) noexcept;

private:

    NDIlib_send_instance_t pNDI_send_;
    NDIlib_video_frame_v2_t NDI_video_frame_;

};


#endif //PROJECT_H_NDISENDER_H
