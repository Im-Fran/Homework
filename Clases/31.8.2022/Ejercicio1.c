/*
 * Created by Francisco Solis Maturana on 31-8-2022
 */

#include <stdio.h>
#include <math.h>

int cuenta(int *r) {
    int num = *r, i = 0;
    while(num%10 != 0) {
        num = num/10;
        i++;
    }
    return i;
}

void conversion(int *p, int *q) {
    printf("=======\n");
    int u1, u2, p1, p2, d1, d2;
    u1 = *p%10;
    u2 = *q%10;

    d1 = sizeof *p;
    d2 = sizeof *q;

    p1 = *p /(pow(10, d1));
    p2 = *q /(pow(10, d2));

//    *p = *p - u1 + p2;
//   *q = *q - u2 + p1;
    *p = *p - p1*(pow(10, d1)) + u2*(pow(10, d1));
    *q = *q - p2*(pow(10, d2)) + u1*(pow(10, d2));

    printf("p=%d\nq=%d", *p,*q);
}

int intercambiar(int *a, int *b){
    int cantidadA = cuenta(a), cantidadB = cuenta(b);
    if(cantidadA%2 == 0 || cantidadB%2 == 0) {
        printf("La cantidad de numeros debe ser impar! Cantidad de a: %d, Cantidad de b: %d", cantidadA, cantidadB);
        return 0;
    }
    printf("%d=%d;\n", cantidadA, cantidadB);
    int centroA = *a % (pow(10, cantidadB%2)), centroB = *b % (pow(10, cantidadB%2));
    printf("%d\n%d", centroA, centroB);
}



int main() {
    int a = 178549, b = 3264;
    //conversion(&a,&b);
    a = 37892;
    b = 143;
    intercambiar(&a,&b);
}