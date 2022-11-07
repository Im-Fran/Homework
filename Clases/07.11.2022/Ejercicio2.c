/*
 * Created by Francisco Solis Maturana on 07/11/2022.
 *
 * Implementar una función recursiva que imprima los digitos de la representación binaria de un numero natural n
 *
 * Por ejemplo n = 19
 * 19 / 2 = 9 resto 1
 * 9 / 2 = 4 resto 1
 * 4 / 2 = 2 resto 0
 * 2 / 2 = 1 resto 0
 * 1 / 2 = 0 resto 1
 *
 * 1 0 0 1 1
 */

#include <stdio.h>

void imprimirBinario(int numero);

int main() {
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("El numero %d en binario es: ", numero);
    imprimirBinario(numero);
    return 0;
}

void imprimirBinario(int numero) {
    if (numero < 2) {
        printf("%d", numero);
        return;
    }
    imprimirBinario(numero / 2);
    printf("%d", numero % 2);
}