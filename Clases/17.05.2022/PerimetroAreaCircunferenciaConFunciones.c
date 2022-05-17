/*
 * Created by Francisco Solis Maturana on 19-04-22.
 *
 * Escriba un programa que reciba el valor del radio de una circunferencia y retorne el respectivo perimetro y area
 */

#include <stdio.h>

float getArea(float radio);
float getPerimetro(float radio);

int main(){
    float radio;
    printf("Ingrese el radio de la circunferencia: ");
    scanf("%f", &radio);
    printf("El area es: %f\n", getArea(radio));
    printf("El perimetro es: %f\n", getPerimetro(radio));
    return 0;
}

float getArea(float radio){
    return 3.1416 * radio * radio;
}

float getPerimetro(float radio){
    return 2 * 3.1416 * radio;
}