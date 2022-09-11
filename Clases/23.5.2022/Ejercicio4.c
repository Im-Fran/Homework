/**
 * Created by Francisco Solis at 2022-05-23
 *
 * Implementar una función que retorne la suma de los dígitos de un numero entero positivo N
 */

#include <stdio.h>

int sumarDigitos(int N){
    int suma = 0;
    while (N > 0) {
        suma += N % 10;
        N /= 10;
    }
    return suma;
}

int main() {
    int N;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &N);
    int suma = sumarDigitos(N);
    printf("La suma de los digitos de %d es %d", N, suma);
}