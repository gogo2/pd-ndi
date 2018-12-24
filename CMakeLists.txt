cmake_minimum_required(VERSION 3.0)
project(pd_ndi VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -pedantic -Wall -static-libstdc++ ")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

if (APPLE)
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
    set(PD_LIB_NAME)
    set(NDI_LIB_NAME ndi.3)
else ()
    set(PD_LIB_NAME pd)
    #        change if building for x86
    set(NDI_LIB_NAME Processing.NDI.Lib.x64)
endif ()

# PD and NDI libraries configuration BEGIN
set(PD_LIB_DIR ${PROJECT_SOURCE_DIR}/../_lib/lib)
set(PD_LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/../_lib/include)
set(NDI_LIB_DIR ${PROJECT_SOURCE_DIR}/../_lib/lib)
set(NDI_LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/../_lib/include)
# END PD and NDI libraries configuration


include_directories(${PD_LIB_INCLUDE_DIR})
link_directories(${PD_LIB_DIR})
include_directories(${NDI_LIB_INCLUDE_DIR})
link_directories(${NDI_LIB_DIR})
include_directories(${PROJECT_SOURCE_DIR}/lib/)
add_subdirectory(src)
add_subdirectory(lib/glew)