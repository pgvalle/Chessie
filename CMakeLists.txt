cmake_minimum_required(VERSION 3.22)

project(Chessie LANGUAGES C CXX)

file(GLOB COMMON source/**.cpp)
include_directories(source)

add_subdirectory(source/client)
add_subdirectory(source/server)