cmake_minimum_required(VERSION 3.3)
project(Medley)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -std=c++11 -lvlc -fPIC")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCE_FILES
        src/Medley.cpp
        src/sound/Player.cpp
        src/sound/Player.h
        src/interface/MedleyUI.cpp)

set(HEADER_FILES
        src/interface/MedleyUI.h)

set(UI_FILES
        src/interface/MedleyUI.ui)

find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})

set(EXEC
        ${SOURCE_FILES}
        ${UI_HEADERS}
        ${UI_SOURCES})

add_executable(Medley ${EXEC})

target_link_libraries(Medley ${Qt5Widgets_LIBRARIES})
