cmake_minimum_required(VERSION 3.3)
project(Medley)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lvlc")

set(SOURCE_FILES src/Medley.cpp src/sound/Player.cpp)
add_executable(Medley ${SOURCE_FILES})