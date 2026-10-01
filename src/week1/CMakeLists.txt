cmake_minimum_required(VERSION 3.10)
project(day01_Demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Opencv REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 工具库
add_library(image_utils STATIC src/image_utils.cpp)
target_link_libraries(image_utils PRIVATE ${OpenCV_LIBS})

# Day 01
add_executable(day01_image_basics src/day01_image_basics.cpp)
target_link_libraries(day01_image_basics PRIVATE image_utils ${OpenCV_LIBS})