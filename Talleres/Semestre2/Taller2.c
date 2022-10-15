/**
 * Created by Francisco Solis Maturana on 14-10-2022.
 *
 *  - Número Descuadrado: aquel que empieza con el cuadrado de su último dígito. Por ejemplo, 493827
 *  - Número Reparado: aquel número par que comienza con un dígito impar. Por ejemplo, 347216.
 *
 * A partir de lo anteriormente expresado se pide desarrollar, en lenguaje de programación C,
 * una aplicación que cumpla, a lo menos, con lo que a continuación se indica:
 *
 * - Definicion de la estructura de datos adecuada.
 * - Función que determine si un número natural es descuadrado.
 * - Función que determine si un número natural es reparado.
 * - Función que cree un arreglo con los primeros n ≤ 20 números descuadrados.
 * - Función que cree un arreglo con los primeros n ≤ 20 números reparados.
 * - Función que despliegue en pantalla los n elementos un arreglo. Usarla para ver los dos arreglos creados.
 * - Programa principal que, mediante un menú, llame organizadamente a las funciones anteriores.
 */

#include <stdio.h>
#include <math.h>

// Definir arreglo de tamaño 20
typedef int arreglo[20];

// Función que determine si un número natural es descuadrado.
int esDescuadrado(int n) {
    int largoNumero = 0, // Largo del numero para obtener los primeros digitos
        largoCuadrado = 0, // Largo del cuadrado para obtener los primeros digitos
        aux = n, // Auxiliar para calcular largos
        ultimoDigito = n % 10; // Ultimo digito
    int cuadradoUltimoDigito = ((int) pow(ultimoDigito, 2)); // Cuadrado del ultimo digito
    if(cuadradoUltimoDigito == 0 && n != 0) { // Si el cuadrado es 0 y n != 0 significa que no es descuadrado
        return 0;
    }

    while(aux > 0) {
        aux /= 10;
        largoNumero++;
    }

    aux = cuadradoUltimoDigito;
    while(aux > 0) {
        aux /= 10;
        largoCuadrado++;
    }

    int primerosDigitos = n / ((int) pow(10, largoNumero - largoCuadrado));
    if(primerosDigitos == n) { // Esto pasa en casos como el 25, que el calculo sería 25/ 10^0 = 25 / 1 = 25, por lo que se debe hacer una excepción
        return 0;
    }
    return primerosDigitos == cuadradoUltimoDigito ? 1 : 0;
}

// Función que determine si un número natural es reparado.
int esReparado(int n) {
    int primerDigito = 0, aux = n;
    while(aux > 0) { // Loop que obtiene el primer digito del número
        primerDigito = aux % 10;
        aux /= 10;
    }

    return (n % 2 == 0 && primerDigito % 2 != 0) ? 1 : 0; // Si n es par y parte con un dígito impar
}

// Función que cree un arreglo con los primeros n ≤ 20 números descuadrados.
void numerosDescuadrados(arreglo *numeros, int *n) {
    printf("Ingrese la cantidad de numeros descuadrados a generar: ");
    scanf("%d", n);
    if(*n > 20) {
        printf("El numero ingresado es mayor a 20, se generaran 20 numeros descuadrados");
        *n = 20;
    }

    if (*n < 1) {
        printf("El numero ingresado es menor a 1, se generaran 1 numero descuadrado");
        *n = 1;
    }
    int i = 0, // Contador para loop
        j = 10; // Numero que debe ser descuadrado (comienza del 10 para obtener numeros de 2 digitos o más)
    while(i < *n) {
        if(esDescuadrado(j) == 1) {
            *numeros[i] = j;
            i++;
        }
        j++;
    }
}

// Función que cree un arreglo con los primeros n ≤ 20 números reparados.
void numerosReparados(arreglo *numeros, int *n) {
    printf("Ingrese la cantidad de numeros reparados a generar: ");
    scanf("%d", n);
    if(*n > 20) {
        printf("El numero ingresado es mayor a 20, se generaran 20 numeros reparados");
        *n = 20;
    }

    if (*n < 1) {
        printf("El numero ingresado es menor a 1, se generaran 1 numero reparado");
        *n = 1;
    }

    int i = 0, // Contador para loop
        j = 0; // Numero que debe ser reparado
    while(i < *n) {
        if(esReparado(j) == 1) {
            *numeros[i] = j;
            i++;
        }
        j++;
    }
}

// Función que despliegue en pantalla los n elementos un arreglo. Usarla para ver los dos arreglos creados.
void imprimirArreglo(arreglo *numeros, int n) {
    for(int i = 0; i < n; i++) {
        printf("\n%d. %d", i + 1, *numeros[i]);
    }
}

/*
 * Funcion main que muestre el siguiente menú
 * 1. Determinar si un número es descuadrado
 * 2. Determinar si un número es reparado
 * 3. Generar los primeros n números descuadrados
 * 4. Generar los primeros n números reparados
 * 5. Salir
 */
int main() {
    int opcion = 0;
    do {
        printf("\n\n\n\n\n\n\n");
        printf("\n1. Determinar si un número es descuadrado");
        printf("\n2. Determinar si un número es reparado");
        printf("\n3. Generar los primeros n números descuadrados");
        printf("\n4. Generar los primeros n números reparados");
        printf("\n5. Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        if(opcion == 1) {
            int numero = 0;
            printf("Ingrese un numero: ");
            scanf("%d", &numero);
            if(esDescuadrado(numero) == 1) {
                printf("El numero %d es descuadrado", numero);
            } else {
                printf("El numero %d no es descuadrado", numero);
            }
            return 0;
        } else if(opcion == 2) {
            int numero = 0;
            printf("Ingrese un numero: ");
            scanf("%d", &numero);
            if(esReparado(numero) == 1) {
                printf("El numero %d es reparado", numero);
            } else {
                printf("El numero %d no es reparado", numero);
            }
            return 0;
        } else if(opcion == 3) {
            arreglo numeros;
            int buscados = 0;
            numerosDescuadrados(&numeros, &buscados);
            printf("\nNumeros encontrados:\n");
            imprimirArreglo(&numeros, buscados);
            return 0;
        } else if(opcion == 4) {
            arreglo numeros;
            int buscados = 0;
            numerosReparados(&numeros, &buscados);
            printf("\nNumeros encontrados:\n");
            imprimirArreglo(&numeros, buscados);
            return 0;
        }
    } while(opcion != 5);

    return 0;
}
