/*
 * Created by Francisco Solis at 2022-08-24
 * 
 * Implementar una funcion que despliegue los primeros n terminos de la sucesion 3,6,18,72,360,2160 y 15120
 */
#include <stdio.h>
#include <math.h>

void imprime(int n) {
    int num = 0, x = 3, e = 1;
    for(int i = 1; i <= n; i++){
        num = x*e;
        printf("- %d\n", num);
        x = num;
        e++;
    }
}

int main(){
    printf("Cuantos numeros deseas ver?");
    int n = 0;
    scanf("%d", &n);
    imprime(n);
}