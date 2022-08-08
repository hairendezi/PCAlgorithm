cmake_minimum_required(VERSION 3.21)
project(PCAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(PCAlgorithm main.cpp utils.h utils.cpp Elementary.h Elementary.cpp algorithms/CutSplit.h algorithms/CutSplit.cpp)
