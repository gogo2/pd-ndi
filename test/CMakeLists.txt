project(pd_ndi_test C)

set(SRC_FILES
        main.c
        )

add_executable(pd-ndi-test ${SRC_FILES})

target_link_libraries(pd-ndi-test pd-ndi)





