#  NDI_FOUND - system has NDI
#  NDI_INCLUDE_DIRS - the NDI include directories
#  NDI_LIBRARIES - link these to use NDI

include(ext/LibFindMacros)

if ("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
    message(STATUS "Looking for 64bit NDI")
    if (WIN32 OR APPLE)
        set(NDI_ARCH x64)
    elseif (UNIX)
        set(NDI_ARCH x86_64-linux-gnu)
    endif ()
else ()
    message(STATUS "Looking for 32bit NDI")
    if (WIN32)
        set(NDI_ARCH x86)
    elseif (UNIX AND NOT APPLE)
        set(NDI_ARCH i686-linux-gnu)
    endif ()
endif ()

if (WIN32)
    set(NDI_LIB_NAME Processing.NDI.Lib.${NDI_ARCH})
    set(NDI_BASE_DIR $ENV{NDI_SDK_DIR})
elseif (APPLE)
    set(NDI_LIB_NAME ndi.4)
    set(NDI_BASE_DIR ${NDI_INSTALL_DIR})
elseif (UNIX)
    set(NDI_LIB_NAME ndi)
    set(NDI_BASE_DIR ${NDI_INSTALL_DIR})
endif ()
message(STATUS  ${NDI_BASE_DIR}/lib/${NDI_ARCH})
find_path(NDI_INCLUDE_DIR
        NAMES
        Processing.NDI.Lib.h
        PATHS
        ${NDI_BASE_DIR}/include
        )

find_library(NDI_LIBRARY
        NAMES
        ${NDI_LIB_NAME}
        PATHS
        ${NDI_BASE_DIR}/lib/${NDI_ARCH}
        )

set(NDI_PROCESS_INCLUDES NDI_INCLUDE_DIR)
set(NDI_PROCESS_LIBS NDI_LIBRARY)
libfind_process(NDI)

message(STATUS "NDI_LIBRARIES: ${NDI_LIBRARIES}")
message(STATUS "NDI_INCLUDE_DIRS: ${NDI_INCLUDE_DIRS}")
