/*

Mario L�ndez Mart�nez
Ejercicio 1 - Ley de Ohm

*/

#include <iostream>   // Inclusi�n de los recursos de E/S
using namespace std;

int main () { // Programa Principal
	//Variables
		double voltaje, intensidad, resistencia;

	//Recogida de datos
		cout << "Introduzca el valor de la Intensidad: ";
		cin >> intensidad;
		
		cout << "Introduzca el valor de la Resistencia: ";
		cin >> resistencia;

	//C�lculos
		voltaje = intensidad * resistencia;

	//Salida
		cout << endl << "El valor del voltaje es: " << voltaje << " A";

   return 0;
}

