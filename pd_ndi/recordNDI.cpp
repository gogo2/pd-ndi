//
// file recordNDI.cpp
// Created by Bartosz Sobol
//

#include "recordNDI.hpp"

namespace pdndi {

    recordNDI::recordNDI() : ndi_sender_(500, 500) {}


    std::vector<std::string> recordNDI::getCodecs() {
        return std::vector<std::string>{"Newtek NDI"};
    }

    const std::string recordNDI::getCodecDescription(const std::string &codecname) {
        return std::string{"https://www.newtek.com/ndi/ \n https://en.wikipedia.org/wiki/Network_Device_Interface"};
    }

    bool recordNDI::setCodec(const std::string &name) {
        return true;
    }

    bool recordNDI::enumProperties(gem::Properties &props) {
        return false;
    }

    bool recordNDI::dialog() {
        return false;
    }

    bool recordNDI::start(const std::string &filename, gem::Properties &props) {
        return true;
    }

    bool recordNDI::write(imageStruct *aStruct) {
        return true;
    }

    void recordNDI::stop() {

    }

}

