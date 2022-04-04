/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Muestra el antecesor y sucesor de un numero ingresado.
 */

#include <stdio.h>

int main(){
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("El antecesor de %d es %d y el sucesor es %d\n", numero, numero-1, numero+1);
    return 0;
}
