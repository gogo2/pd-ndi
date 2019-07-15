project(pd_ndi_ndi_base)

set(SRC_FILES
        NDISender.cpp
        NDISourceFinder.cpp
        NDIReceiver.cpp
        )

add_library(ndi_base STATIC ${SRC_FILES})

find_package(NDI REQUIRED)

target_compile_options(ndi_base PRIVATE $<$<CXX_COMPILER_ID:GNU>:-O3 -pedantic -Wall -static-libstdc++>)

set_target_properties(ndi_base PROPERTIES CXX_STANDARD 11)

target_include_directories(ndi_base PUBLIC
        ${NDI_INCLUDE_DIRS}
        )

target_link_libraries(ndi_base PRIVATE
        ${NDI_LIBRARIES}
        )




