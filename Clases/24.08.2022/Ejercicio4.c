/*
 * Created by Francisco Solis at 2022-08-24
 * 
 * Implementar una funcion que simule el comportamiento de un reloj digital
 * desplegando hora, minutos y segundos de un día, desde las 00:00:00 horas hasta las 23:59:59 horas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reloj(){
    int hora = 0, minuto = 0, segundo = 0;
    while(hora < 24 && minuto < 60 && segundo < 60) {
        printf("%d:%d:%d\n", hora, minuto, segundo);
        segundo++;
        if(segundo == 60) {
            minuto++;
            segundo = 0;
        }

        if(minuto == 60) {
            hora++;
            minuto = 0;
        } 
        sleep(1);     
    }
}

int main(int argc, char const *argv[]) {
    reloj();
    
    return 0;
}