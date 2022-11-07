/*
 * Created by Francisco Solis Maturana on 07/11/2022.
 *
 * Implementar una funcion recursiva que llene un vector de tamaño n
 */

#include <stdio.h>
#include <stdlib.h>

typedef int vector[100];

int numeroAleatorio(int min, int max);

void llenarVector(vector v, int n, int i);

void imprimirVector(vector v, int n, int i);

int main() {
    vector v;
    int n;
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &n);
    llenarVector(v, n, 0);
    imprimirVector(v, n, 0);
    return 0;
}

void llenarVector(vector v, int n, int i) {
    if (i == n) {
        return;
    }
    v[i] = numeroAleatorio(100, 999);
    llenarVector(v, n, i + 1);
}

int numeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void imprimirVector(vector v, int n, int i) {
    if (i == n) {
        return;
    }

    printf("%d ", v[i]);
    imprimirVector(v, n, i + 1);
}