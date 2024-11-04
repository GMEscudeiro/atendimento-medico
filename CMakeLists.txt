cmake_minimum_required(VERSION 3.29)
project(Projeto C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projeto
    abb.h
    fila.h
    lista.h
    main.c
    pilha.h
    registro.h)
