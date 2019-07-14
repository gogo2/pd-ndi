cmake_minimum_required(VERSION 3.0)
project(pd_ndi VERSION 0.3.4)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#set(CMAKE_VERBOSE_MAKEFILE on)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if (WIN32)
    set(PD_INSTALL_DIR_DEFAULT "C:/bin/Pd-0.49-0")
    set(GEM_EXTERN_DIR_DEFAULT "C:/Users/$ENV{USERNAME}/Documents/Pd/externals/Gem")
elseif (APPLE)
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
    set(PD_INSTALL_DIR_DEFAULT "/Applications/Pd-0.49-1.app/Contents/Resources/")
    set(GEM_EXTERN_DIR_DEFAULT "/Users/$ENV{USER}/Documents/Pd/externals/Gem/")
else ()
endif ()

set(PD_INSTALL_DIR ${PD_INSTALL_DIR_DEFAULT} CACHE PATH "Installation direcotry of pd")
set(GEM_EXTERN_DIR ${GEM_EXTERN_DIR_DEFAULT} CACHE PATH "Directory containing pd Gem")

add_subdirectory(src)
add_subdirectory(lib/glew)