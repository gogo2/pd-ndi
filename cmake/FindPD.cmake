#  PD_FOUND - system has PD
#  PD_INCLUDE_DIRS - the PD include directories
#  PD_LIBRARIES - link these to use PD

include(ext/LibFindMacros)

if (WIN32)
    set(PD_BASE_DIR "C:/bin/Pd-0.49-0")
elseif (APPLE)
else ()
endif ()

find_path(PD_INCLUDE_DIR
        NAMES
        m_pd.h
        PATHS
        ${PD_BASE_DIR}/src
        )

find_library(PD_LIBRARY
        NAMES
        pd
        PATHS
        ${PD_BASE_DIR}/bin
        )


set(PD_PROCESS_INCLUDES PD_INCLUDE_DIR)
set(PD_PROCESS_LIBS PD_LIBRARY)
libfind_process(PD)

message(STATUS "PD_LIBRARIES: ${PD_LIBRARIES}")
message(STATUS "PD_INCLUDE_DIRS: ${PD_INCLUDE_DIRS}")
