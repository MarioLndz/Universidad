/*

Mario L�ndez Mart�nez
Ejercicio 1 - Ley de Ohm

*/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos
using namespace std;

int main () { // Programa Principal
	//Variables
		double radio;
		double longitud_circunferencia, area_circulo;
		
		double pi = 3.1416;

	//Recogida de datos
		cout << "Introduzca el valor del radio: ";
		cin >> radio;

	//C�lculos
		longitud_circunferencia = 2 * pi * radio;
		area_circulo = pi * pow(radio, 2);

	//Salida
		cout << endl << "El valor de la longitud de la circunferencia es de " << longitud_circunferencia << endl;
		cout << "El valor del �rea del c�rculo es de " << area_circulo << endl;
 	
   return 0;
}
