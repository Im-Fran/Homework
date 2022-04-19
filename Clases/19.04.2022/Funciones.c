/*
 * Created by Francisco Solis Maturana on 19-04-22.
 *
 * Utilizando funciones calcule el area de un triangulo dadas su variables por el usuario
 */

#include <stdio.h>

float calculoArea(float base, float altura){
    return (base * altura) / 2;
}

int main(){
    // Declaración de variables
    float base, altura, area;
    area = 0;

    // Obtener base y altura
    printf("Ingresa la base del triángulo: ");
    scanf("%f", &base);
    printf("Ingresa la altura del triángulo: ");
    scanf("%f", &altura);

    if(base == 0 || altura == 0) {
        printf("ERROR! Por favor utiliza un numero mayor a 0 para la base y la altura.");
        printf("\nDeseas reiniciar el programa? (s/n): ");
        char resultado;
        scanf(" %s", &resultado);
        if(resultado == 's'){
            return main();
        }
    }

    // Calculo de area
    area = calculoArea(base,altura);
    printf("\n\nEl área del triángulo es: %.2f", area);
}
