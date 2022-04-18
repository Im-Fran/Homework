/*
 * Created by Francisco Solis Maturana on 18-04-22.
 *
 * Ingresar numeros por teclado hasta que se ingrese el número 100. Determinar:
 * 
 * - Cuantos son mayores o iguales a 50
 * - La suma de los mayores que 80
 * - Cuantos son mayores a o iguales que 40 y menores que 60
 * - Determine el promedio de los números ingresados
 */

#include <stdio.h>

int main(){
    int numero, mayores50 = 0, sumaMayores80 = 0, mayores40Menores60 = 0, i;
    float promedio;

    for(i = 0; numero != 100; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if(numero > 50){
            mayores50++;
        }

        if(numero > 80){
            sumaMayores80 += 1;
        }

        if(numero >= 40 && numero < 60){
            mayores40Menores60++;
        }

        promedio = promedio + numero;
    }

    printf("\n\n");
    printf("\nMayores a 50: %d", mayores50);
    printf("\nSuma de los mayores que 80: %d", sumaMayores80);
    printf("\nMayores a o iguales que 40 y menores que 60: %d", mayores40Menores60);
    printf("\nPromedio de los números ingresados: %f", promedio/i);

}