cmake_minimum_required(VERSION 3.3)
project(Medley)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/sound/Player.cpp
    src/sound/Player.h
    src/Medley.cpp)

add_executable(Medley ${SOURCE_FILES})