Algoritmo Calculadora_repeticion
	continuar <- 'si';
	Mientras continuar='si' Hacer
		Escribir 'Ingrese el primer número: ';
		Leer numero1;
		Escribir 'Ingrese el operador (1. suma, 2. resta, 3. multiplicacion, 4. Division): ';
		Leer operador;
		Escribir 'Ingrese el segundo número: ';
		Leer numero2;
		// Realizar la operación
		Según operador Hacer
			'1':
				resultado <- numero1+numero2;
			'2':
				resultado <- numero1-numero2;
			'3':
				resultado <- numero1*numero2;
			'4':
				Si numero2<>0 Entonces
					resultado <- numero1/numero2;
				SiNo
					Escribir 'Error: División por cero.';
					error <- 'Error';
				FinSi
			De Otro Modo:
				Escribir 'Operador no válido.';
		FinSegún
		Escribir 'El resultado es: ', resultado, error;
		Escribir 'Desea continuar? (si/no)';
		Leer continuar;
	FinMientras
FinAlgoritmo
