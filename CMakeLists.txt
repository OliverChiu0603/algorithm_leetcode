cmake_minimum_required(VERSION 4.0)
project(algorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(algorithm main.cpp
        util.h
        leetcode/21.h
        leetcode/86.h)
