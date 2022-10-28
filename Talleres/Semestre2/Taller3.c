/*
 * Created by Francisco Solis and Benjamín Farías on 28-10-2022.
 * Video: https://youtu.be/Y_WBSy4zWm4
 */

#include <stdio.h>
#include <string.h>

typedef char cadena[16];

void flushInput() { // Limpia el caché del scanf (lo que puede causar loop infinito si por ejemplo esperas un int e ingresas un char)
    char c = '0';
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void crearCadena(cadena c);

void protegerCadena(cadena c);

void desprotegerCadena(cadena c);

void mostrarCadena(cadena c);

int esValida(cadena c);

int main() {
    int opcion;
    cadena c;
    do {
        // Menu de Opciones
        printf("\n\nMenú de opciones: \n");
        printf("1. Crear cadena \n");
        printf("2. Proteger cadena \n");
        printf("3. Desproteger cadena \n");
        printf("4. Salir \n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        flushInput(); // Para evitar errores
        switch (opcion) {
            case 1: // Crear cadena
                crearCadena(c);
                mostrarCadena(c);
                break;
            case 2: // Proteger cadena
                mostrarCadena(c);
                protegerCadena(c);
                mostrarCadena(c);
                break;
            case 3: // Desproteger cadena
                mostrarCadena(c);
                desprotegerCadena(c);
                mostrarCadena(c);
                break;
            case 4: // Salir
                printf("Saliendo del programa... \n");
                break;
            default: // Opcion invalida
                printf("Opción inválida \n");
                break;
        }
    } while (opcion != 4);
    return 0;
}

void crearCadena(cadena c) {
    do {
        printf("\nIngrese una cadena de 8 a 16 caracteres (Solo mayúsculas y minúsculas!): ");
        fgets(c, 16, stdin);
    } while (!esValida(c)); // Mientras no sea valida, pedir de nuevo
}

int esValida(cadena c) {
    if(strlen(c) < 8 || strlen(c) > 16) { // Si la longitud es menor a 8 o mayor a 16, no es válida
        printf("La cadena debe tener entre 8 y 16 caracteres!\n");
        return 0;
    }

    for(int i = 0; i < strlen(c)-1; i++) { // Se resta 1 para no contar el \0
        if (c[i] < 65 || c[i] > 90 && c[i] < 97 || c[i] > 122) { // Si el character no es una letra, no es válida
            printf("La cadena solo puede contener letras!\n");
            return 0;
        }
    }

    return 1;
}

void protegerCadena(cadena c) {
    printf("\nProtegiendo...");
    for (int i = 0; i < strlen(c); i++) {
        int original = ((int) c[i]); // Obtener numero de la tabla ascii
        int protegido = original + 8;
        // Revisa si es mayúscula
        if (original >= 65 && original <= 90) {
            // Revisa si el numero es mayor a 90
            if (protegido > 90) {
                protegido = protegido - 26;
            }
        } else if (original >= 97 && original <= 122) {  // Es minúscula
            // Revisa si el numero es mayor a 122
            if (protegido > 122) {
                protegido = protegido - 26;
            }
        }

        c[i] = (char) protegido;
    }
}

void desprotegerCadena(cadena c) {
    printf("\nDesprotegiendo...");
    for (int i = 0; i < strlen(c); i++) {
        int protegido = ((int) c[i]); // Obtener numero de la tabla ascii
        int original = protegido - 8;
        // Revisa si es mayúscula
        if(protegido >= 65 && protegido <= 90) {
            // Revisa si el número es menor a 65
            if(original < 65) {
                original = original + 26; // Da la vuelta hasta el inicio de las letras mayúsculas
            }
        } else if(protegido >= 97 && protegido <= 122) { // Es minúscula
            // Revisa si el número es menor a 97
            if(original < 97) {
                original = original + 26; // Da la vuelta hasta el inicio de las letras minúsculas
            }
        }

        c[i] = (char) original;
    }
}

void mostrarCadena(cadena c) {
    printf("\nMuestra de cadena actual: %s", c); // %s para mostrar la cadena
}

