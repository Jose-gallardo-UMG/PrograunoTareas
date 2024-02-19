Algoritmo Calcular_Sueldo_Bruto
	// Definir variables
	Definir horas_trabajadas, tarifa_por_horas Como Real;
	Definir sueldo_bruto Como Real;
	// Instrucción repetitiva para recibir entrada de datos para cada empleado
	Escribir 'Introduzca las horas trabajadas (-1 para salir): ';
	Leer horas_trabajadas;
	Mientras horas_trabajadas<>-1 Hacer
		Escribir 'Introduzca la tarifa por horas del empleado ($00.00): ';
		Leer tarifa_por_horas;
		// Calcular el sueldo bruto para el empleado
		Si horas_trabajadas<=40 Entonces
			sueldo_bruto <- horas_trabajadas*tarifa_por_horas;
		SiNo
			sueldo_bruto <- (40*tarifa_por_horas)+((horas_trabajadas-40)*1.5*tarifa_por_horas);
		FinSi
		// Mostrar el sueldo bruto del empleado
		Escribir 'El salario es $', sueldo_bruto;
		// Solicitar la entrada de datos para el próximo empleado o salir del programa
		Escribir 'Introduzca las horas trabajadas (-1 para salir): ';
		Leer horas_trabajadas;
	FinMientras
FinAlgoritmo
