/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 36 - II: Programa que leer� un n�mero real r y un 
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
		
		cout << "Introduzca el numero de decimales que dejaremos al truncar: ";
		cin >> entero;
		
		bool entero_ok = entero >= 0;
		
	//C�lculos
		if (entero_ok){
			double desplazamiento = pow (10, entero);
			
			real = real * desplazamiento;
	
			num_truncado = (int) real / desplazamiento;
			
		}
	
	//Salida de datos
		if (entero_ok){
			cout << endl << "El numero truncado es: " << num_truncado;
			
		} else {
			cout << "ERROR: El n�mero de decimales que dejaremos al truncar no "
				 << "puede ser negativo" << endl;
		}
		
	return 0;
}
