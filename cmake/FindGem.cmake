#  GEM_FOUND - system has GEM
#  GEM_INCLUDE_DIRS - the GEM include directories
#  GEM_LIBRARIES - link these to use GEM

include(ext/LibFindMacros)

find_package(PD)

find_path(GEM_INCLUDE_DIR
        NAMES
        GemBase.h
        PATHS
        ${GEM_BASE_DIR}
        )


find_library(GEM_LIBRARY
        NAMES
        ${GEM_LIB_NAME}
        PATHS
        ${GEM_BASE_DIR}
        )

set(GEM_PROCESS_INCLUDES GEM_INCLUDE_DIR)
set(GEM_PROCESS_LIBS GEM_LIBRARY)
libfind_process(GEM)

message(STATUS "GEM_LIBRARIES: ${GEM_LIBRARIES}")
message(STATUS "GEM_INCLUDE_DIRS: ${GEM_INCLUDE_DIRS}")