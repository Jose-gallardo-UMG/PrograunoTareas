Algoritmo Calculadora
	
	Escribir "Que desea realizar? ";
	Escribir "1. sumar";
	Escribir "2. restar";
	Escribir "3. Multiplicar";
	Escribir "4. Dividir";
	
	Leer opcion;
	
	si opcion = 1 Entonces
		Escribir "ingrese un numero: ";
		leer numero1;
		Escribir "ingrese otro numero: ";
		leer numero2;
		resultado = numero1+numero2;
		Escribir "la suma de los numeros es: ", resultado;
	SiNo
		Si opcion = 2 Entonces
			Escribir "ingrese un numero: ";
			leer numero1;
			Escribir "ingrese otro numero: ";
			leer numero2;
			resultado = numero1-numero2;
			Escribir "la resta de los numeros es: " resultado;
		SiNo
			Si opcion = 3 Entonces
				Escribir "ingrese un numero: ";
				leer numero1;
				Escribir "ingrese otro numero: ";
				leer numero2;
				resultado = numero1*numero2;
				Escribir "la miltiplicacion de los numeros es: " resultado;
			SiNo
				Si opcion = 4 Entonces
					Escribir "ingrese un numero: ";
					leer numero1;
					Escribir "ingrese otro numero: ";
					leer numero2;
					resultado = numero1/numero2;
					Escribir "la Division de los numeros es: " resultado;
				SiNo
					Escribir "Error al ingresar opcion entre 1 a 4, opcion elegida: " opcion;
				Fin Si
			Fin Si
		Fin Si
	FinSi
	
FinAlgoritmo
