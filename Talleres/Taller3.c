/*
    Integrante: Francisco Solis
    Profesor(a): Fredy Marambio
    Sección: 304
    Compilador utilizado: onlinegdb.coms
*/

#include <stdio.h>

void flushInput() { // Limpia el cache del scanf (lo que puede causar loop infinito si por ejemplo esperas un int e ingresas un char)
    char c = '0';
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int obtenerEdad() { // Obtiene la edad de una persona
    int edad = 0;
    printf("Ingresa la edad de la persona: ");
    scanf("%d", &edad);
    while (edad < 0) { // En caso de que se ingrese un numero menor a 0
        flushInput();
        printf("Por favor ingresa un número mayor o igual a 0: ");
        scanf("%d", &edad);
    }
    return edad;
}

float obtenerPeso() { // Obtiene el peso de una persona
    float peso = 0;
    printf("Ingresa el peso de la persona (en kilos): ");
    scanf("%f", &peso);
    while(peso < 0.0) {
        flushInput();
        printf("Por favor ingresa un número mayor a 0: ");
        scanf("%f", &peso);
    }
    return peso;
}

float obtenerEstatura() {// Obtiene la estatura de una persona
    float estatura = 0;
    printf("Ingresa la estatura de la persona (en centímetros): ");
    scanf("%f", &estatura);
    while(estatura < 0.0) {
        flushInput();
        printf("Por favor ingresa un número mayor a 0: ");
        scanf("%f", &estatura);
    }
    return estatura;
}

float calculoIMC(float peso, float estatura) { // Calculo de IMC
    float estaturaEnMetros = estatura / 100;
    return peso / (estaturaEnMetros * estaturaEnMetros);
}

int main() {
    printf("Bienvenido al muestreo de personas :)\n");
    printf("Ingresa la cantidad de personas: ");
    int personas = 0;

    /* Niños (0-12) */
    int cantidadNinios = 0; // Cantidad de niños
    float pesoNinios = 0; // Peso promedio de los niños
    float pesoMin = 0; // Peso mínimo de los niños
    float pesoMax = 0; // Peso máximo de los niños
    /* Jovenes (13-29) */
    int cantidadJovenes = 0; // Cantidad de jóvenes
    float pesoJovenes = 0; // Peso promedio de los jóvenes
    float pesoMinJovenes = 0; // Peso mínimo de los jóvenes
    float pesoMaxJovenes = 0; // Peso máximo de los jóvenes
    /* Adultos (30-64) */
    int cantidadAdultos = 0; // Cantidad de adultos
    float pesoAdultos = 0; // Peso promedio de los adultos
    float pesoMinAdultos = 0; // Peso mínimo de los adultos
    float pesoMaxAdultos = 0; // Peso máximo de los adultos
    /* Ancianos (65-mayor) */
    int cantidadAncianos = 0; // Cantidad de ancianos
    float pesoAncianos = 0; // Peso promedio de los ancianos
    float pesoMinAncianos = 0; // Peso mínimo de los ancianos
    float pesoMaxAncianos = 0; // Peso máximo de los ancianos

    // Categorias de Riesgo

    /* Bajo */
    int cantidadBajo = 0; // Cantidad de personas de bajo riesgo
    int porcentajeBajo = 0; // Porcentaje de las personas de bajo riesgo en comparación con las personas totales

    /* Medio */
    int cantidadMedio = 0; // Cantidad de personas de medio riesgo
    int porcentajeMedio = 0; // Porcentaje de las personas de medio riesgo en comparación con las personas totales

    /* Alto */
    int cantidadAlto = 0; // Cantidad de personas de alto riesgo
    int porcentajeAlto = 0; // Porcentaje de las personas de alto riesgo en comparación con las personas totales

    scanf("%d", &personas);
    for(int i = 0; i < personas; i++) {
        printf("\n> Vamos a calcular el IMC de la persona #%d:\n", i + 1);
        int edad = obtenerEdad();
        float peso = obtenerPeso();
        float estatura = obtenerEstatura();
        float imc = calculoIMC(peso, estatura);
        char *riesgo = "";
        if(imc < 22.0) {
            if(edad < 45) {
                riesgo = "Bajo";
                cantidadBajo++;
            } else {
                riesgo = "Medio";
                cantidadMedio++;
            }
        } else {
            if(edad < 45) {
                riesgo = "Medio";
                cantidadMedio++;
            } else {
                riesgo = "Alto";
                cantidadAlto++;
            }
        }

        printf(">> IMC: %.1f\n", imc);
        printf(">> Riesgo de enfermedades coronarias: %s\n\n", riesgo);

        if(edad >= 0 && edad <= 12) {
            cantidadNinios++;
            pesoNinios += peso;
            if(pesoMin == 0 || peso < pesoMin) {
                pesoMin = peso;
            }
            if(pesoMax == 0 || peso > pesoMax) {
                pesoMax = peso;
            }
        } else if (edad >= 13 && edad <= 29) {
            cantidadJovenes++;
            pesoJovenes += peso;
            if(pesoMinJovenes == 0 || peso < pesoMinJovenes) {
                pesoMinJovenes = peso;
            }
            if(pesoMaxJovenes == 0 || peso > pesoMaxJovenes) {
                pesoMaxJovenes = peso;
            }
        } else if (edad >= 30 && edad <= 64) {
            cantidadAdultos++;
            pesoAdultos += peso;
            if(pesoMinAdultos == 0 || peso < pesoMinAdultos) {
                pesoMinAdultos = peso;
            }
            if(pesoMaxAdultos == 0 || peso > pesoMaxAdultos) {
                pesoMaxAdultos = peso;
            }
        } else if (edad >= 65) {
            cantidadAncianos++;
            pesoAncianos += peso;
            if(pesoMinAncianos == 0 || peso < pesoMinAncianos) {
                pesoMinAncianos = peso;
            }
            if(pesoMaxAncianos == 0 || peso > pesoMaxAncianos) {
                pesoMaxAncianos = peso;
            }
        }
    }

    porcentajeBajo = (cantidadBajo * 100) / personas;
    porcentajeMedio = (cantidadMedio * 100) / personas;
    porcentajeAlto = (cantidadAlto * 100) / personas;

    pesoNinios = pesoNinios / ((float) cantidadNinios);
    pesoJovenes = pesoJovenes / ((float) cantidadJovenes);
    pesoAdultos = pesoAdultos / ((float) cantidadAdultos);

    printf("\t\t ** TABLA DE ESTADISTICAS (IMC) **\n");
    printf("\t\t   > Tamaño de la muestra: %d <\n\n", personas);
    printf("Categoria \t Cantidad \t Peso Promedio \t Peso Min. \t Peso Max.\n");
    printf("Niños \t\t %d \t\t %.1f \t\t %.1f \t\t %.1f\n", cantidadNinios, pesoNinios, pesoMin, pesoMax);
    printf("Jovenes \t %d \t\t %.1f \t\t %.1f \t\t %.1f\n", cantidadJovenes, pesoJovenes, pesoMinJovenes, pesoMaxJovenes);
    printf("Adultos \t %d \t\t %.1f \t\t %.1f \t\t %.1f\n", cantidadAdultos, pesoAdultos, pesoMinAdultos, pesoMaxAdultos);
    printf("Ancianos \t %d \t\t %.1f \t\t %.1f \t\t %.1f\n\n", cantidadAncianos, pesoAncianos, pesoMinAncianos, pesoMaxAncianos);

    printf("\t ** TABLA DE ESTADISTICAS (ENFERMEDADES CORONARIAS) **\n");
    printf("Categoria \t Cantidad \t Porcentaje\n");
    printf("Bajo \t\t %d \t\t %d%%\n", cantidadBajo, porcentajeBajo);
    printf("Medio \t\t %d \t\t %d%%\n", cantidadMedio, porcentajeMedio);
    printf("Alto \t\t %d \t\t %d%%\n", cantidadAlto, porcentajeAlto);
}