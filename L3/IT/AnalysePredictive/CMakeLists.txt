cmake_minimum_required(VERSION 3.31)
project(AnalysePredictive)

set(CMAKE_CXX_STANDARD 20)

add_executable(Exo-1 "Exo 1/main.cpp"
        "Exo 1/AnalyseurSyntaxique.h"
        "Exo 1/AnalyseurSyntaxique.cpp"
)

add_executable(Exo-2 "Exo 2/main.cpp"
        "Exo 2/PDA.cpp"
        "Exo 2/PDA.h"
)