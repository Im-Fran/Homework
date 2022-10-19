/**
 * Se tiene la instruccion typedef con un int vector[100];
 * implementar una funcion que reciba un vector 'v' de largo n < 100
 * ordenado ascendentemente
 */

#include <stdio.h>
#include <stdlib.h>

typedef int vector[10];

int insertar(vector v, int n) {
    printf("\n\nDonde deseas ingresar un valor? (Ingresa el indice entre 0 y %d): ", n);
    int indice = 0;
    scanf("%d", &indice);
    while (indice < 0 || indice > n) {
        printf("\nIngresa un indice valido: ");
        scanf("%d", &indice);
    }

    printf("Ingresa el valor a insertar: ");
    scanf("%d", &v[indice]);
    printf("Vector actualizado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d.- %d\n", i, v[i]);
    }
    return 0;
}

int main() {
    vector v;
    int n = 0;
    printf("Ingrese el largo del vector: ");
    scanf("%d", &n);
    while(n > 100 || n < 0) {
        printf("\nIngresa un largo valido: ");
        scanf("%d", &n);
    }

    for (int i = 0; i < n; i++) {
        v[i] = i+1; // Se rellena el vector
    }

    insertar(v, n);
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        printf("%d.- %d\n", i, v[i]);
    }
}
