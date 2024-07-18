cmake_minimum_required(VERSION 3.27)
project(tpFinalC C)

set(CMAKE_C_STANDARD 11)

add_executable(tpFinalC main.c
        preguntas.c
        examenes.c
        correcciones.c
        persistencia.c
        prueba.c
        functions.h
        menu.c
        persistencia.h
        util.h
        util.c
)
