cmake_minimum_required(VERSION 3.23)
project(lalamarjas C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lalamarjas
        main.c
        pessoa.c
        pessoa.h
        pet.c
        pet.h)
