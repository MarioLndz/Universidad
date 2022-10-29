/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 36 - II: Programa que leerá un número real r y un 
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
		
		cout << "Introduzca el numero de decimales que dejaremos al truncar: ";
		cin >> entero;
		
		bool entero_ok = entero >= 0;
		
	//Cálculos
		if (entero_ok){
			double desplazamiento = pow (10, entero);
			
			real = real * desplazamiento;
	
			num_truncado = (int) real / desplazamiento;
			
		}
	
	//Salida de datos
		if (entero_ok){
			cout << endl << "El numero truncado es: " << num_truncado;
			
		} else {
			cout << "ERROR: El número de decimales que dejaremos al truncar no "
				 << "puede ser negativo" << endl;
		}
		
	return 0;
}
