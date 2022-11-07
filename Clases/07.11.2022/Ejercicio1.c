/*
 * Created by Francisco Solis Maturana on 07/11/2022.
 *
 * Obtener el primer digito de un numero natural utilizando recursividad
 * Por ejemplo: el numero 35346 deberia devolver 3
 */

#include <stdio.h>

int obtenerPrimerDigito(int numero);

int main() {
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("El primer digito del numero %d es %d", numero, obtenerPrimerDigito(numero));
    return 0;
}

int obtenerPrimerDigito(int numero) {
    if (numero < 10) {
        return numero;
    }
    return obtenerPrimerDigito(numero / 10);
}