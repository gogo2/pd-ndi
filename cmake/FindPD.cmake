#  PD_FOUND - system has PD
#  PD_INCLUDE_DIRS - the PD include directories
#  PD_LIBRARIES - link these to use PD

include(ext/LibFindMacros)

if (NOT PD_INSTALL_DIR)
    message(FATAL_ERROR "Please set PD_INSTALL_DIR variable (installation directory of Pure Data)")
endif ()

if (WIN32)
    set(PD_BASE_DIR ${PD_INSTALL_DIR})
elseif (APPLE)
    set(PD_BASE_DIR ${PD_INSTALL_DIR}/Contents/Resources)
elseif (UNIX)
    set(PD_BASE_DIR ${PD_INSTALL_DIR})
endif ()

find_path(PD_INCLUDE_DIR
        NAMES
        m_pd.h
        PATHS
        ${PD_BASE_DIR}/src
        )

if (WIN32)
    find_library(PD_LIBRARY
            NAMES
            pd
            PATHS
            ${PD_BASE_DIR}/bin
            )
endif ()

set(PD_PROCESS_INCLUDES PD_INCLUDE_DIR)
set(PD_PROCESS_LIBS PD_LIBRARY)
libfind_process(PD)

message(STATUS "PD_LIBRARIES: ${PD_LIBRARIES}")
message(STATUS "PD_INCLUDE_DIRS: ${PD_INCLUDE_DIRS}")
