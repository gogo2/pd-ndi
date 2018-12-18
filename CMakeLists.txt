cmake_minimum_required(VERSION 3.13)
project(pd_ndi VERSION 0.0.1)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -pedantic -Wall ")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/lib/)
include_directories(${PROJECT_SOURCE_DIR}/../_lib/include)
link_directories(${PROJECT_SOURCE_DIR}/../_lib/lib)

add_subdirectory(src)
add_subdirectory(test)