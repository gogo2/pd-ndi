project(pd_ndi_glew)

add_library(pd_ndi_glew STATIC glew.c)

set_target_properties(pd_ndi_glew PROPERTIES COMPILE_FLAGS "-w")

