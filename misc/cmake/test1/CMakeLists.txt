cmake_minimum_required(VERSION 3.10)

project(MyProject2)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add executable
add_executable(my_app main.cpp add.cpp)