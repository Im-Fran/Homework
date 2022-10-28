/**
 * Genere una funcion que cree una matriz triangular inferior izquierda 'C' de tipo cuadrada y orden n,
 * luego reflejarla sobre la diagonal principal e imprimir la matriz resultante.
 */

#include <stdio.h>

typedef int matriz[10][10];

int main() {
    matriz c;
    int n = 5;
    int i = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (x <= y) {
                c[x][y] = i+1;
            } else {
                c[x][y] = 0;
            }
            i++;
            printf("%d\t", c[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (x < y) {
                c[y][x] = c[x][y];
                c[x][y] = 0;
            }
            printf("%d\t", c[x][y]);
        }
        printf("\n");
    }
}