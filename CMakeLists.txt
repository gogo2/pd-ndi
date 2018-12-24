cmake_minimum_required(VERSION 3.7)
project(pd_ndi VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -pedantic -Wall -static-libgcc -static-libstdc++ -m32 ")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


# PD and NDI libraries configuration BEGIN
set(PD_LIB_NAME pd)
set(PD_LIB_DIR ${PROJECT_SOURCE_DIR}/../_lib/lib)
set(PD_LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/../_lib/include)

set(NDI_LIB_NAME Processing.NDI.Lib.x86)
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