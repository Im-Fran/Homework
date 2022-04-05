Algoritmo DiaSemana
	Definir dia Como Entero
	Escribir "Ingresa el día: "
	Leer dia
	
	Mientras dia < 1 O dia > 7 Hacer
		Escribir "Ingresa un número entre 1 y 7!"
		Leer dia
	FinMientras
	
	Segun dia
		Caso 1:
			Escribir "Es Lunes!"
		Caso 2:
			Escribir "Es Martes!"
		Caso 3:
			Escribir "Es Miércoles!"
		Caso 4:
			Escribir "Es Jueves!"
		Caso 5:
			Escribir "Es Viernes!"
		Caso 6:
			Escribir "Es Sábado!"
		Caso 7:
			Escribir "Es Domingo!"
	FinSegun
FinAlgoritmo
