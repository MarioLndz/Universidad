/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 20: En atletismo se expresa la rapidez de un atleta en términos 
	de ritmo (minutos y segundos por kilómetro) más que en unidades de 
	velocidad (kilómetros por hora). Escribid dos programas para convertir 
	entre estas dos medidas:
		a) El primero leerá el ritmo (minutos y segundos, por separado) y 
		mostrará la velocidad (kilómetros por hora).
		b) El segundo leerá la velocidad (kilómetros por hora) y mostrará el 
		ritmo (minutos y segundos).

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double segundos, velocidad;
		int minutos;
		
	//Recogida de datos
		cout << "Introduzca el valor de la velocidad en km/h: ";
		cin >> velocidad;
		
	//Cálculos
		minutos = 60 / velocidad;/*	Gracias a que minutos es entero nos 
									podemos quedar solo con la parte entera */
		segundos = ((60 / velocidad) - minutos) * 60;

	//Salida de datos
		cout << endl << "El atleta corre a " << minutos << " min y " 
		<< segundos << " segundos por kilómetro";

	return 0;
}
