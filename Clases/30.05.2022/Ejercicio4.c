/**
 * Created by Francisco Solis at 2022-05-30
 * 
 * Un teatro otorga descuentos segun la edad del cliente, se pide determinar la cantidad de dinero que el teatro deja
 * de percibir por cada uno de las categorías. Tomar en cuenta que los niños menores a 5 años no pueden entrar al teatro
 * y que existe un precio único en la entrada al teatro. Los descuentos se hacen tomando en cuenta los siguientes datos:
 * 
 * - Categoria 1 > de 5 a 17 años > 30% de descuento
 * - Categoria 2 > de 18 a 25 años > 20% de descuento
 * - Categoria 3 > de 26 a 49 años > 25% de descuento
 * - Categoria 4 > de 50 años y más > 35% de descuento
 * 
 * Además se pide determinar la menor y mayor edad de los asistentes al teatro con dos funciones distintas. Y
 * el promedio de edad de asistentes al teatro.
 * Solicite precioo de la entrada al teatro.
 * Solicite la edad de cada asistente si se ingresa una edad menor a 1 se termina el ingreso de asistentes al teatro.
 */

#include <stdio.h>

int menorEdad(int edad, int menor){
    return menor == 0 || edad < menor ? edad : menor;
}

int mayorEdad(int edad, int mayor){
    return mayor == 0 || edad > mayor ? edad : mayor; 
}

int solicitarEdad(){
    int edad;
    printf("Ingrese la edad del asistente: ");
    scanf("%d", &edad);
    return edad;
}

int main(){
    int edad = 0, menor = 0, mayor = 0, asistentes = 0;
    float precio = 0.0, descuento = 0.0, cat1 = 0.0, cat2 = 0.0, cat3 = 0.0, cat4 = 0.0, promedioEdades = 0.0;

    printf("Ingrese el precio de la entrada al teatro: ");
    scanf("%f", &precio);

    while((edad = solicitarEdad()) > 0){
        if(edad < 5 || edad > 135){
            printf("No puede entrar al teatro\n");
        }else if(edad >= 5 && edad <= 17){
            descuento = precio * 0.3;
            cat1 += descuento;
            printf("El precio de la entrada es: %.2f\n", precio - descuento);
        }else if(edad >= 18 && edad <= 25){
            descuento = precio * 0.2;
            cat2 += descuento;
            printf("El precio de la entrada es: %.2f\n", precio - descuento);
        }else if(edad >= 26 && edad <= 49){
            descuento = precio * 0.25;
            cat3 += descuento;
            printf("El precio de la entrada es: %.2f\n", precio - descuento);
        }else if(edad >= 50){
            descuento = precio * 0.35;
            cat4 += descuento;
            printf("El precio de la entrada es: %.2f\n", precio - descuento);
        }

        if(edad >= 5){
            menor = menorEdad(edad, menor);
            mayor = mayorEdad(edad, mayor);

            promedioEdades += ((float) edad);

            asistentes++;
        }
    }

    printf("\n\n\n==============================\n");
    printf("La menor edad es: %d\n", menor);
    printf("La mayor edad es: %d\n", mayor);
    printf("El promedio de edades es: %.2f\n", promedioEdades / ((float) asistentes));
    printf("El total de descuentos de la categoria 1 es: %.2f\n", cat1);
    printf("El total de descuentos de la categoria 2 es: %.2f\n", cat2);
    printf("El total de descuentos de la categoria 3 es: %.2f\n", cat3);
    printf("El total de descuentos de la categoria 4 es: %.2f\n", cat4);

    return 0;
}