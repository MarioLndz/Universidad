/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 15: Realizar un programa que nos pida una longitud cualquiera 
	dada en metros. El programa deberá calcular el equivalente de dicha 
	longitud en pulgadas, pies, yardas y millas, y mostrarnos los resultados 
	en pantalla.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double metros, pulgada, pie, yarda, millas;
		
	//Recogida de datos
		cout << "Introduzca la longitud en metros: ";
		cin >> metros;
		
	//Cálculos
		pulgada = (metros * 1000) / 25.4;
		pie = (metros * 100) / 30.48;	
		yarda = metros / 0.9144;		
		millas = (metros / 1000) / 1.609344; 
		
	//Salida de datos
		cout << endl << metros << " metros son:" << endl;
			cout << "\t" << pulgada << " pulgadas" << endl;
			cout << "\t" << pie << " pies" << endl;
			cout << "\t" << yarda << " yardas" << endl;
			cout << "\t" << millas << " millas" << endl;

	return 0;
}
