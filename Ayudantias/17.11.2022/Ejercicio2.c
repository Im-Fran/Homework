/*
 * Created by Francisco Solis Maturana on 2021-11-17.
 *
 * La funcion veces(v,e,n) retorna la cantidad de veces que aparece un entero
 * e en un vector v de n numeros enteros. Implementar de manera iterativa y recursiva.
 */

#include <stdio.h>

int iterativa(int v[], int e, int n);

int recursiva(int v[], int e, int n);

int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    int e = 2;
    int n = 18;
    printf("La cantidad de veces que aparece %d en el vector es %d (it)\n", e, iterativa(v, e, n));
    printf("La cantidad de veces que aparece %d en el vector es %d (re)", e, recursiva(v, e, n));
    return 0;
}

int iterativa(int v[], int e, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == e) {
            c++;
        }
    }
    return c;
}

int recursiva(int v[], int e, int n) {
    if (n == 0) {
        return 0;
    } else {
        if (v[n - 1] == e) {
            return 1 + recursiva(v, e, n - 1);
        } else {
            return recursiva(v, e, n - 1);
        }
    }
}
