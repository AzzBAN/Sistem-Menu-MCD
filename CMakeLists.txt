cmake_minimum_required(VERSION 3.21)
project(SistemMenuMCD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Multi_III
        list_child.cpp
        list_child.h
        list_parent.cpp
        list_parent.h
        list_relasi.cpp
        list_relasi.h
        main.cpp)