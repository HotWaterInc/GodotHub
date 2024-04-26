cmake_minimum_required(VERSION 3.28)
project(GodotHub)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(GodotHub
        src/json.hpp
        src/main.cpp)
