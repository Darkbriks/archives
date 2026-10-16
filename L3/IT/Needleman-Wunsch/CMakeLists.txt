cmake_minimum_required(VERSION 3.30)
project(Needleman_Wunsch)

set(CMAKE_CXX_STANDARD 20)

add_executable(Needleman_Wunsch main.cpp
        NeedlemanWunsch.h
        NeedlemanWunschLocal.h)
