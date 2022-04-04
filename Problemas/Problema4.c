/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Calcula si un numero ingresado es positivo o negativo
 */

#include <stdio.h>

int main(){
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    if (numero > 0) {
        printf("El numero es positivo");
    } else if(numero < 0) {
        printf("El numero es negativo");
    } else {
        printf("El numero es neutro");
    }
    return 0;
}


