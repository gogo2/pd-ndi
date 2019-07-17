project(pd_ndi_main)

set(SRC_FILES
        NDIBase/NDISender.cpp
        NDIBase/NDIReceiver.cpp
        NDIBase/NDISourceFinder.cpp
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

find_package(OpenGL)
find_package(NDI REQUIRED)
find_package(PD REQUIRED)
find_package(Gem REQUIRED)

target_compile_options(pd_ndi PRIVATE $<$<CXX_COMPILER_ID:GNU>:-O3 -pedantic -Wall -static-libstdc++>)

set_target_properties(pd_ndi PROPERTIES CXX_STANDARD 11)

target_include_directories(pd_ndi PRIVATE
        ${PROJECT_SOURCE_DIR}/../lib/
        ${NDI_INCLUDE_DIRS}
        ${PD_INCLUDE_DIRS}
        ${GEM_INCLUDE_DIRS}
        )

target_link_libraries(pd_ndi PRIVATE
        pd_ndi_glew
        ${OPENGL_gl_LIBRARY}
        ${NDI_LIBRARIES}
        ${PD_LIBRARIES}
        ${GEM_LIBRARIES}
        )




