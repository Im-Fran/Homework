/*
 * Integrantes: Benjamín Farías y Francisco Solís
 *
 * 1. Función que retorne 1 si un número n es Encuadrado y 0 en caso contrario.
 *    - Número Encuadrado: aquel que termina con el cuadrado de su primer dígito. Por ejemplo, 78249.
 *
 * 2. Función que imprima cada número Disparado presente en el intervalo [2^12, 2^16].
 *    - Número Disparado: aquel número impar que comienza con un dígito par. Por ejemplo, 24785.
 *
 * 3. Función que retorne 1 si un número n es Sumariado y 0 en caso contrario.
 *    - Número Sumariado: aquel cuyos dígitos del extremo derecho representan la suma de todos sus dígitos. Por ejemplo, 476129.
 *
 * 4. Función que imprima cada número Inclinado presente en el intervalo [2^8, 2^16].
 *    - Número Inclinado: aquel cuyos dígitos están dispuestos en orden descendente de izquierda a derecha. Por ejemplo, 974310.
 *
 */
#include <stdio.h>
#include <math.h>
int largoDigito(int x) { // Calcula el largo de un dzsAigito, ej: 123456 tiene 6 digitos.
    int i = 1;
    while((x = x/10) > 0){
        i++;
    }
    return i;
}

int primerDigito(const int *x){ // Obtiene el primer digito de un puntero, por ejemplo en 214536424 el primer digito es 2.
    int primerDigito = *x;
    while(primerDigito > 9) {
        primerDigito = primerDigito/10;
    }
    return primerDigito;
}

int encuadrado(int *n){
    int d1 = primerDigito(n);                           // Obtener primer digito
    double cuadrado = pow(d1, 2);                    // El cuadrado del primer digito
    int largoCuadrado = largoDigito(((int) cuadrado));  // Cantidad de numeros en el cuadrado
    int cantidad = ((int) pow(10, largoCuadrado));   // Cantidad a dividir, por ejemplo:
                                                           // - primerDigito=3 => cuadrado=9 => cantidad=10
                                                           // - primerDigito=9 => cuadrado=81 => cantidad=100
                                            
    int ultimosNumeros = *n%cantidad;                      // Se obtiene los ultimos numeros para comparar
    return ultimosNumeros == cuadrado;                     // Revisar si los ultimos numeros son iguales al cuadrado del primero.
}

void disparado(){
    int desde = ((int) pow(2,12)), hasta = ((int) pow(2,16)), i = 0; // Desde 2^12 hasta 2^16
    printf("\nNúmeros 'disparado': ");
    while(desde <= hasta) {
        int d1 = primerDigito(&desde);
        int esPrimerDigitoPar = d1%2 == 0;
        int esImpar = (desde)%2 != 0;
        if(esPrimerDigitoPar && esImpar){
            printf("• %d\n", desde);
            i++;
        }
        desde++;
    }
    printf("En total son %d numeros 'Disparado'.", i);
}

int sumariado(const int *x) {
    int suma = 0; // Primero realizamos la suma
    int aux = *x; // Almacenamos los datos en la variable auxiliar.
    while(aux != 0) {
        suma += aux % 10; // Sumamos el ultimo digito
        aux = aux / 10; // Removemos el ultimo digito
    }
    int largoSuma = largoDigito(suma); // Obtenemos el largo del digito, ejemplo: 29 es 2.
    int n = ((int) pow(10, largoSuma)); // La cantidad para obtener los ultimos digitos, si la suma fuera 29, entonces 10^2 sería 100
    int ultimosDigitos = *x%n; // Obtiene los ultimos n digitos del numero para luego comparar

    return suma == ultimosDigitos;
}

void inclinado(){
    int n = 0;
    int desde = ((int) pow(2,8)), hasta = ((int) pow(2,16));
    int aux = 0; // Copia del numero original
    for(int i = desde; i <= hasta; i++) {
        aux = i;
        int ultimoDigito = aux%10; // Obtenemos el ultimo digito
        aux = aux/10; // Removemos el ultimo digito
        int esInclinado = 1; // Bandera para saber si es inclinado
        while(aux != 0) {
            int digito = aux%10; // Obtenemos el ultimo digito
            if(digito < ultimoDigito) { // Si el digito es mayor al ultimo digito, entonces no es inclinado
                esInclinado = 0;
                break;
            }

            // Si existe algun digito igual como 65532, entonces no es inclinado
            if(digito == ultimoDigito) {
                esInclinado = 0;
                break;
            }
            ultimoDigito = digito; // Actualizamos el ultimo digito
            aux = aux/10; // Removemos el ultimo digito
        }
        if(esInclinado) {
            printf("• %d\n", i);
            n++;
        }
    }

    printf("\nHay %d numeros 'Inclinado'", n);
}

int main() {
    printf("MENÚ Taller 1: ");
    printf("\n1. Ejercicio 1");
    printf("\n2. Ejercicio 2");
    printf("\n3. Ejercicio 3");
    printf("\n4. Ejercicio 4");
    int opcion = 0;
    do {
        printf("\nIngresa una opcion:");
        scanf("%d", &opcion);
    }while(opcion <= 0 || opcion > 4);
    
    if(opcion == 1){
        int n = 0;
        do {
            printf("\nIngresa un número:");
            scanf("%d", &n);
        } while(n <= 0);
        
        printf("\nEs 'Encuadrado'? R=%d", encuadrado(&n));
    } else if(opcion == 2){
        disparado();
    } else if(opcion == 3) {
        int n = 0;
        do {
            printf("\nIngresa un número:");
            scanf("%d", &n);
        } while(n <= 0);
        printf("\nEs 'Sumariado'? R=%d", sumariado(&n));
    } else if(opcion == 4){
        inclinado();
    } else {
        return 1;
    }
    return 0;
}