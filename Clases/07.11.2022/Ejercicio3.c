/*
 * Created by Francisco Solis Maturana on 07/11/2022.
 *
 * La cantidad de bacterias en cierto cultivo es inicialmente x y crece
 * duplicandose diariamente. Implementar una funcion recursiva que determine
 * la cantidad de bacterias que existiran despues de n dias.
 *
 * Comprobar que para x = 500, despues de n=10 dias la poblacion de bacterias
 * alcanzará los 512000 ejemplares.
 */

#include <stdio.h>

int calcularPoblacion(int x, int n);

int main() {
    int x, n;
    printf("Ingrese la cantidad inicial de bacterias: ");
    scanf("%d", &x);
    printf("Ingrese la cantidad de dias: ");
    scanf("%d", &n);
    printf("La poblacion de bacterias despues de %d dias es %d", n, calcularPoblacion(x, n));
    return 0;
}

int calcularPoblacion(int x, int n) {
    if (n == 0) {
        return x;
    }
    return calcularPoblacion(x * 2, n - 1);
}