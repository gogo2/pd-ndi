project(pd_ndi_main)

set(SRC_FILES
        NDISender.cpp
        NDISenderC.cpp
        pd-ndi.c
        )

add_library(ndisender SHARED ${SRC_FILES})

target_link_libraries(ndisender PRIVATE Processing.NDI.Lib.x64 pd)





