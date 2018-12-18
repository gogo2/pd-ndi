project(pd_ndi_main)

set(SRC_FILES
        NDISender.cpp
        NDISenderC.cpp
        pd-ndi.c
        )

add_library(pd-ndi SHARED ${SRC_FILES})

target_link_libraries(pd-ndi PRIVATE Processing.NDI.Lib.x64)





