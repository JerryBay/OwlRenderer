cmake_minimum_required(VERSION 3.10)

project(OwlRenderer)

set(CMAKE_BUILD_TYPE DEBUG)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)



aux_source_directory(./Test Test)

aux_source_directory(./Source/Math Math)

aux_source_directory(./Source/ModelProject Model)

add_executable(${PROJECT_NAME} ${Test} ${Math} ${Model})