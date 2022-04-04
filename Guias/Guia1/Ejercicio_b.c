/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Escriba  un  programa  que  lea  una  cierta  cantidad  de  kilómetros y muestre  su  equivalente en millas náuticas.
 */

#include <stdio.h>

int main(){
    float km, millas;
    printf("Ingrese la cantidad de kilometros: ");
    scanf("%f", &km);
    millas = km * 1.852f;
    // Mostrar con 3 decimales, pero si el numero tiene 0 decimales, mostrar solo el numero entero
    printf("%.3f kilometros son %.3f millas náuticas", km, millas);
    return 0;
}