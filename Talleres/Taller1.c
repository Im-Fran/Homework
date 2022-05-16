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
        contadorDias2 = 0, // cantidad de personas que asisten 2 dias
        contadorDias3 = 0,  // Cantidad de personas que asisten 3 dias
        sumaEdad = 0, // Suma de las edades de los asistentes que van al evento por 2 dias
        idMenor = 0, // Identificador de la persona con menor edad
        edadMenor = 0, // La menor edad entre todas las personas
        asistentesA2Dias = 0 // Cantidad de personas que asisten 2 días
    ;

    float promedioAsistencia = 0.0, // Promedio de dias de asistencia
            promedioEdad = 0.0; // Promedio de edad de quienes van por 2 dias

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
        printf("Cuantos días estará en el evento? (Ingresa un número entre 1 y 3): ");
        scanf("%d", &numeroDias);
        while (numeroDias < 1 || numeroDias > 3) { // Si el usuario ingresa un numero distinto a 1, 2 ó 3
            flushInput();
            printf("Por favor ingresa un número entre 1 y 3: ");
            scanf("%d", &numeroDias);
        }

        if (numeroDias == 1) {
            contadorDias1++; // Incrementa en 1 el contadorDias1
        } else if (numeroDias == 2) {
            contadorDias2 += 2; // incrementa en 2 el contadorDias2
        } else {
            contadorDias3 += 3; // incrementa en 3 el contadorDias3
        }

        // 3. Solicitar la edad del asistente
        printf("Cuál es la edad del asistente? (Ingresar un número entre 1 y 135): ");
        scanf("%d", &edad);
        while (edad < 1 || edad > 135) { // Si el usuario ingresa un numero menor a 1 o mayor a 135
            flushInput();
            printf("Por favor ingresa un número entre 1 y 135: ");
            scanf("%d", &edad);
        }

        if (numeroDias == 2) {
            sumaEdad += edad;
            asistentesA2Dias++;
        }

        if(edad < edadMenor || edadMenor == 0) {
            idMenor = identificador;
            edadMenor = edad;
        }

        printf("\n\n");
    }

    promedioAsistencia = (contadorDias1 + contadorDias2 + contadorDias3) / ((float) asistentes);
    promedioEdad = sumaEdad / ((float) asistentesA2Dias);
    int recaudado = (contadorDias1 + contadorDias2 + contadorDias3) * 25000;

    printf("\n===============\n");
    printf("Promedio de dias de asistencia: %.2f", promedioAsistencia);
    if(contadorDias2 > 0){
        printf("\nPromedio de edad de quienes asistieron 2 días: %.2f", promedioEdad);
    }
    printf("\nRecaudación: $%d Pesos", recaudado);
    printf("\nLa persona de menor edad tiene ID: %d y su edad es %d", idMenor, edadMenor);
    printf("\n===============\n");

    return 0;
}

