Algoritmo positivo_negativo_cero
	Escribir 'Ingrese el primer numero: ';
	Leer n1;
	Escribir 'Ingrese el segundo numero: ';
	Leer n2;
	suma <- n1+n2;
	Si suma>0 Entonces
		Escribir 'La suma de los numeros ', n1, ' y ', n2, ' es positiva, suma = ', suma;
	SiNo
		Si suma=0 Entonces
			Escribir 'La suma de los numeros ', n1, ' y ', n2, ' es cero, suma = ', suma;
		SiNo
			Si suma<0 Entonces
				Escribir 'La suma de los numeros ', n1, ' y ', n2, ' es negativa, suma = ', suma;
			FinSi
		FinSi
	FinSi
FinAlgoritmo
