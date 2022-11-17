/*
 * Created by Francisco Solis Maturana on 2021-11-17.
 *
 * La funcion unos(b) retorna la cantidad de unos (1's) que existen
 * en la representacion binaria de un entero positivo b. por ejemplo si
 * b = 100111011 la funcion deberá retornar 6. Implementar de manera
 * iterativa y recursiva.
 */

#include <stdio.h>

int iterativa(int b);
int recursiva(int b);
int binario(int x);

int main() {
    int b = binario(5);
    printf("La cantidad de unos en %d es %d (it)\n", b, iterativa(b));
    printf("La cantidad de unos en %d es %d (re)", b, recursiva(b));
    return 0;
}

int binario(int x) {
    int bin = 0;
    int i = 1;
    while (x != 0) {
        bin += (x % 2) * i;
        x /= 2;
        i *= 10;
    }
    return bin;
}

int iterativa(int b) { // Contar cantidad de unos
    int c = 0;
    while (b != 0) {
        if (b % 10 == 1) {
            c++;
        }
        b /= 10;
    }
    return c;
}

int recursiva(int b) {
    if (b == 0) {
        return 0;
    } else {
        if (b % 10 == 1) {
            return 1 + recursiva(b / 10);
        } else {
            return recursiva(b / 10);
        }
    }
}