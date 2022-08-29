/*
 * Created by Francisco Solis Maturana on 8/29/2022.
 *
 * Implementar una funcion que intercambie los digitios del extremo derecho de dos numeros naturales a, b, es decir,
 * si inicialmente a=4567 y b=13952, finalmente a=4562 y b=13957.
 */

#include <stdio.h>

void intercambiar(int *a, int *b){
    int digito_a = (*a)%10;
    int digito_b = (*b)%10;
    *a = (*a) - digito_a + digito_b;
    *b = (*b) - digito_b + digito_a;
    printf("a: %d\nb: %d\n", *a, *b);
}

int main(){
    int a = 4567, b = 13952;
    intercambiar(&a, &b);
}
