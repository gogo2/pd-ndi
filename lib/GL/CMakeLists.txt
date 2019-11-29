project(pd_gem_glew)

add_library(pd_gem_glew STATIC glew.c)

set_target_properties(pd_gem_glew PROPERTIES COMPILE_FLAGS "-w")

