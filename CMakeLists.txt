cmake_minimum_required(VERSION 2.6)

set(CMAKE_C_COMPILER gcc-7)
set(CMAKE_CXX_COMPILER g++-7)

file(GLOB_RECURSE SRC_GLOB_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/library/*) 
list(APPEND SOURCE_FILES ${SRC_GLOB_LIST})

set(CXX_FLAGS
        -Wall
        -Wextra
        -Werror
        -Wconversion
        -Wno-unused-parameter
        -Wold-style-cast
        -Woverloaded-virtual
        -Wpointer-arith
        -Wshadow
        -Wwrite-strings
        -march=native
        -std=c++17
        -rdynamic)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

include_directories(src/library)

add_executable(timer timer.cc ${SOURCE_FILES})
target_link_libraries(timer pthread)
