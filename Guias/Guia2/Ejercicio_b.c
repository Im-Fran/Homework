/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Escribir  un  programa,  que  permita  leer  tres  números  enteros  (asuma  que  son  distintos entre sí) y determine el número central (no es el mayor ni el menor).
 */


#include <stdio.h>

int main(){
    int num1, num2, num3, numCentral;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);

    if (num1 < num2 && num2 < num3) {
        numCentral = num2;
    } else if (num1 < num3 && num3 < num2 || num2 < num3 && num3 < num1) {
        numCentral = num3;
    } else if (num2 < num1 && num1 < num3 || num3 < num1 && num1 < num2) {
        numCentral = num1;
    } else {
        numCentral = num2;
    }

    printf("El numero central es: %d", numCentral);

    return 0;
}

