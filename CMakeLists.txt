cmake_minimum_required(VERSION 3.16)
project(Pokedex_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pokedex_Project
                src/main.cpp
                src/Pokedex.cpp
                src/Pokemon.cpp
        )
