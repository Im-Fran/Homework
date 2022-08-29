/*
 * Created by Francisco Solis Maturana on 29-08-2022.
 *
 * Implementar una funcion que rote, circularmente a la izquierda, los valores de 3 variables enteras
 * a, b y c, es decir, que deje el valor de c en b, el valor de b en a y el valor de a en c.
 */

#include <stdio.h>

void rotar(int *a, int *b, int *c){
    int aux = *a;
    *a = *b;
    *b = *c;
    *c = aux;
    printf("a: %d\nb: %d\nc: %d\n", *a, *b, *c);
}

int main(){
    int a = 0, b = 0, c = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &a);
    printf("Ingrese otro numero: ");
    scanf("%d", &b);
    printf("Ingrese otro numero: ");
    scanf("%d", &c);
    rotar(&a, &b, &c);
}
