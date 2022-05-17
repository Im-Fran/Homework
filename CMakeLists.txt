cmake_minimum_required(VERSION 3.21)
project(Homework C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

# Problemas #

# Problema 1 al 6
add_executable(Problema1 Problemas/Problema1.c)
add_executable(Problema2 Problemas/Problema2.c)
add_executable(Problema3 Problemas/Problema3.c)
add_executable(Problema4 Problemas/Problema4.c)
add_executable(Problema5 Problemas/Problema5.c)
add_executable(Problema6 Problemas/Problema6.c)

# Guias #

# Guia 1, Ejercicio_a y Ejercicio_b
add_executable(G1_Ej_A Guias/Guia1/Ejercicio_a.c)
add_executable(G1_Ej_B Guias/Guia1/Ejercicio_b.c)

# Guia 2, Ejemplo_1 Ejemplo_3, Ejercicio a al b
add_executable(G2_Ejem_1 Guias/Guia2/Ejemplo_1.c)
add_executable(G2_Ejem_3 Guias/Guia2/Ejemplo_3.c)

add_executable(G2_Ej_A Guias/Guia2/Ejercicio_a.c)
add_executable(G2_Ej_B Guias/Guia2/Ejercicio_b.c)

# Talleres #

# Ejercicios de Taller
add_executable(EjercicioTaller1 Talleres/Ejercicios/EjercicioTaller1.c)

# Talleres
add_executable(Taller1 Talleres/Taller1.c)
