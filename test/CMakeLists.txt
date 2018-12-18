project(pd_ndi_test)

set(SRC_FILES
        main.cpp
        )

add_executable(pd-ndi-test ${SRC_FILES})

target_link_libraries(pd-ndi-test pd-ndi)





