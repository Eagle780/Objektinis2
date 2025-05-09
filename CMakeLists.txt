cmake_minimum_required(VERSION 3.10)
project(GalutinisBalas VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
enable_testing()
add_executable(GalutinisBalas
    galutinis_balas.cpp
    funkcijos.cpp
)
add_subdirectory(tests)