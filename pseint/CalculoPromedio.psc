Algoritmo CalculoPromedio
	Definir nota1,nota2,nota3,promedio Como Real
	
	Escribir "Ingresa nota 1: "
	Leer nota1
	
	Escribir "Ingresa nota 2:"
	Leer nota2
	
	Escribir "Ingresa nota 3:"
	Leer nota3
	
	promedio <- (nota1+nota2+nota3)/3
	Si promedio >= 3.5 Entonces
		Escribir "El estudiante aprobó con nota: ", promedio
	SiNo
		Escribir "El estudiante reprobó con nota: ", promedio
	FinSi
	
FinAlgoritmo
