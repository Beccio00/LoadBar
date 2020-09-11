cmake_minimum_required(VERSION 3.17)
project(LabProject)

add_subdirectory(test)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_PREFIX_PATH "/usr/lib/qt5/bin")

set (CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES main.cpp Subject.h Observer.h  File.h LoadFiles.cpp LoadFiles.h Window.cpp Window.h ConcreteObserver.h)
add_executable(LabProject main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(core Qt5::Widgets)
target_link_libraries(LabProject core)