/**
 * Created by Francisco Solis at 2020-05-23
 * 
 * Implementar una función que retorne la cantidad de dígitos de un numero entero positivo N
 */

#include <stdio.h>

int cantidadDeDigitos(int N){
    int contador = 0;
    while (N > 0) {
        N /= 10;
        contador++;
    }
    return contador;
}

int main() {
    int N;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &N);
    int cantidad = cantidadDeDigitos(N);
    printf("La cantidad de digitos de %d es %d", N, cantidad);
}