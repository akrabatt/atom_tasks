cmake_minimum_required(VERSION 3.10)

project(GeoPoints)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(headders)

set(SOURCES ./main.cpp ./source/GeoPointProcessor.cpp)

set(HEADERS ./headders/GeoPointProcessor.h)

add_executable(GeoPoints  ${SOURCES})

set(CMAKE_BUILD_TYPE Debug)
