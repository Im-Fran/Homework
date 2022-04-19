/*
 * Created by Francisco Solis Maturana on 19-04-22.
 *
 * Escribe un programa que permita el ingreso de 2 números cualquiera, y a partir de los números ingresados, escriba las 4 operaciones basicas matematicas con funciones (+,-,*,/).
 */

#include <stdio.h>

int suma(int x, int y) { return x + y; }

int resta(int x, int y) { return x - y; }

int multiplica(int x, int y) { return x * y; }

float divide(int x, int y) { return (x * 1.0) / (y * 1.0); }

int main() {
    // Declaración de variables
    int x, y;

    printf("Ingresa el primer número: ");
    scanf("%d", &x);
    printf("Ingresa el segundo número: ");
    scanf("%d", &y);

    // Calculo de operaciones
    printf("\n\nEl resultado de la suma %d+%d = %d", x, y, suma(x, y));
    printf("\nEl resultado de la resta %d-%d = %d", x, y, resta(x, y));
    printf("\nEl resultado de la multiplicación %d*%d = %d", x, y, multiplica(x, y));
    printf("\nEl resultado de la división %d/%d = %.2f", x, y, divide(x, y));

    char res;
    printf("\n\nDeseas reiniciar el programa? (s/n): ");
    scanf(" %s", &res);
    if(res == 's'){
        return main();
    }
    return 0;
}