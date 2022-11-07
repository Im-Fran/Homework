/*
 * Se quieren registrar las temperaturas diarias en una semana del mes de noviembre,
 * de tal manera que podamos obtener informacion posterior de dichas temperaturas y los dias en que se generaron.
 *
 * Considere los dias Lunes, Martes, Miercoles, Jueves, Viernes Sabado y Domingo.
 * Se requiere:
 * 1. Una funcion con la estructura necesaria para ingresar dichos registros.
 * 2. Ingresar el dia en que se produjo la 4ta temperatura mas alta
 * 3. Guardar la información en archivo "Noviembre"
 * 4. Mostrar la información del archivo "Noviembre"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[10];

typedef struct {
    string dia;
    float temperatura;
} TemperaturaDelDia;

void ingresarTemperaturas(TemperaturaDelDia *temperaturas);

void mostrarTemperaturas(TemperaturaDelDia *temperaturas);

void ordernarTemperaturas(TemperaturaDelDia *temperaturas);

void obtenerCuartaTemperaturaMasAlta(TemperaturaDelDia *temperaturas);

int main() {
    int i;
    printf("Deseas ingresar nuevas temperaturas? (1 = Si, 0 = No): ");
    scanf("%d", &i);
    TemperaturaDelDia temperaturas[7];
    if(i == 1){
        printf("Ingrese las temperaturas de la semana:\n");
        ingresarTemperaturas(temperaturas);
    }

    // Cargar temperaturas desde archivo
    FILE *archivo = fopen("Noviembre", "r");
    if(archivo == NULL){
        printf("No se pudo abrir el archivo");
        return 1;
    }
    for(i = 0; i < 7; i++){
        fscanf(archivo, "%s %f", temperaturas[i].dia, &temperaturas[i].temperatura);
    }

    ordernarTemperaturas(temperaturas);

    printf("\n\nTemperaturas ingresadas: \n");
    mostrarTemperaturas(temperaturas);

    printf("\n\n");
    obtenerCuartaTemperaturaMasAlta(temperaturas);
    return 0;
}

void ingresarTemperaturas(TemperaturaDelDia *temperaturas) {
    FILE *archivo = fopen("Noviembre", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        exit(1);
    }
    for (int i = 0; i < 7; i++) {
        printf("Ingrese el dia: ");
        scanf("%s", temperaturas[i].dia);
        printf("Ingrese la temperatura: ");
        scanf("%f", &temperaturas[i].temperatura);
        fprintf(archivo, "%s %.2f\n", temperaturas[i].dia, temperaturas[i].temperatura);
    }
    fclose(archivo);
}

void mostrarTemperaturas(TemperaturaDelDia *temperaturas) {
    for (int i = 0; i < 7; i++) {
        printf("%s %.2f\n", temperaturas[i].dia, temperaturas[i].temperatura);
    }
}

void obtenerCuartaTemperaturaMasAlta(TemperaturaDelDia *temperaturas) {
    printf("La cuarta temperatura mas alta fue: %.2f", temperaturas[3].temperatura);
}

void ordernarTemperaturas(TemperaturaDelDia *temperaturas) {
    TemperaturaDelDia aux;
    for(int i = 0; i < 6; i++){
        for(int j = 6; j > i; j--){
            if(temperaturas[j].temperatura > temperaturas[j-1].temperatura){
                aux = temperaturas[j];
                temperaturas[j] = temperaturas[j-1];
                temperaturas[j-1] = aux;
            }
        }
    }
}