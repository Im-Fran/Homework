/*
 * Created by Francisco Solís y Benjamín Farías on 12/11/2022
 *
 * Un  edificio  consta  de  cierto  número  de  pisos  y  determinada  cantidad  de  departamentos  por  piso,  debido  a  lo  cual  se  utiliza  un
 * arreglo bidimensional para su representación. Como datos relevantes de un departamento se consideran el número, la superficie
 * en m2 y su valor en UF. El número de departamento es función de los índices de piso y departamento; por ejemplo, el departamento
 * 34  está  situado  en  el  tercer  piso  (índice  2),  cuarto  departamento  (índice  3).  Sin  embargo,  el  número  de  departamento  no  se
 * encuentra explícitamente asignado.
 *
 * - Definición de las estructuras de datos tanto de departamento como del edificio.
 * - Función que cree un edificio de tres pisos y cuatro departamentos por piso, sin asignar el número.
 * - Función que asigne el respectivo número a cada departamento del edificio.
 * - Función que despliegue en pantalla los datos de todos y cada uno de los departamentos del edificio.
 * - Programa principal que, mediante un menú, llame organizadamente a las funciones anteriores.
 * - Autodocumentación mediante un video explicativo de una de las funciones implementadas el cual no debe exceder los 3 minutos y debe contener rostro y voz.
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
    Departamento edificio[100][100]; // Arreglo bidimensional de departamentos
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
    int numero = 1;
    for (int i = 0; i < edificio->pisos; i++) {
        for (int j = 0; j < edificio->departamentos + 1; j++) { // Agrega uno para saltar el departamento
            if(j != 10) {
                edificio->edificio[i][j].numero = numero;
                edificio->edificio[i][j].superficie = 0;
                edificio->edificio[i][j].valorUF = 0;
            }
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
