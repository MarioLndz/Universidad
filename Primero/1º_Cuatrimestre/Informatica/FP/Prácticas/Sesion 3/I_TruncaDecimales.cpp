/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 36: Se quiere construir un programa que lea un n�mero real r y un 
	n�mero entero n y trunque r a tantas cifras decimales como indique n. El 
	resultado debe guardarse en una variable diferente. La �nica funci�n que 
	puede usar de cmath es pow.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		int entero;
		double real, num_truncado;
		
	//Recogida de datos
		cout << "Introduzca un n�mero real: ";
		cin >> real;
		
		cout << "Introduzca el numero de decimales que truncaremos: ";
		cin >> entero;

	//C�lculos
		real = real * pow (10, entero);
		
		num_truncado = (int) real * pow (10, -entero);
		
	//Salida de datos
		cout << endl << "El numero truncado es: " << num_truncado;

	return 0;
}
