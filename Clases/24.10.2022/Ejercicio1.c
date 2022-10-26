/*
 * Created by Francisco Solis Maturana on 24/10/2022
 *
 * Para cada una de las categorías de automóviles que comercializa, una distribuidora de
 * vehiculos motorizados registra la marca (texto), el modelo (texto), el año (número),
 * el rendimiento (número) en km/litro y la capacidad (número) del estanque en litros.
 *
 * Considerando que estos datos ocupan n posiciones en un arreglo, se pide
 * a) Declarar los tipos de datos adecuados
 * b) Implementar una funcion que, a partir del arreglo, imprima una lista de tríos marca, modelo
 * distancia (a recorrer con la capacidad del estanque).
 */

#include <stdio.h>

typedef char texto[20];
typedef int numero;


typedef struct {
    texto marca;
    texto modelo;
    numero anio;
    numero rendimiento;
    numero capacidad;
} automovil;

typedef automovil autos[15];

void imprimirLista(autos arreglo, int n);

int main() {
    autos arreglo = {
            { "Ford", "Galaxie", 1963},
            {"Ford", "Fiesta", 2019, 10, 40},
            {"Ford", "Focus", 2019, 10, 40},
            {"Ford", "Fusion", 2019, 10, 40},
            {"Ford", "Mustang", 2019, 10, 40},
            {"Ford", "Ranger", 2019, 10, 40},
            {"Ford", "EcoSport", 2019, 10, 40},
            {"Ford", "Explorer", 2019, 10, 40},
            {"Ford", "F-150", 2019, 10, 40},
            {"Ford", "F-250", 2019, 10, 40},
            {"Ford", "F-350", 2019, 10, 40},
            {"Ford", "F-450", 2019, 10, 40},
            {"Ford", "F-550", 2019, 10, 40},
            {"Ford", "F-650", 2019, 10, 40},
            {"Ford", "F-750", 2019, 10, 40},
    };

    imprimirLista(arreglo, 15);

    return 0;
}

void imprimirLista(autos arreglo, int n) {
    for (int pagina = 0; pagina < n/3; ++pagina) {
        for(int idx = 0 * pagina; idx < 3; idx++) {
            printf("%s %s %d\n", arreglo[idx].marca, arreglo[idx].modelo, arreglo[idx].capacidad);
        }

        printf("\n");
    }
}

