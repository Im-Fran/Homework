/*
    Integrante 1: Mauricio Reynoso
    Integrante 2: Francisco Solis
    Profesor(a): Freddy Marambio
    Sección: 1021
    Compilador utilizado: repl.it
*/

#include <stdio.h>

void flushInput() { // Limpia el cache del scanf (lo que puede causar loop infinito si por ejemplo esperas un int e ingresas un char)
    char c = '0';
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    printf("Bievenido a LollaPalooza!\n");
    printf("Ingresa la cantidad de asistentes (Ingresa un valor entero mayor a 0): ");
    int asistentes = 0;
    scanf("%d", &asistentes);
    // Ahora leer con strtol
    while (asistentes <= 0) { // En caso de que se ingrese un numero menor a 0
        flushInput();
        printf("Por favor ingresa un número mayor a 0: ");
        scanf("%d", &asistentes);
    }

    int identificador = 0, // Identificador de un asistente
    numeroDias = 0, // Cantidad de días que se estará (entre 1 y 3)
    edad = 0, // Edad del asistente
    contadorDias1 = 0, // Cantidad de personas que asisten 1 dia
    contadorDiasMenores1 = 0, // Cantidad de personas que asisten 1 dia para menores
    contadorDias2 = 0, // cantidad de personas que asisten 2 dias
    contadorDiasMenores2 = 0, // cantidad de personas que asisten 2 dias para menores
    contadorDias3 = 0,  // Cantidad de personas que asisten 3 dias
    contadorDiasMenores3 = 0,  // Cantidad de personas que asisten 3 dias para menores
    sumaEdad = 0 // Suma de las edades de los asistentes que van al evento por 2 dias
    ;

    float promedioAsistencia = 0.0, // Promedio de dias de asistencia
            promedioEdad = 0.0; // Promedio de edad de quienes van por 2 dias

    char respuesta; // Respuesta de si va con menor de edad

    int tempAsistentes = asistentes; // Variable temporal
    for (int i = 1; i <= tempAsistentes; i++) { // Loop por cada asistente

        // 1. Solicitar identificador
        printf("Ingresa un identificador para el asistente #%d (debe ser mayor a 0): ", i);
        scanf("%d", &identificador);
        while (identificador <= 0) { // En caso de que se ingrese un numero menor a 0
            flushInput();
            printf("Por favor ingresa un número mayor a 0: ");
            scanf("%d", &identificador);
        }

        // 2. Solicitar numero de días que se estará
        printf("\nCuantos días estará en el evento? (Ingresa un número entre 1 y 3): ");
        scanf("%d", &numeroDias);
        while (numeroDias < 1 || numeroDias > 3) { // Si el usuario ingresa un numero distinto a 1, 2 ó 3
            flushInput();
            printf("Por favor ingresa un número entre 1 y 3: ");
            scanf("%d", &numeroDias);
        }

        if (numeroDias == 1) {
            contadorDias1++;
        } else if (numeroDias == 2) {
            contadorDias2 += 2;
        } else {
            contadorDias3 += 3;
        }

        // 3. Solicitar la edad del asistente
        printf("\nCuál es la edad del asistente? (Ingresar un número entre 18 y 135): ");
        scanf("%d", &edad);
        while (edad < 18 || edad > 135) { // Si el usuario ingresa un numero menor a 18 o mayor a 135
            flushInput();
            printf("Por favor ingresa un número entre 18 y 135: ");
            scanf("%d", &edad);
        }

        if (numeroDias == 2) {
            sumaEdad += edad;
        }

        // 4. Preguntar si va acompañado de un menor de edad
        printf("Va acompañado de un menor de edad? (s/n): ");
        scanf(" %s", &respuesta);
        if(respuesta == 's') {
            asistentes++;
            // Solicitar identificador
            printf("Ingresa un identificador para el menor de edad (debe ser mayor a 0): ");
            scanf("%d", &identificador);
            while (identificador <= 0) { // En caso de que se ingrese un numero menor a 0
                flushInput();
                printf("Por favor ingresa un número mayor a 0: ");
                scanf("%d", &identificador);
            }

            // Solicitar cantidad de días a estar
            printf("\nCuantos días estará el menor de edad en el evento? (Ingresa un número entre 1 y 3): ");
            scanf("%d", &numeroDias);
            while (numeroDias < 1 || numeroDias > 3) { // Si el usuario ingresa un numero distinto a 1, 2 ó 3
                flushInput();
                printf("Por favor ingresa un número entre 1 y 3: ");
                scanf("%d", &numeroDias);
            }
    
            if (numeroDias == 1) {
                contadorDiasMenores1++;
            } else if (numeroDias == 2) {
                contadorDiasMenores2+=2;
            } else {
                contadorDiasMenores3+=3;
            }

            // preguntar la edad para estadisticas nadamas
            if (numeroDias == 2) {
                printf("\nCuál es la edad del asistente? (Ingresar un número entre 1 y 18): ");
                scanf("%d", &edad);
                while (edad < 1 || edad > 18) { // Si el usuario ingresa un numero menor a 1 o mayor a 18
                    flushInput();
                    printf("Por favor ingresa un número entre 1 y 18: ");
                    scanf("%d", &edad);
                }

                sumaEdad += edad;
            }
        }

        respuesta = 'n';

        printf("\n\n");
    }

    promedioAsistencia = (contadorDias1 + contadorDias2 + contadorDias3 + contadorDiasMenores1 + contadorDiasMenores2 + contadorDiasMenores3) / ((float) asistentes);
    promedioEdad = sumaEdad / ((float) asistentes);
    int recaudado = (contadorDias1 + contadorDias2 + contadorDias3 + contadorDiasMenores1 + contadorDiasMenores2 + contadorDiasMenores3) * 25000;

    printf("\n===============\n");
    printf("Promedio de dias de asistencia: %.2f", promedioAsistencia);
    if(contadorDias2 > 0){
        printf("\nPromedio de edad de quienes asistieron 2 días: %.2f", promedioEdad);
    }
    printf("\nRecaudación: $%d Pesos", recaudado);
    printf("\n===============\n");

    return 0;
}
