cmake_minimum_required(VERSION 3.16)
project(Wordle)

set(CMAKE_CXX_STANDARD 20)

add_executable(Wordle main.cpp consts.cpp wordle.h wordle.cpp)
