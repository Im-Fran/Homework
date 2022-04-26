/*
 * Created by Francisco Solis Maturana on 26-04-22.
 *
 * Taller 1
 */

#include <stdio.h>

void main(){
    int asistentes; // Cantidad de asistentes al teatro
    float precio_entrada; // Precio de la entrada 
    float categoria1 = 0; // Edad de 5 a 17 (Descuento 30%)
    float categoria2 = 0; // Edad de 18 a 25 (Descuento 20%)
    float categoria3 = 0; // Edad de 26 a 49 (Descuento 25%)
    float categoria4 = 0; // Edad de 50 en adelante (Descuento 35%)

    printf("\nIngresa la cantidad de asistentes: "); // Solicite la cantidad de asistentes
    scanf("%d", &asistentes);
    printf("\nIngresa el precio de la entrada: "); // Solicite el precio de la entrada
    scanf("%f", &precio_entrada);

    for(int i = 0; i < asistentes; i++){ // Ciclo para solicitar la edad de cada asistente
        int edad;
        do {
            printf("\nIngresa la edad de la persona #%d: ", i+1);
            scanf("%d", &edad);
        } while(edad < 5); // Si es menor de 5 años, no puede ingresar al teatro

        // Identificar la categoria de cada asistente
        if(edad >= 5 && edad <= 17){
            categoria1++;
        } else if(edad >= 18 && edad <= 25){
            categoria2++;
        } else if(edad >= 26 && edad <= 49){
            categoria3++;
        } else {
            categoria4++;
        }
    }

    // Ahora se muestra la cantidad de dinero que se deja de percibir por cada categoria
    categoria1 = (categoria1 * precio_entrada) * 0.3;
    categoria2 = (categoria2 * precio_entrada) * 0.2;
    categoria3 = (categoria3 * precio_entrada) * 0.25;
    categoria4 = (categoria4 * precio_entrada) * 0.35;

    // Mostrar datos
    printf("\nCategoria 1 dejó de percibir: %.2f", categoria1);
    printf("\nCategoria 2 dejó de percibir: %.2f", categoria2);
    printf("\nCategoria 3 dejó de percibir: %.2f", categoria3);
    printf("\nCategoria 4 dejó de percibir: %.2f", categoria4);

}