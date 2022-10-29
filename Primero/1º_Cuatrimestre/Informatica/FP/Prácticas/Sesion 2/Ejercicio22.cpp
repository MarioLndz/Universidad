/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 22: Queremos construir una expresión numérica que desplace un 
	entero un número dado de posiciones, pero lo mantenga dentro de un 
	intervalo.
	
*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		int minimo, maximo, desplazamiento, a_desplazar, posicion_final;
		
	//Recogida de datos
		cout << "Introduzca el valor mínimo del intervalo: ";
		cin >> minimo;
		
		cout << "Introduzca el valor máximo del intervalo: ";
		cin >> maximo;

		cout << "Introduzca el número de posiciones a desplazar (el valor del"
		<< " desplazamiento): ";
		cin >> desplazamiento;
		
		cout << "Introduzca el número a desplazar: ";
		cin >> a_desplazar;
		
	//Cálculos
		posicion_final = a_desplazar + desplazamiento;
		
		//No se me ha ocurrido una forma de hacerlo sin utilizar "if"
		
		if (posicion_final > maximo) {
			posicion_final = (minimo - 1) + (posicion_final - maximo);
		}
		
	//Salida
		cout << endl << "La posición final es " << posicion_final;	
	
	return 0;
}
