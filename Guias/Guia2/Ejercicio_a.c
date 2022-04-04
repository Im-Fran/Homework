/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Escribir  un  programa,  que  permita  leer  tres  números  enteros  (asuma  que  son  distintos entre sí) y determine el mayor.
 */


#include <stdio.h>

int main(){
    int a, b, c;
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &c);

    if (a > b && a > c){
        printf("El numero mayor es: %d", a);
    } else if (b > a && b > c){
        printf("El numero mayor es: %d", b);
    } else if (c > a && c > b){
        printf("El numero mayor es: %d", c);
    } else {
        printf("Los numeros ingresados son iguales");
    }

    return 0;
}

