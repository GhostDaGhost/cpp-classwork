cmake_minimum_required(VERSION 3.10)
project(Warmup2-26)

find_package(OpenCV REQUIRED)

add_executable(Warmup2-26 ShapeFunStart.cpp)
target_link_libraries(Warmup2-26 ${OpenCV_LIBS})

include_directories(${OpenCV_INCLUDE_DIRS})