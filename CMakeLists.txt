cmake_minimum_required(VERSION 3.2)
project(lttngUSTProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("src/")
set(SOURCE_FILES
    src/mainToBeTraced.cpp
)

add_executable(mainToBeTraced ${SOURCE_FILES})
target_link_libraries(mainToBeTraced lttng-ust dl)