cmake_minimum_required(VERSION 3.31.5 FATAL_ERROR)

project(new-repo)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(new-repo src/main.cpp src/fibonacci.cpp)

enable_testing()

add_executable(test_fibonacci_1 src/test_fibonacci_1.cpp src/fibonacci.cpp)
add_test(NAME FibonacciTest1 COMMAND test_fibonacci_1)

add_executable(test_fibonacci_2 src/test_fibonacci_2.cpp src/fibonacci.cpp)
add_test(NAME FibonacciTest2 COMMAND test_fibonacci_2)

add_executable(test_fibonacci_3 src/test_fibonacci_3.cpp src/fibonacci.cpp)
add_test(NAME FibonacciTest3 COMMAND test_fibonacci_3)