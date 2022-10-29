/*

Mario Líndez Martínez
Ejercicio 1 - Ley de Ohm

*/

#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;

int main () { // Programa Principal
	//Variables
		double voltaje, intensidad, resistencia;

	//Recogida de datos
		cout << "Introduzca el valor de la Intensidad: ";
		cin >> intensidad;
		
		cout << "Introduzca el valor de la Resistencia: ";
		cin >> resistencia;

	//Cálculos
		voltaje = intensidad * resistencia;

	//Salida
		cout << endl << "El valor del voltaje es: " << voltaje << " A";

   return 0;
}

