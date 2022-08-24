/*
 * Created by Francisco Solis at 2022-08-24
 * 
 * Mediante bolas de acero apiladas por capas, se ha construido una pirámide de base cuadrada,
 * de modo que en su cima hay una bola apoyada sobre otras cuatro, las cuales están apoyadas sobre
 * otras nueve, las cuales estan apoyadas sobre otras 16, etc.
 * Implementar una funcion que calcule la cantidad de bolas necesarias para formar una 
 * piramide de c capas.
 */
#include <stdio.h>
#include <math.h>

void imprime(int c) {
    int suma = 0;
    for(int i = 1; i <= c; i++){
        suma = suma + pow(2, i);
    }
    printf("Necesitas %d bolas.\n", suma);
}

int main() {
    int c;
    printf("Ingrese el numero de capas: ");
    scanf("%d", &c);
    imprime(c);
    return 0;
}