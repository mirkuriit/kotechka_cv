cmake_minimum_required(VERSION 3.12)
project(MyProject)

set(OpenCV_DIR "../../build")
find_package(OpenCV REQUIRED)

add_executable(program main.cpp)
target_link_libraries(program ${OpenCV_LIBS})