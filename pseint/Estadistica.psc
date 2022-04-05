Algoritmo Estadistica
	Definir pos,neg,neutro,contador,num Como Entero
	Definir prom Como Real
	
	pos=0
	neg=0
	neutro=0
	contador=0
	num=0
	prom=0
	
	Mientras contador < 10 Hacer
		Escribir "Ingresa un numero"
		Leer num
		
		Si num < 0 Entonces
			neg = neg+1
		SiNo
			Si num > 0 Entonces
				pos = pos+1
			SiNo
				neutro = neutro+1
			FinSi
		FinSi
		prom = prom + num
		contador = contador+1
	FinMientras
	Escribir "Hay ", pos, " positivos, ", neg, " negativos y ", neutro, " neutros."
	Escribir "Y el promedio es: ", prom/10
FinAlgoritmo
