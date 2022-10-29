/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 14: Escriba un programa que lea un distancia en millas (como un
	real) y muestre la cantidad equivalente en kil�metros. A continuaci�n leer� 
	una distancia en kil�metros (como un real) y mostrar� la cantidad 
	equivalente en millas.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double millas, kilometros;
		
	//Recogida de datos (millas)
		cout << "Introduzca el valor de las millas: ";
		cin >> millas;
		
	//Conversi�n millas - kil�metros
		kilometros = millas * 1.609;
		
	//Salida
		cout << millas << " millas son " << kilometros << " km" << endl;
		
	//Recogida de datos (kil�metros)
		cout << endl << "Introduzca el valor de los kil�metros: ";
		cin >> kilometros;
	
	//Conversi�n kil�metros - millas
		millas = kilometros / 1.609;
		
	//Salida
		cout << kilometros << "km son " << millas << " millas";
	
	return 0;
}
