Algoritmo Acumulador_suma_numeros
	
	Escribir "Ingrese un numero (0 para salir)";
	Leer  numero;
	total = 0;
	Mientras numero<>0 Hacer
		total = total + numero ;
		Escribir "ingrese otro numero";
		Leer numero;
	FinMientras
	Escribir "El total acumulado es: ", total;
FinAlgoritmo
