cmake_minimum_required(VERSION 3.31)
project(C__)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(LeetCode)
add_subdirectory(lab)
add_subdirectory(homework)
add_subdirectory(dotOJ)

add_executable(C__ main.cpp)

