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
		double minutos, segundos, velocidad;
		
	//Recogida de datos
		cout << "Introduzca el valor del ritmo: ";
		
		cout << endl << "\t Introduzca los minutos: ";
		cin >> minutos;
		
		cout << "\t Introduzca los segundos: ";
		cin >> segundos;
		
	//Cálculos
		velocidad = 60 / (minutos + (segundos / 60));
		
	//Salida de datos
		cout << endl << "El atleta corre a " << velocidad << "km/h";

	return 0;
}
