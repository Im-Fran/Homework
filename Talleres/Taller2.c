/* 
    Integrante 1: Mauricio Reynoso
    Integrante 2: Francisco Solis
    Profesor(a): Fredy Marambio
    Sección: 304
    Compilador utilizado: repl.it
*/


#include <stdio.h>
#include <ctype.h> 

void flushInput() { // Limpia el cache del scanf (lo que puede causar loop infinito si por ejemplo esperas un int e ingresas un char)
  char c = '0';
  while ((c = getchar()) != '\n' && c != EOF) {}
}

int solicitarRut() {
	int rut = 0;
	// Pedir el rut
	printf("Ingrese el rut del paciente: ");
    scanf("%d",&rut);
    while (rut < 0) { // En caso de que se ingrese un numero menor a 0
        flushInput();
        printf("Error... Ingrese un rut valido: ");
        scanf("%d", &rut);
    }

	return rut;
}

// Funcion float que entrega el % de pacientes detectados con COVID19, respecto del total de pacientes, debiendo recibir como parámetros las dos variables necesarias para el cálculo.
float porcentajePacientes(int pacientesTotales, int pacientesDetectados) {
    // Usando regla de 3 y un porcentaje de 0 a 100
    return (((float)pacientesDetectados) * 100.0) / ((float)pacientesTotales);
}


// Funcion void que imprima por pantalla el rango de temperatura alcanzado por los pacientes con COVID19, desplegando los siguientes datos del paciente con mayor y menor temperatura.
void imprimirEnPantalla(int rutMa, int edadMa, char sexoMa, float temperaturaMa, int rutMe, int edadMe, char sexoMe, float temperaturaMe, float porcentajePacientesConCovid, int hombreConCovid, int mujeresMayores40Covid) {
    printf("\nPaciente con mayor temperatura (rut, edad, sexo, temperatura): %d, %d, %c, %.2f\n", rutMa, edadMa, sexoMa, temperaturaMa);
    printf("Paciente con menor temperatura (rut, edad, sexo, temperatura): %d, %d, %c, %.2f\n", rutMe, edadMe, sexoMe, temperaturaMe);
    printf("Porcentaje de pacientes con COVID19: %.2f\n", porcentajePacientesConCovid);
    printf("Cantidad de hombres con COVID19: %d\n", hombreConCovid);
    printf("Cantidad de mujeres con COVID19 mayores de 40 años: %d\n", mujeresMayores40Covid);
}

int main() {
  
    int rut = 0, // Si es 0 terminamos
		edad = 0, // Porfis mayor de 0
		tieneCovid = 0, // 1 para si, 0 para no
		contadorSexoM = 0,  // Contador de hombres con covid
		contadorSexoF40 = 0, // Pacientes mujeres mayores de 40 con covid
        pacientes = 0, // Cantidad de pacientes totales
        pacientesCovid = 0, // Cantidad de pacientes con covid
        rutMa = 0, edadMa = 0, sexoMa = 0, temperaturaMa = 0, // Variables para el paciente con mayor temperatura
        rutMe = 0, edadMe = 0, sexoMe = 0, temperaturaMe = 0; // Variables para el paciente con menor temperatura
    float temperatura = 0.0; // Temperatura del paciente
    char sexo = 'n';

    while((rut = solicitarRut()) > 0){
		// Solicitar el sexo
		printf("Ingrese su sexo [m/f]: ");
		scanf(" %s", &sexo);
		sexo = tolower(sexo); // Hacer minuscula para evitar exceso de checkeo
		while(sexo != 'f' && sexo != 'm'){ // Si no es f o m pedir de nuevo hasta que sea uno de los dos
			flushInput();
			printf("Ingrese un sexo valida... [m/f]: ");
			scanf(" %s", &sexo);
			sexo = tolower(sexo);
		}

		// Solicitar edad
		printf("Ingrese la edad: ");
		scanf("%d", &edad);
		while(edad <= 0 || edad >= 135) { // Si la edad es menor a 0 o mayor a 135 pedir de nuevo
            flushInput();
            printf("Error... Ingrese una edad valida: ");
            scanf("%d", &edad);
		}

        // Solicitar si tiene covid
        printf("Tiene COVID-19? [1/0]: ");
        scanf("%d", &tieneCovid);
        while(tieneCovid != 0 && tieneCovid != 1) {
            flushInput();
            printf("Error... Ingrese un valor valido: ");
            scanf("%d", &tieneCovid);
        }

        // Solicitar la temperatura
        printf("Ingrese la temperatura: ");
        scanf("%f", &temperatura);
        while(temperatura < 30) { // Colocamos 30° porque a esta altura el paciente tiene hipotermia
            flushInput();
            printf("Error... Ingrese una temperatura valida: ");
            scanf("%f", &temperatura);
        }

        // Si es hombre y tiene covid, sumar 1 al contador de hombres con covid
        if(sexo == 'm' && tieneCovid == 1) {
            contadorSexoM++;
        }

        // Si es mujer y tiene covid y es mayor de 40, sumar 1 al contador de mujeres mayores de 40 con covid
        if(sexo == 'f' && tieneCovid == 1 && edad > 40) {
            contadorSexoF40++;
        }

        // Aumentar contadores de mayor y menor temperatura
        if(temperatura > temperaturaMa || temperaturaMa == 0) {
            temperaturaMa = temperatura;
            rutMa = rut;
            edadMa = edad;
            sexoMa = sexo;
        }

        if(temperatura < temperaturaMe || temperaturaMe == 0) {
            temperaturaMe = temperatura;
            rutMe = rut;
            edadMe = edad;
            sexoMe = sexo;
        }

        pacientes++;
        if(tieneCovid == 1) {
            pacientesCovid++;
        }
		printf("\n=-=-=-=-=-=-=-=-=-\n");
	}
  
    imprimirEnPantalla(rutMa, edadMa, sexoMa, temperaturaMa, rutMe, edadMe, sexoMe, temperaturaMe, porcentajePacientes(pacientes, pacientesCovid), contadorSexoM, contadorSexoF40);
  
    
    return 0;
}