//
// file sourcefinder.h
// Created by Bartosz Sobol
//

#include <sstream>
#include "m_pd.h"
#include "NDIBase/NDISourceFinder.hpp"

static t_class *ndisourcefinder_class;

struct t_ndisourcefinder {
    t_object x_obj;
    NDISourceFinder *ndi_sourcefinder;
};

void *ndisourcefinder_new();

void ndisourcefinder_delete(t_ndisourcefinder *ndisourcefinder);

void ndisourcefinder_bang(t_ndisourcefinder *ndisourcefinder);

void setup_ndisourcefinder();
