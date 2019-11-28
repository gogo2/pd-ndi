//
// file gem_ndisender.hpp
// Created by Bartosz Sobol
//

#ifndef PD_NDI_GEMNDISENDER_HPP
#define PD_NDI_GEMNDISENDER_HPP

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

#include <Base/GemBase.h>

#pragma GCC diagnostic pop

#include "ndi_base/ndi_sender.hpp"

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

        void resize_screen(int screen_width, int screen_height);


    private:

        base::ndi_sender ndi_sender_;
        uint8_t *p_pixel_transfer_data;

    };

}


#endif //PD_NDI_GEMNDISENDER_HPP
