cmake_minimum_required(VERSION 3.24)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "-std=c++17 -Wall -Werror -g -O0")
set(CMAKE_CXX_FLAGS_SANITIZED "-fsanitize=address,undefined,leak")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -O3")

if (CMAKE_BUILD_TYPE STREQUAL "Sanitized")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_SANITIZED}")
    message("SANITIZED build")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")
    message("RELEASE build")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")
    message("DEBUG build")
endif ()


add_executable(lab1 src/main.cpp src/matrix/MatrixRow.cpp src/matrix/MatrixRow.h src/matrix/Matrix.cpp src/matrix/Matrix.h src/input/matrix_input.cpp src/input/matrix_input.h src/gauss/gauss_method.cpp src/gauss/gauss_method.h src/util/tolerant_equals.h)
