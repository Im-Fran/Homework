/*
 * Created by Francisco Solis Maturana on 31-08-2022
 *
 * Función que retorne 1 si un número n es Encuadrado y 0 en caso contrario. 
 * - Número Encuadrado: aquel que termina con el cuadrado de su primer dígito. Por ejemplo, 78249. 
 */
#include <stdio.h>
#include <math.h>

int largoDigito(int x) {
    int i = 1;
    while((x = x/10) > 0){
        i++;
    }
    return i;
}

int primerDigito(int *x){
    int primerDigito = *x;
    while((primerDigito = primerDigito/10) > 9);
    return primerDigito;
}

int encuadrado(int *n){
    int d1 = primerDigito(n);
    int cuadrado = pow(d1, 2);                  // El cuadrado del primer digito
    int largoCuadrado = largoDigito(cuadrado);  // Cantidad de numeros en el cuadrado
    int cantidad = pow(10, largoCuadrado);      // Cantidad a dividir, por ejemplo:
                                                // - primerDigito=3 => cuadrado=9 => cantidad=10
                                                // - primerDigito=9 => cuadrado=81 => cantidad=100
                                            
    int ultimosNumeros = *n%cantidad;           // Se obtiene los ultimos numeros para comparar
    return ultimosNumeros == cuadrado;
}

void disparado(){
    int desde = 4096, hasta = 131072, i = 0;; // Desde 2^12 hasta 2^16
    printf("\nNúmeros 'disparado': ");
    printf("%d,%d\n", desde, hasta);
    while(desde <= hasta) {
        int d1 = primerDigito(&desde);
        int esPrimerDigitoPar = d1%2 == 0;
        int esImpar = (desde)%2 != 0;
        if(esPrimerDigitoPar && esImpar){
            printf("• %d\n", desde);
        }
        desde++;
        i++;
    }
    printf("En total son %d numeros 'Disparado'.", i);
}

int main() {
    printf("MENÚ Taller 1: ");
    printf("\n1. Ejercicio 1");
    printf("\n2. Ejercicio 2");
    int opcion = 0;
    do {
        printf("\nIngresa una opcion:")
        scanf("%d", &opcion);
    }while(opcion <= 0 || opcion > 2);
    
    if(opcion == 1){
        int n = 0;
        do {
        printf("\nIngresa un número:");
        scanf("%d", &n);
        } while(n <= 0);
        
        printf("\nEs encuadrado? R=%d", encuadrado(&n));
    } else if(opcion == 2){
        disparado();
    }
    return 0;
}