cmake_minimum_required(VERSION 2.8)

project(OwlRenderer)

set(CMAKE_BUILD_TYPE DEBUG)

file(GLOB SOURCES *.h *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})