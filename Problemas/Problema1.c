//
// Created by Francisco Solis Maturana on 03-04-22.
//
#include <stdio.h>

int main(){
    // Declarar variables
    float base, altura, area;

    // Solicitar base
    printf("Ingrese la base del triangulo: ");
    scanf("%f", &base);

    // Solicitar altura
    printf("Ingrese la altura del triangulo: ");
    scanf("%f", &altura);

    // Calcular area
    area = (base * altura) / 2;

    // Mostrar el area con un limite de 2 decimales
    printf("El area del triangulo es: %.2f", area);
    return 0;
}
