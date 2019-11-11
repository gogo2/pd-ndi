cmake_minimum_required(VERSION 3.0)
project(pd_ndi VERSION 0.5.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_VERBOSE_MAKEFILE on)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if (WIN32)
    set(PD_INSTALL_DIR_DEFAULT "C:/bin/Pd-0.50-2")
    set(GEM_EXTERN_DIR_DEFAULT "C:/Users/$ENV{USERNAME}/Documents/Pd/externals/Gem")
elseif (APPLE)
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
    set(PD_INSTALL_DIR_DEFAULT "/Applications/Pd-0.50-2.app")
    set(GEM_EXTERN_DIR_DEFAULT "/Users/$ENV{USER}/Documents/Pd/externals/Gem")
elseif (UNIX)
    set(PD_INSTALL_DIR_DEFAULT "/usr/include/pd")
    set(GEM_EXTERN_DIR_DEFAULT "/usr/include/Gem")
    set(NDI_INSTALL_DIR "/home/$ENV{USER}/NDI SDK for Linux" CACHE PATH "Directory containing NDI SDK")
endif ()

set(PD_INSTALL_DIR ${PD_INSTALL_DIR_DEFAULT} CACHE PATH "Installation direcotry of pd")
set(GEM_EXTERN_DIR ${GEM_EXTERN_DIR_DEFAULT} CACHE PATH "Directory containing Gem")

if(POLICY CMP0072)
	cmake_policy(SET CMP0072 NEW)
endif()

add_subdirectory(lib/GL)
add_subdirectory(src)
