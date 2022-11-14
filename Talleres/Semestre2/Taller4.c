/*
 * Created by Francisco Solís y Benjamín Farías on 12/11/2022
 * Video: https://youtu.be/Xi3Ta2xZZmo
 */

#include <stdio.h>

typedef struct {
    int numero; // Numero de departamento
    int superficie; // Superficie en m2
    int valorUF; // Valor en UF
} Departamento;

typedef struct {
    int pisos; // Cantidad de pisos
    int departamentos; // Cantidad de departamentos por piso
    Departamento edificio[50][50]; // Arreglo bidimensional de departamentos
} Edificio;

void crearEdificio(Edificio *edificio, int pisos, int departamentos);

void asignarNumeroDepartamento(Edificio *edificio);

void imprimirEdificio(Edificio *edificio);

int main() {
    Edificio edificio;

    int opcion;
    // Menú
    do {
        printf("Menú de opciones:\n");
        printf("1. Crear edificio\n");
        printf("2. Asignar datos de departamentos\n");
        printf("3. Imprimir edificio\n");
        printf("4. Salir\n");
        printf("Ingrese una opción:\n> ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crearEdificio(&edificio, 3, 4);
                printf("Edificio creado con éxito");
                break;
            case 2:
                asignarNumeroDepartamento(&edificio);
                printf("Número de departamento asignado con éxito");
                break;
            case 3:
                imprimirEdificio(&edificio);
                break;
            case 4:
                printf("Saliendo...");
                break;
            default:
                printf("Opción inválida");
                break;
        }

        printf("\n\n");
    }while (opcion != 4);
}

void crearEdificio(Edificio *edificio, int pisos, int departamentos) {
    edificio->pisos = pisos;
    edificio->departamentos = departamentos;
}

void asignarNumeroDepartamento(Edificio *edificio) {
    for (int i = 0; i < edificio->pisos; i++) {
        int base = (i + 1) * 10; // Piso 1 = 10; Piso 2 = 20; Piso 3 = 30
        int numero = 1;
        for (int j = 0; j < edificio->departamentos; j++) {
            edificio->edificio[i][j].numero = base + numero; // Piso 1: 10 + 1 = 11; Piso 2: 20 + 1 = 21; Piso 3: 30 + 1 = 31
            edificio->edificio[i][j].superficie = 0;
            edificio->edificio[i][j].valorUF = 0;
            numero++;
        }
    }
}

void imprimirEdificio(Edificio *edificio) {
    printf("Edificio:\n");
    for (int piso = 0; piso < edificio->pisos; piso++) {
        printf("== Piso %d ==\n", piso + 1);
        for (int departamento = 0; departamento < edificio->departamentos; departamento++) {
            printf("- Departamento #%d\n", edificio->edificio[piso][departamento].numero);
            printf("\t|-- Superficie: %d m2\n", edificio->edificio[piso][departamento].superficie);
            printf("\t|-- Valor: %d UF\n", edificio->edificio[piso][departamento].valorUF);
        }
        printf("\n");
    }
}
