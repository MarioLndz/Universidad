/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 14: Escriba un programa que lea un distancia en millas (como un
	real) y muestre la cantidad equivalente en kilómetros. A continuación leerá 
	una distancia en kilómetros (como un real) y mostrará la cantidad 
	equivalente en millas.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double millas, kilometros;
		
	//Recogida de datos (millas)
		cout << "Introduzca el valor de las millas: ";
		cin >> millas;
		
	//Conversión millas - kilómetros
		kilometros = millas * 1.609;
		
	//Salida
		cout << millas << " millas son " << kilometros << " km" << endl;
		
	//Recogida de datos (kilómetros)
		cout << endl << "Introduzca el valor de los kilómetros: ";
		cin >> kilometros;
	
	//Conversión kilómetros - millas
		millas = kilometros / 1.609;
		
	//Salida
		cout << kilometros << "km son " << millas << " millas";
	
	return 0;
}
