//
// Created by Bartek on 26.12.2018.
//

#ifndef PD_NDI_GEMNDISENDER_H
#define PD_NDI_GEMNDISENDER_H

#include <Gem/Base/GemBase.h>
#include "NDISender.hpp"

class GEM_EXTERN GemNDISender : public GemBase {
CPPEXTERN_HEADER(GemNDISender, GemBase)

public:

    GemNDISender();

    ~GemNDISender() override = default;

protected:
    void render(GemState *state) override;


private:

    NDISender ndi_sender_;

};


#endif //PD_NDI_GEMNDISENDER_H
