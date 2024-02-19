Algoritmo Credito_limite
	// Definir variables
	Definir numero_cuenta, saldo_inicial, cargos_totales, creditos_totales, limite_credito Como Real;
	// Instrucción repetitiva para recibir entrada de datos
	Escribir 'Introduzca el numero de cuenta (-1 para salir): ';
	Leer numero_cuenta;
	Mientras numero_cuenta<>-1 Hacer
		Escribir 'Introduzca el saldo inicial: ';
		Leer saldo_inicial;
		Escribir 'Introduzca los cargos totales: ';
		Leer cargos_totales;
		Escribir 'Introduzca los creditos totales: ';
		Leer creditos_totales;
		Escribir 'Introduzca el limite de credito: ';
		Leer limite_credito;
		// Calcular el nuevo saldo
		nuevo_saldo <- saldo_inicial+cargos_totales-creditos_totales;
		// Verificar si se excedió el límite de crédito
		Si nuevo_saldo>limite_credito Entonces
			// Mostrar la información del cliente y un mensaje de exceso de crédito
			Escribir 'El nuevo saldo es ', nuevo_saldo;
			Escribir 'Cuenta: ', numero_cuenta;
			Escribir 'Limite de credito: ', limite_credito;
			Escribir 'Saldo: ', nuevo_saldo;
			Escribir 'Se excedio el limite de su credito';
		FinSi
		// Volver a solicitar el número de cuenta para continuar o terminar el programa
		Escribir 'Introduzca el numero de cuenta (-1 para salir): ';
		Leer numero_cuenta;
	FinMientras
FinAlgoritmo
