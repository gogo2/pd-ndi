//
// file recordNDI.cpp
// Created by Bartosz Sobol
//


#ifndef PD_NDI_RECORDNDI_HPP
#define PD_NDI_RECORDNDI_HPP

#include <plugins/record.h>

class GEM_EXPORT recordNDI : public gem::plugins::record {
public:
    std::vector<std::string> getCodecs() override;

    const std::string getCodecDescription(const std::string &codecname) override;

    bool setCodec(const std::string &name) override;

    bool enumProperties(gem::Properties &props) override;

    bool dialog() override;

    bool start(const std::string &filename, gem::Properties &props) override;

    bool write(imageStruct *aStruct) override;

    void stop() override;

private:

};


#endif //PD_NDI_RECORDNDI_HPP
