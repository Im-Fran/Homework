/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Escriba un programa que lea un número entero positivo y muestre  el doble y el triple de dicho número.
 */

#include <stdio.h>

int main(){
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("El doble de %d es %d y el triple es %d\n", numero, numero*2, numero*3);
    return 0;
}