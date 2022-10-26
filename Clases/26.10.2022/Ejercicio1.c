/*
 * Created by Francisco Solis Maturana on 26/10/2022
 *
 * Se ha declarado:
 *
 * typedef char palabra[10];
 * typedef char texto[20];
 *
 * Implementar una funcion que retorne el indice de la palabra de mayor longitud que existe
 * entre las k cadenas de tipo palabra contenidas en un arreglo de tipo texto.
 */

#include <stdio.h>
#include <string.h>

typedef char palabra[10];
typedef palabra texto[20];

int indicePalabraMayorLongitud(texto arreglo, int k);

int main() {
    texto arreglo = {"Francisco", "Nicolás"};

    int indice = indicePalabraMayorLongitud(arreglo, 2);
    printf("La palabra de mayor longitud es: %s\n", arreglo[indice]);

    return 0;
}

int lenTexto(texto arreglo, int idx){
    return ((int) strlen(arreglo[idx]));
}

int indicePalabraMayorLongitud(texto arreglo, int k){
    int idx = 0;
    int len = lenTexto(arreglo, 0);
    for (int i = 0; i < k; i++){
        if (lenTexto(arreglo, i) > len){
            len = lenTexto(arreglo, i);
            idx = i;
        }
    }
    return idx;
}