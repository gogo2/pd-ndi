project(pd_ndi_main)

set(SRC_FILES
        NDISender.cpp
        #        NDISenderC.cpp
        pd-ndi.cpp
        )

add_library(pd_ndi SHARED ${SRC_FILES})

find_package(OpenGL)

set_target_properties(pd_ndi PROPERTIES PREFIX "")
target_link_libraries(pd_ndi PRIVATE
        Processing.NDI.Lib.x86
        project_h_glad
        ${OPENGL_gl_LIBRARY}
        pd

        )




