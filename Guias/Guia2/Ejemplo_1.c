/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Escribir un programa que permita convertir centímetros en pulgadas.
 */

#include <stdio.h>

int main(){
    float cm, pulgadas;

    printf("Ingrese los centimetros: ");
    scanf("%f", &cm);

    pulgadas = cm / 2.54f;

    printf("%f cm son %f pulgadas", cm, pulgadas);

    return 0;
}

