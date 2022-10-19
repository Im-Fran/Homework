/**
 * Created by Francisco Solís on 17-10-2022
 * Implementar una funcion que retorne la suma de los valores significativos
 * impares de una matriz triangular inferior derecha 'C' de tipo cuadrada y
 * orden n sin acceder a los elementos situados sobre la diagonal
 */

#include <stdio.h>
typedef int matriz[10][10];

int random();
void crearMatriz(matriz *c, int n);
int sumaImpares(matriz *c, int n);

int main() {
    matriz c;
    int n = 5;
    crearMatriz(&c, n);

    /* Formato matriz:
     *
     * 0    0   0   0   4
     * 0    0   0   8   9
     * 0    0  12   13  14
     * 0    16 17   18  19
     * 20   21 22   23  24
     *
     * La idea es leer los datos 4, 8, 12, 16 y 20
     */

    for(int i = 0; i < n; i++) {
        for (int j = n - 1 - i; j < n; j++) {
            if(c[i][j] % 2 != 0) {
                printf("%d, ", c[i][j]);
            }
        }
    }


}

void crearMatriz(matriz *c, int n) {
    int i = 0;
    for (int x = 0; x < n; x++) {
        for (int y = n-1; y >= 0; y--) {
            if (x >= y) {
                (*c)[x][y] = i;
            } else {
                (*c)[x][y] = 0;
            }
            i++;
            printf("%d\t", (*c)[x][y]);
        }
        printf("\n");
    }
}