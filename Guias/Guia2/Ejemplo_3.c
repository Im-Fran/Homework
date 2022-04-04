/*
 * Created by Francisco Solis Maturana on 03-04-22.
 *
 * Escribir una función que calcule el valor de una cuenta de agua potable, dados el consumo en  metros  cúbicos  y  el  valor  del  metro  cúbico.  Por  consumos  superiores  a  100  metros cúbicos se aplica un recargo del 3% sobre el valor del consumo. Además, existe un impuesto del 12% sobre el valor del consumo.
 */


#include <stdio.h>

float valorCuenta(float metrosConsumidos, float valorMetro) {
    float consumo = metrosConsumidos * valorMetro;
    if (metrosConsumidos > 100.0f) {
        consumo += consumo * 0.03f;
    }

    return consumo + (consumo * 0.12f);
}

int main(){
    float metrosConsumidos, valorMetro;
    printf("Ingrese el valor del metro cúbico: ");
    scanf("%f", &valorMetro);
    printf("Ingrese el consumo en metros cúbicos: ");
    scanf("%f", &metrosConsumidos);
    printf("El valor de la cuenta es: %.2f", valorCuenta(metrosConsumidos, valorMetro));
    return 0;
}

