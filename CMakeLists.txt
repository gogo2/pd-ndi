cmake_minimum_required(VERSION 3.0)
project(pd_ndi VERSION 0.3.4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -pedantic -Wall -static-libstdc++ ")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#set(CMAKE_VERBOSE_MAKEFILE on)

if (APPLE)
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
    set(PD_LIB_NAME)
    set(GEM_LIB_NAME)
    set(NDI_LIB_NAME ndi.3)
else ()
    set(PD_LIB_NAME pd)
    set(GEM_LIB_NAME Gem)
    #        change if building for x86
    set(NDI_LIB_NAME Processing.NDI.Lib.x64)
endif ()


#find_library(PD_LIB pd HINTS)


# PD and NDI libraries configuration BEGIN
set(PD_LIB_DIR ${PROJECT_SOURCE_DIR}/../_lib/lib)
set(PD_LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/../_lib/include)
set(GEM_LIB_DIR ${PROJECT_SOURCE_DIR}/../_lib/lib)
set(GEM_LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/../_lib/include/Gem)
set(NDI_LIB_DIR ${PROJECT_SOURCE_DIR}/../_lib/lib)
set(NDI_LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/../_lib/include)
# END PD and NDI libraries configuration


include_directories(${PD_LIB_INCLUDE_DIR})
link_directories(${PD_LIB_DIR})
include_directories(${GEM_LIB_INCLUDE_DIR})
link_directories(${GEM_LIB_DIR})
include_directories(${NDI_LIB_INCLUDE_DIR})
link_directories(${NDI_LIB_DIR})
include_directories(${PROJECT_SOURCE_DIR}/lib/)
add_subdirectory(src)
add_subdirectory(lib/glew)