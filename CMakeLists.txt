cmake_minimum_required(VERSION 3.3)
project(Medley)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lvlc")

set(SOURCE_FILES
    src/sound/Player.cpp
    src/sound/Player.h
    src/Medley.cpp)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_executable(Medley ${SOURCE_FILES})

target_link_libraries(Medley Qt5::Widgets)