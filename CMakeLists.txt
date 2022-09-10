cmake_minimum_required(VERSION 3.15)
project(Homework C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

# Problemas #
add_executable(Problema1 Problemas/Problema1.c)
add_executable(Problema2 Problemas/Problema2.c)
add_executable(Problema3 Problemas/Problema3.c)
add_executable(Problema4 Problemas/Problema4.c)
add_executable(Problema5 Problemas/Problema5.c)
add_executable(Problema6 Problemas/Problema6.c)

# Guias #
add_executable(G1_Ej_A Guias/Guia1/Ejercicio_a.c)
add_executable(G1_Ej_B Guias/Guia1/Ejercicio_b.c)
add_executable(G2_Ejem_1 Guias/Guia2/Ejemplo_1.c)
add_executable(G2_Ejem_3 Guias/Guia2/Ejemplo_3.c)
add_executable(G2_Ej_A Guias/Guia2/Ejercicio_a.c)
add_executable(G2_Ej_B Guias/Guia2/Ejercicio_b.c)

# Talleres #

# Ejercicios de Taller
add_executable(Sem1_EjercicioTaller1 Talleres/Semestre1/Ejercicios/EjercicioTaller1.c)

# Talleres
add_executable(Sem1_Taller1 Talleres/Semestre1/Taller1.c)
add_executable(Sem1_Taller2 Talleres/Semestre1/Taller2.c)
add_executable(Sem1_Taller3 Talleres/Semestre1/Taller3.c)
add_executable(Sem2_Taller1 Talleres/Semestre2/Taller1.c)

# Clases #
add_executable(Clase_18_04_22_Ejercicio6 Clases/18.04.2022/Ejercicio6.c)
add_executable(Clase_19_04_22_Funciones Clases/19.04.2022/Funciones.c)
add_executable(Clase_19_04_22_FuncionesMatematicas Clases/19.04.2022/FuncionesMatematicas.c)
add_executable(Clase_17_05_22_PerimetroAreaCircunferenciaConFunciones Clases/17.05.2022/PerimetroAreaCircunferenciaConFunciones.c)
add_executable(Clase_23_05_22_Ejercicio2 Clases/23.5.2022/Ejercicio2.c)
add_executable(Clase_23_05_22_Ejercicio3 Clases/23.5.2022/Ejercicio3.c)
add_executable(Clase_23_05_22_Ejercicio4 Clases/23.5.2022/Ejercicio4.c)
add_executable(Clase_23_05_22_TipoDeTriangulo Clases/23.5.2022/TipoDeTriangulo.c)
add_executable(Clase_30_05_22_Ejercicio4 Clases/30.05.2022/Ejercicio4.c)
add_executable(Clase_29_08_22_Ejercicio1 Clases/29.8.2022/Ejercicio1.c)
add_executable(Clase_29_08_22_Ejercicio2 Clases/29.8.2022/Ejercicio2.c)
add_executable(Clase_29_08_22_Ejercicio3 Clases/29.8.2022/Ejercicio3.c)
add_executable(Clase_29_08_22_Ejercicio4 Clases/29.8.2022/Ejercicio4.c)
add_executable(Clase_29_08_22_Ejercicio5 Clases/29.8.2022/Ejercicio5.c)
add_executable(Clase_31_08_22_Ejercicio5 Clases/31.8.2022/Ejercicio1.c)


## LIBS ##
target_link_libraries(Sem2_Taller1 m)