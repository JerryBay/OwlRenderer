cmake_minimum_required(VERSION 3.10)

project(OwlRenderer)

set(CMAKE_BUILD_TYPE DEBUG)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)



aux_source_directory(./Test Test)

aux_source_directory(./Source/ImageProcessor ImageProcessor)

aux_source_directory(./Source/Shader Shader)

aux_source_directory(./Source/Renderer Renderer)

aux_source_directory(./Source/ModelProcessor Model)

add_executable(${PROJECT_NAME} ${Test} ${ImageProcessor} ${Shader} ${Renderer} ${Model})