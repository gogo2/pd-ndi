#  GEM_FOUND - system has GEM
#  GEM_INCLUDE_DIRS - the GEM include directories
#  GEM_LIBRARIES - link these to use GEM

include(ext/LibFindMacros)

find_package(PD)

if (WIN32)
    set(GEM_BASE_DIR ${GEM_EXTERN_DIR})
    set(GEM_LIB_NAME Gem)
elseif (APPLE)
    set(GEM_BASE_DIR ${GEM_EXTERN_DIR})
    set(GEM_LIB_NAME Gem.pd_darwin)
    list(APPEND CMAKE_FIND_LIBRARY_SUFFIXES ".pd_darwin")
endif ()

find_path(GEM_INCLUDE_DIR
        NAMES
        GemBase.h
        PATHS
        ${GEM_BASE_DIR}/include/Gem/Base
        )

find_library(GEM_LIBRARY
        NAMES
        ${GEM_LIB_NAME}
        PATHS
        ${GEM_BASE_DIR}
        )

get_filename_component(GEM_INCLUDE_DIR ${GEM_INCLUDE_DIR} DIRECTORY)

set(GEM_PROCESS_INCLUDES GEM_INCLUDE_DIR)
set(GEM_PROCESS_LIBS GEM_LIBRARY)
libfind_process(GEM)

message(STATUS "GEM_LIBRARIES: ${GEM_LIBRARIES}")
message(STATUS "GEM_INCLUDE_DIRS: ${GEM_INCLUDE_DIRS}")