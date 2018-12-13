project(pd_ndi_main)

set(SRC_FILES
        NDISender.cpp
        )

add_library(pd-ndi ${SRC_FILES})

target_link_libraries(pd-ndi PRIVATE Processing.NDI.Lib.x64)





