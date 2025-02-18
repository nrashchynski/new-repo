cmake_minimum_required(VERSION 3.31.5 FATAL_ERROR)

project(new-repo)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(new-repo src/main.cpp)