cmake_minimum_required(VERSION 3.5.0)

project(Shape VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a shared library
add_library(shape_shared SHARED shape.cpp)
# Create a static library
add_library(shape_static STATIC shape.cpp)
