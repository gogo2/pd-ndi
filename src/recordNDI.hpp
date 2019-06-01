//
// file recordNDI.cpp
// Created by Bartosz Sobol
//


#ifndef PD_NDI_RECORDNDI_HPP
#define PD_NDI_RECORDNDI_HPP

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

#include <plugins/record.h>
#include "NDI_base/NDISender.hpp"

#pragma GCC diagnostic pop

class GEM_EXPORT recordNDI : public gem::plugins::record {
public:

    recordNDI();

    std::vector<std::string> getCodecs() override;

    const std::string getCodecDescription(const std::string &codecname) override;

    bool setCodec(const std::string &name) override;

    bool enumProperties(gem::Properties &props) override;

    bool dialog() override;

    bool start(const std::string &filename, gem::Properties &props) override;

    bool write(imageStruct *aStruct) override;

    void stop() override;

private:

    NDISender ndi_sender_;

};


#endif //PD_NDI_RECORDNDI_HPP
