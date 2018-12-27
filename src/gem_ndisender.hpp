//
// file gem_ndisender.hpp
// Created by Bartosz Sobol
//

#ifndef PD_NDI_GEMNDISENDER_HPP
#define PD_NDI_GEMNDISENDER_HPP

#include <Gem/Base/GemBase.h>
#include "NDISender.hpp"

namespace pdndi {

    class GEM_EXTERN ndisender : public GemBase {

    CPPEXTERN_HEADER(ndisender, GemBase)

    public:

        ndisender();

        ~ndisender() override = default;

    protected:

        void startRendering() override;

        void stopRendering() override;

        void render(GemState *state) override;

        void set_framerate(float max_fps);


    private:

        NDISender ndi_sender_;

    };

}


#endif //PD_NDI_GEMNDISENDER_HPP
