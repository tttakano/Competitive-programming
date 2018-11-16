cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        bits/std++.h
        new.cpp
)

add_executable(untitled new.cpp)
