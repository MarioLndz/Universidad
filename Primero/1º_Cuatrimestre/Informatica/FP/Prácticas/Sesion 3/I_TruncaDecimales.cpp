/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 36: Se quiere construir un programa que lea un número real r y un 
	número entero n y trunque r a tantas cifras decimales como indique n. El 
	resultado debe guardarse en una variable diferente. La única función que 
	puede usar de cmath es pow.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		int entero;
		double real, num_truncado;
		
	//Recogida de datos
		cout << "Introduzca un número real: ";
		cin >> real;
		
		cout << "Introduzca el numero de decimales que truncaremos: ";
		cin >> entero;

	//Cálculos
		real = real * pow (10, entero);
		
		num_truncado = (int) real * pow (10, -entero);
		
	//Salida de datos
		cout << endl << "El numero truncado es: " << num_truncado;

	return 0;
}
