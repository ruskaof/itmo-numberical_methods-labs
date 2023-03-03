cmake_minimum_required(VERSION 3.24)
project(lab2_nonlinear)

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


add_executable(lab2_nonlinear main.cpp newton/newton_solver.cpp newton/newton_solver.h fixed_point/fixed_point_solver.cpp fixed_point/fixed_point_solver.h util/itermethods_scalar_reduce.cpp util/itermethods_scalar_reduce.h)
