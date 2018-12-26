project(pd_ndi_main)

set(SRC_FILES
        NDISender.cpp
        pix_ndisender.cpp
        gem_ndisender.cpp
        )

add_library(pd_ndi SHARED ${SRC_FILES})

find_package(OpenGL)

set_target_properties(pd_ndi PROPERTIES PREFIX "")
if (WIN32)
    set_target_properties(pd_ndi PROPERTIES SUFFIX ".dll")
elseif (APPLE)
    set_target_properties(pd_ndi PROPERTIES SUFFIX ".pd_darwin")
elseif (UNIx)
    set_target_properties(pd_ndi PROPERTIES SUFFIX ".pd_linux")
endif ()

target_link_libraries(pd_ndi PRIVATE
        pd_ndi_glew
        ${OPENGL_gl_LIBRARY}
        ${NDI_LIB_NAME}
        ${PD_LIB_NAME}
        ${GEM_LIB_NAME}
        )




