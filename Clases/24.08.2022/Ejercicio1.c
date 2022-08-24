/**
 * Created by Francisco Solis at 2022-08-24
 * 
 * Definir una funcion "oso", que sume los digitos pares de un numero entero ingresado y retorne la suma
 */
#include <stdio.h>

int oso(int numero){
    int suma = 0;
    while(numero > 0){
        if(numero % 2 == 0){
            suma += numero % 10;
        }
        numero /= 10;
    }
    return suma;
}

int main(){
    int numero = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("La suma de los digitos pares es: %d\n", oso(numero));
    return 0;
}