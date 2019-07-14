//
// file NDISourceFinder.hpp
// Created by Bartosz Sobol
//

#ifndef PD_NDI_NDISOURCEFINDER_HPP
#define PD_NDI_NDISOURCEFINDER_HPP

#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <Processing.NDI.Lib.h>

#pragma GCC diagnostic pop

class NDISourceFinder {
public:

    NDISourceFinder();

    NDISourceFinder(const NDISourceFinder &) = delete;

    NDISourceFinder(const NDISourceFinder &&) = delete;

    NDISourceFinder &operator=(const NDISourceFinder &) = delete;

    NDISourceFinder &operator=(const NDISourceFinder &&) = delete;

    friend std::ostream &operator<<(std::ostream &ostream, const NDISourceFinder &source_finder);

    ~NDISourceFinder();

    bool find_sources();

    const NDIlib_source_t *p_sources() const noexcept;

    uint32_t no_sources() const noexcept;


private:
    NDIlib_find_instance_t pNDI_find_;
    uint32_t no_sources_;
    const NDIlib_source_t *p_sources_;


};


#endif //PD_NDI_NDISOURCEFINDER_HPP
