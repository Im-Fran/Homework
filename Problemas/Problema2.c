/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Calculo de promedio ponderado, nota 1 con 30%, nota 2 con 30% y nota 3 con 40%
 */

#include "stdio.h"

// Obtener nota
float getNota(int numero) {
    float nota;
    printf("Ingrese nota %d: ", numero);
    scanf("%f", &nota);
    return nota;
}

int main(){
    // Declaracion de variables
    float nota1 = getNota(1);
    float nota2 = getNota(2);
    float nota3 = getNota(3);

    // Calculo de promedio ponderado
    float promedioPonderado = (nota1 * 0.3f) + (nota2 * 0.3f) + (nota3 * 0.4f);

    // Imprimir resultado
    printf("El promedio ponderado es: %.2f\n", promedioPonderado);
    return 0;
}

