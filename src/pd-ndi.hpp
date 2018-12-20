//
// file ss.hpp
// Created by Bartek
//

#ifndef PD_NDI_SS_HPP
#define PD_NDI_SS_HPP


#include "NDISender.hpp"

struct _pd_ndi;

class PdGlNdiConnector {
public:
    explicit PdGlNdiConnector(_pd_ndi *pd_ndi);

    PdGlNdiConnector() = delete;

    PdGlNdiConnector(const PdGlNdiConnector &) = delete;

    PdGlNdiConnector(const PdGlNdiConnector &&) = delete;

    PdGlNdiConnector &operator=(const PdGlNdiConnector &) = delete;

    PdGlNdiConnector &operator=(const PdGlNdiConnector &&) = delete;

    ~PdGlNdiConnector() = default;

    void bang();

private:
    _pd_ndi *const pd_ndi_;
    NDISender ndi_sender_;

};

typedef struct _pd_ndi {
    t_object x_obj;

    PdGlNdiConnector *ndi_connector;

} t_pd_ndi;


#endif //PD_NDI_SS_HPP
