/*
 * Created by Francisco Solis at 2022-08-24
 * 
 * Implementar una funcion que acepte un numero natural b en base 2 y retorne b en base 10
 */
#include <stdio.h>
#include <math.h>

int binario_a_decimal(int b) {
    int decimal = 0;
    int i = 0;
    while (b != 0) {
        decimal += b % 10 * pow(2, i);
        b /= 10;
        i++;
    }
    return decimal;
}

int main() {
    int b;
    printf("Ingrese un numero en base 2: ");
    scanf("%d", &b);
    printf("%d en base 10 es %d\n", b, binario_a_decimal(b));
    return 0;
}