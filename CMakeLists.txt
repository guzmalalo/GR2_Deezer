cmake_minimum_required(VERSION 3.26)
project(GR2_Deezer C)

set(CMAKE_C_STANDARD 11)

add_executable(GR2_Deezer main.c
        music.c
        music.h)
