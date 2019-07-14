project(pd_ndi_main)

set(SRC_FILES
        NDIBase/NDISender.cpp
        NDIBase/NDISourceFinder.cpp
        NDIBase/NDIReceiver.cpp
        pd_ndi.cpp
        gl_ndisender.cpp
        gem_ndisender.cpp
        gem_ndireceiver.cpp
        recordNDI.cpp
        sourcefinder.cpp
        )

add_library(pd_ndi SHARED ${SRC_FILES})

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
        ${NDI_LIBRARIES}
        ${PD_LIBRARIES}
        ${GEM_LIBRARIES}
        )




