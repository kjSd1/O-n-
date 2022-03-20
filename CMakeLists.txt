cmake_minimum_required(VERSION 3.21)
project(O_n_ C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(libs)

add_executable(O_n_ main.c
        libs/algorithms/algorithms.c libs/algorithms/algorithms.h
        libs/sortArray/sortArray.c libs/sortArray/sortArray.h
        )
