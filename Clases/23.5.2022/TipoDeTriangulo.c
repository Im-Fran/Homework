/**
 * Created by Francisco Solis at 2022-05-23
 * 
 * Escribir una función que valide si 3 longitudes a,b,c forman o no un triángulo y, en caso afirmativo, indicar si es equilatero, isoceles, o escaleno. (Si no es un triángulo, retornar 0. Si es equilatero 1, si es isoceles 2 y escaleno 3).
 */

#include <stdio.h>
#include <stdbool.h>

bool esTriangulo(float lado1, float lado2, float lado3) {
    return lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1; // Revisar si es un triangulo
}

bool esEquilatero(float lado1, float lado2, float lado3) {
    return lado1 == lado2 && lado2 == lado3; // Revisar si es equilatero
}

bool esIsosceles(float lado1, float lado2, float lado3) {
    return lado1 == lado2 || lado1 == lado3 || lado2 == lado3; // Revisar si es isosceles
}

bool esEscaleno(float lado1, float lado2, float lado3) {
    return lado1 != lado2 && lado1 != lado3 && lado2 != lado3; // Revisar si es escaleno
}


int main() {
    float lado1, lado2, lado3;
    printf("Ingrese el lado 1: ");
    scanf("%f", &lado1);
    printf("Ingrese el lado 2: ");
    scanf("%f", &lado2);
    printf("Ingrese el lado 3: ");
    scanf("%f", &lado3);
    // Revisamos si los lados forman un triangulo
    if (esTriangulo(lado1, lado2, lado3)) {
        // Revisamos si los lados forman un triangulo equilatero
        if (esEquilatero(lado1, lado2, lado3)) {
            printf("El triangulo es equilatero");
            return 1;
        }
        // Revisamos si los lados forman un triangulo isosceles
        else if (esIsosceles(lado1, lado2, lado3)) {
            printf("El triangulo es isosceles");
            return 2;
        }
        // Revisamos si los lados forman un triangulo escaleno
        else if(esEscaleno(lado1, lado2, lado3)) {
            printf("El triangulo es escaleno");
            return 3;
        } else {
            printf("No forma un triangulo");
            return 0;
        }
    } else {
        printf("No forma un triangulo");
        return 0;
    }
}