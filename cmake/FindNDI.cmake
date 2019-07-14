#  NDI_FOUND - system has NDI
#  NDI_INCLUDE_DIRS - the NDI include directories
#  NDI_LIBRARIES - link these to use NDI

include(ext/LibFindMacros)
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
    message(STATUS "Looking for 64bit NDI")
    set(NDI_ARCH x64)
else()
    message(STATUS "Looking for 32bit NDI")
    set(NDI_ARCH x86)
endif()

if (WIN32)
    set(NDI_LIB_NAME Processing.NDI.Lib.${NDI_ARCH})
    set(NDI_BASE_DIR
            "C:/Program Files/NewTek"
            "C:/Program Files (x86)/NewTek")
elseif (APPLE)
    set(NDI_LIB_NAME ndi.3)
else ()

endif ()

find_path(NDI_INCLUDE_DIR
        NAMES
        Processing.NDI.Lib.h
        PATHS
        ${NDI_BASE_DIR}
        )

find_library(NDI_LIBRARY
        NAMES
        ${NDI_LIB_NAME}
        PATHS
        ${NDI_BASE_DIR}
        )

set(NDI_PROCESS_INCLUDES NDI_INCLUDE_DIR)
set(NDI_PROCESS_LIBS NDI_LIBRARY)
libfind_process(NDI)