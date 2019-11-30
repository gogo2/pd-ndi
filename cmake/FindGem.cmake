#  GEM_FOUND - system has GEM
#  GEM_INCLUDE_DIRS - the GEM include directories
#  GEM_LIBRARIES - link these to use GEM

include(ext/LibFindMacros)

find_package(PD)

if (NOT GEM_EXTERN_DIR)
    if (WIN32)
        set(GEM_EXTERN_DIR "$ENV{USERPROFILE}/Documents/Pd/externals/Gem")
    elseif (APPLE)
        set(GEM_EXTERN_DIR "/Users/$ENV{USER}/Documents/Pd/externals/Gem")
    elseif (UNIX)
        set(GEM_EXTERN_DIR "/usr/include/Gem")
    endif ()
endif ()

message(STATUS ff${GEM_EXTERN_DIR})

if (WIN32 OR APPLE)
    set(GEM_BASE_DIR ${GEM_EXTERN_DIR})
    set(GEM_INCLUDE_BASE_DIR "${GEM_BASE_DIR}/include/Gem")
elseif (UNIX)
    set(GEM_INCLUDE_BASE_DIR ${GEM_EXTERN_DIR})
endif ()

find_path(GEM_INCLUDE_DIR
        NAMES
        GemBase.h
        PATHS
        "${GEM_INCLUDE_BASE_DIR}/Base"
        )

if (WIN32)
    find_library(GEM_LIBRARY
            NAMES
            Gem
            PATHS
            ${GEM_BASE_DIR}
            )
endif ()

get_filename_component(GEM_INCLUDE_DIR ${GEM_INCLUDE_DIR} DIRECTORY)

set(GEM_PROCESS_INCLUDES GEM_INCLUDE_DIR)
set(GEM_PROCESS_LIBS GEM_LIBRARY)
libfind_process(GEM)

message(STATUS "GEM_LIBRARIES: ${GEM_LIBRARIES}")
message(STATUS "GEM_INCLUDE_DIRS: ${GEM_INCLUDE_DIRS}")
