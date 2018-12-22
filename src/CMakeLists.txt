project(pd_ndi_main)

set(SRC_FILES
        NDISender.cpp
        pd-ndi.cpp
        )

add_library(pd_ndi SHARED ${SRC_FILES})

find_package(OpenGL)

set_target_properties(pd_ndi PROPERTIES PREFIX "")
target_link_libraries(pd_ndi PRIVATE
        pd_ndi_glew
        ${OPENGL_gl_LIBRARY}
        ${NDI_LIB_NAME}
        ${PD_LIB_NAME}
        )




