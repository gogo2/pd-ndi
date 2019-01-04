//
// file gem_ndisender.hpp
// Created by Bartosz Sobol
//

#ifndef PD_NDI_GEMNDISENDER_HPP
#define PD_NDI_GEMNDISENDER_HPP

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

#include <Gem/Base/GemBase.h>

#pragma GCC diagnostic pop

#include "NDISender.hpp"

namespace pdndi {

    class GEM_EXTERN ndisender : public GemBase {

    CPPEXTERN_HEADER(ndisender, GemBase)

    public:

        ndisender();

        ~ndisender() override;

    protected:

        void startRendering() override;

        void stopRendering() override;

        void render(GemState *state) override;

        void set_framerate(float max_fps);

        void resize_screen(const int screen_width, const int screen_height);


    private:

        NDISender ndi_sender_;
        uint8_t *p_pixel_transfer_data;

    };

}


#endif //PD_NDI_GEMNDISENDER_HPP
