//
// file gem_ndireceiver.hpp
// Created by Bartosz Sobol
//

#ifndef PD_NDI_GEM_NDIRECEIVER_HPP
#define PD_NDI_GEM_NDIRECEIVER_HPP

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

#include <Base/GemBase.h>
#include <Gem/Image.h>
#include <Gem/State.h>

#pragma GCC diagnostic pop

#include "NDIBase/NDIReceiver.hpp"


namespace pdndi {
    class GEM_EXTERN ndireceiver : public GemBase {

    CPPEXTERN_HEADER(ndireceiver, GemBase)

    public:

        ndireceiver();

        ndireceiver(t_float source);

        ~ndireceiver() = default;

    protected:

        void startRendering() override;

        void stopRendering() override;

        void render(GemState *state) override;

        void find_sources();

        void post_sources();

        void set_source(uint32_t source);


    private:
        pixBlock pix_block_;
        imageStruct gem_frame_;

        NDIReceiver ndi_receiver_;

    };

}


#endif //PD_NDI_GEM_NDIRECEIVER_HPP
