/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Programa que permite el ingreso de 2 numeros.
 * - Si los 2 numeros son iguales, multiplicarlos
 * - Si el primer numero es mayor que el segundo, restarlos
 * - Si el primer numero es menor que el segundo, sumarlos
 */

#include <stdio.h>

int main(){
    int num1, num2;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    if(num1 == num2){
        printf("El resultado es: %d\n", num1 * num2);
    }else if(num1 > num2){
        printf("El resultado es: %d\n", num1 - num2);
    }else{
        printf("El resultado es: %d\n", num1 + num2);
    }

    return 0;
}

