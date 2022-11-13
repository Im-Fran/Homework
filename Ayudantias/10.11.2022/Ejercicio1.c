/*
 * Created by Francisco Solis Maturana on 10/11/2022.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n < 2) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    printf("Ingrese el numero de la serie de fibonacci que desea calcular: ");
    scanf("%d", &n);
    printf("El numero de la serie de fibonacci en la posicion %d es %d", n, fibonacci(n));
    return 0;
}