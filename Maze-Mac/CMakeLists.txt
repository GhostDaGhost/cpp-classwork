cmake_minimum_required(VERSION 3.10)
project(Maze-Mac)

find_package(OpenCV REQUIRED)

add_executable(Maze-Mac Maze.cpp)
target_link_libraries(Maze-Mac ${OpenCV_LIBS})

include_directories(${OpenCV_INCLUDE_DIRS})