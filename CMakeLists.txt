cmake_minimum_required(VERSION 3.17)
project(concat)

set(CMAKE_CXX_STANDARD 14)

add_executable(concat
        main.cpp join_iterator.h concatenation.h)
