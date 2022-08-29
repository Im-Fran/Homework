/*
 * Created by Francisco Solis Maturana on 8/29/2022.
 *
 * Implementar una funcion que intercambie los digitios del penultimo y ultimo de un numero entero n>100; el entero 7601 debe convertirse en 7610
 */

#include <stdio.h>

void intercambiar(int *a){
    int aux = (*a) % 100;
    *a = (*a) - aux + (((aux % 10) * 10) + (aux / 10));

    printf("Nuevo número: %d\n", *a);
}

int main(){
    int a = 0;
    do {
        printf("Ingrese un numero mayor a 100: ");
        scanf("%d", &a);
    } while (a < 100);

    intercambiar(&a);
}
