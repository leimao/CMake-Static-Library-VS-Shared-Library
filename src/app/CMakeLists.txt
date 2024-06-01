cmake_minimum_required(VERSION 3.5.0)

project(App VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create an executable that links to a shared library that links to another shared library.
add_executable(app_to_rectangle_shared_to_shape_shared main.cpp)
target_include_directories(app_to_rectangle_shared_to_shape_shared PRIVATE ${CMAKE_SOURCE_DIR}/src/rectangle)
target_link_libraries(app_to_rectangle_shared_to_shape_shared PRIVATE rectangle_shared_to_shape_shared)

# Create an executable that links to a static library that links to another shared library.
add_executable(app_to_rectangle_static_to_shape_shared main.cpp)
target_include_directories(app_to_rectangle_static_to_shape_shared PRIVATE ${CMAKE_SOURCE_DIR}/src/rectangle)
target_link_libraries(app_to_rectangle_static_to_shape_shared PRIVATE rectangle_static_to_shape_shared)

# Create an executable that links to a static library that links to a static library.
add_executable(app_to_rectangle_static_to_shape_static main.cpp)
target_include_directories(app_to_rectangle_static_to_shape_static PRIVATE ${CMAKE_SOURCE_DIR}/src/rectangle)
target_link_libraries(app_to_rectangle_static_to_shape_static PRIVATE rectangle_static_to_shape_static)
