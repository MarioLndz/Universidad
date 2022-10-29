/*

Mario Líndez Martínez
Ejercicio 1 - Ley de Ohm

*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos
using namespace std;

int main () { // Programa Principal
	//Variables
		double radio;
		double longitud_circunferencia, area_circulo;
		
		double pi = 3.1416;

	//Recogida de datos
		cout << "Introduzca el valor del radio: ";
		cin >> radio;

	//Cálculos
		longitud_circunferencia = 2 * pi * radio;
		area_circulo = pi * pow(radio, 2);

	//Salida
		cout << endl << "El valor de la longitud de la circunferencia es de " << longitud_circunferencia << endl;
		cout << "El valor del área del círculo es de " << area_circulo << endl;
 	
   return 0;
}
