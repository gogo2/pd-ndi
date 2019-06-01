//
// file NDISourceFinder.hpp
// Created by Bartek
//

#ifndef PD_NDI_NDISOURCEFINDER_HPP
#define PD_NDI_NDISOURCEFINDER_HPP

#include <iostream>
#include <NDI/Processing.NDI.Lib.h>

class NDISourceFinder {
public:

    NDISourceFinder();

    NDISourceFinder(const NDISourceFinder &) = delete;

    NDISourceFinder(const NDISourceFinder &&) = delete;

    NDISourceFinder &operator=(const NDISourceFinder &) = delete;

    NDISourceFinder &operator=(const NDISourceFinder &&) = delete;

    friend std::ostream& operator<<(std::ostream& ostream, const NDISourceFinder& source_finder);

    ~NDISourceFinder();
    
    bool find_sources();

    const NDIlib_source_t* p_sources();

    const uint32_t no_sources();


private:
    NDIlib_find_instance_t pNDI_find_;
    uint32_t no_sources_;
    const NDIlib_source_t* p_sources_;


};


#endif //PD_NDI_NDISOURCEFINDER_HPP
