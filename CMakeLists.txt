cmake_minimum_required(VERSION 3.0)
project(pd_ndi VERSION 0.3.4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -pedantic -Wall -static-libstdc++ ")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#set(CMAKE_VERBOSE_MAKEFILE on)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if (APPLE)
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif ()


set(PD_INSTALL_DIR "C:/bin/Pd-0.49-0" CACHE PATH "Installation direcotry of pd")
set(GEM_EXTERN_DIR "C:/Users/$ENV{USERNAME}/Documents/Pd/externals/Gem" CACHE PATH "Directory containing pd Gem")

find_package(OpenGL)
find_package(NDI REQUIRED)
find_package(PD REQUIRED)
find_package(GEM REQUIRED)

include_directories(${NDI_INCLUDE_DIRS})
include_directories(${PD_INCLUDE_DIRS})
include_directories(${GEM_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/lib/)
add_subdirectory(src)
add_subdirectory(lib/glew)