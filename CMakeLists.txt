cmake_minimum_required(VERSION 3.19)

project(Renderer)

add_compile_options(-O2)

file(GLOB_RECURSE SOURCE "src/*.c")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})
