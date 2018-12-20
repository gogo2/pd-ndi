//
// file ss.hpp
// Created by Bartek
//

#ifndef PD_NDI_HPP
#define PD_NDI_HPP


#include "NDISender.hpp"

struct _pd_ndi;
typedef _pd_ndi t_pd_ndi;

class PdGlNdiConnector {
public:
    explicit PdGlNdiConnector(t_pd_ndi *pd_ndi);

    PdGlNdiConnector() = delete;

    PdGlNdiConnector(const PdGlNdiConnector &) = delete;

    PdGlNdiConnector(const PdGlNdiConnector &&) = delete;

    PdGlNdiConnector &operator=(const PdGlNdiConnector &) = delete;

    PdGlNdiConnector &operator=(const PdGlNdiConnector &&) = delete;

    ~PdGlNdiConnector() = default;

    void send_framebuffer(int tex);

    void bang();

    void resize_screen(int screen_width, int screen_height) noexcept;

    void set_framerate(int max_fps) noexcept;

private:
    t_pd_ndi *const pd_ndi_;
    NDISender ndi_sender_;

};

struct _pd_ndi {
    t_object x_obj;

    PdGlNdiConnector *ndi_connector;

};


#endif //PD_NDI_HPP
