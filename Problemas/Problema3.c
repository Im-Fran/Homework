/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Calcula el dia de la semana dado el numero de día.
 * Ejemplo: Ingresa 1 recibe Lunes, 2 recibe Martes, etc.
 */

#include <stdio.h>

int main(){
    // Asignacion de variables
    char *dias[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    int dia;

    // Soliciud de datos
    printf("Ingrese el día de la semana: ");
    scanf("%d", &dia);

    // Verificacion de datos
    if(dia < 1 || dia > 7){
        printf("Día inválido. Por favor ingrese un día entre 1 y 7.\n");
        return main();
    } else {
        // Imprimir resultado
        printf("El día de la semana es %s", dias[dia-1]);
    }

    return 0;
}