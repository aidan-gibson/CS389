cmake_minimum_required(VERSION 3.23)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_ARCHITECTURES "arm64")
add_executable(untitled1 main.cpp)
add_executable(float float.cpp)
add_executable(int64 int64.cpp)
add_executable(int8 int8.cpp)