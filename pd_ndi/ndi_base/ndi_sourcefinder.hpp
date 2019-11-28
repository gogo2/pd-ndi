//
// file ndi_sourcefinder.hpp
// Created by Bartosz Sobol
//

#ifndef PD_NDI_NDI_SOURCEFINDER_HPP
#define PD_NDI_NDI_SOURCEFINDER_HPP

#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#define PROCESSINGNDILIB_DEPRECATED

#include <Processing.NDI.Lib.h>

#pragma GCC diagnostic pop

class ndi_sourcefinder {
public:

    ndi_sourcefinder();

    ndi_sourcefinder(const ndi_sourcefinder &) = delete;

    ndi_sourcefinder(const ndi_sourcefinder &&) = delete;

    ndi_sourcefinder &operator=(const ndi_sourcefinder &) = delete;

    ndi_sourcefinder &operator=(const ndi_sourcefinder &&) = delete;

    friend std::ostream &operator<<(std::ostream &ostream, const ndi_sourcefinder &source_finder);

    ~ndi_sourcefinder();

    bool find_sources() noexcept;

    const NDIlib_source_t *p_sources() const noexcept;

    uint32_t no_sources() const noexcept;


private:
    NDIlib_find_instance_t pNDI_find_;
    uint32_t no_sources_;
    const NDIlib_source_t *p_sources_;


};


#endif //PD_NDI_NDI_SOURCEFINDER_HPP
