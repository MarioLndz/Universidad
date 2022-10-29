/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 35: Se pide crear un programa que lea un entero positivo n, y 
	calcule el mínimo número de dígitos que se necesitan para su 
	representación. Para simplificar los cómputos, suponed que sólo queremos 
	representar valores enteros positivos (incluido el cero). Consejo: se 
	necesitará usar el logaritmo en base 2 y obtener la parte entera de un
	real (se obtiene tras el truncamiento que se produce al asignar un real a 
	un entero)

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		int numero;
		double binario;
		
	//Recogida de datos
		cout << "Introduzca un numero entero: ";
		cin >> numero;
		
		bool cero = numero != 0;
		
	//Cálculos
		binario = (cero * (int) (log (numero) / log (2))) + 1;
		
	//Salida de datos
		cout << endl << "Para representar el " << numero << " en binario se "
		<< "necesitan " << binario << " bits";
		
	return 0;
}
