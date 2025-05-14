cmake_minimum_required(VERSION 3.29.6)
project(BACKPACK)

set(CMAKE_CXX_STANDARD 20)

add_executable(BACKPACK main.cpp
        Backpack.cpp
        Backpack.h
        utils.h)
