/**
 * Created by Francisco Solis at 2020-05-23
 * 
 * Escribir una función que retorne la cantidad de veces que se debe restar un valor de a un entero positvo n hasta tomar el primer valor negativo.
 */

#include <stdio.h>

int cantidadDeVecesQueSeDebeRestar(int a, int n) {
    int contador = 0;
    while (a >= 0) {
        a -= n;
        contador++;
    }
    return contador;
}

int main() {
    int a,b;
    printf("Ingrese el valor de a: ");
    scanf("%d", &a);
    printf("Ingrese el valor de b: ");
    scanf("%d", &b);
    int cantidad = cantidadDeVecesQueSeDebeRestar(a, b);
    printf("La cantidad de veces que se debe restar %d a %d es %d", a, b, cantidad);
}