/**
 * Created by Francisco Solis on 29-08-2022
 *
 * Implementar una funcion que ordene los valores distintos de 2 variables enteras a (*p), b (*q) dejando en a el menor y en b el mayor
 */

#include <stdio.h>

void ordenar(int *p, int *q){
    int aux;
    if(*p > *q){
        aux = *p;
        *p = *q;
        *q = aux;
    }

    printf("a: %d\nb: %d\n", *p, *q);
}

int main(){
    int a = 0, b = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &a);
    printf("Ingrese otro numero: ");
    scanf("%d", &b);
    ordenar(&a, &b);
}