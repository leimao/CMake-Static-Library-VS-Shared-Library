cmake_minimum_required(VERSION 3.5.0)

project(Rectangle VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a shared library that links to another shared library.
add_library(rectangle_shared_to_shape_shared SHARED rectangle.cpp)
target_include_directories(rectangle_shared_to_shape_shared PUBLIC ${CMAKE_SOURCE_DIR}/src/shape)
target_link_libraries(rectangle_shared_to_shape_shared PUBLIC shape_shared)

# Create a shared library that links to a static library.
# This does not work.
# add_library(rectangle_shared_to_shape_static SHARED rectangle.cpp)
# target_include_directories(rectangle_shared_to_shape_static PUBLIC ${CMAKE_SOURCE_DIR}/src/shape)
# target_link_libraries(rectangle_shared_to_shape_static PUBLIC shape_static)

# Create a static library that links to another shared library.
add_library(rectangle_static_to_shape_shared STATIC rectangle.cpp)
target_include_directories(rectangle_static_to_shape_shared PUBLIC ${CMAKE_SOURCE_DIR}/src/shape)
target_link_libraries(rectangle_static_to_shape_shared PUBLIC shape_shared)

# Create a static library that links to a static library.
add_library(rectangle_static_to_shape_static STATIC rectangle.cpp)
target_include_directories(rectangle_static_to_shape_static PUBLIC ${CMAKE_SOURCE_DIR}/src/shape)
target_link_libraries(rectangle_static_to_shape_static PUBLIC shape_static)
