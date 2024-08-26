cmake_minimum_required(VERSION 3.10)

project(nearest_points)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(headders)
include_directories(source)

set(SOURCES ./main.cpp 
			./source/graph.cpp 
			./source/point.cpp)

set(HEADERS ./headders/graph.h 
			./headders/point.h)

add_executable(nearest_points  ${SOURCES})

set(CMAKE_BUILD_TYPE Debug)
