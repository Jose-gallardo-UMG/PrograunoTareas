Algoritmo promedio
	continuar <- 'si';
	total <- 0;
	numeros <- 0;
	Mientras continuar='si' Hacer
		numeros <- numeros+1;
		Escribir 'Ingrese numero: ';
		Leer numero;
		total <- total+numero;
		Escribir 'desea ingresar otro numero si/no?';
		Leer continuar;
	FinMientras
	Escribir 'el promedio es de: ', (total/numeros);
FinAlgoritmo
