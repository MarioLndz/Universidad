/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 35 - II: Este programa leerá un entero positivo n, y calculará el 
	mínimo número de dígitos que se necesitan para su representación. Para 
	simplificar los cómputos, supondremos que sólo queremos representar valores 
	enteros positivos (incluido el cero). 
	 
	Para ello, necesitaremos usar el logaritmo en base 2 y obtener la parte 
	entera de un real (se obtiene tras el truncamiento que se produce al 
	asignar un real a un entero)

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
		
	//Comprobaremos si el número introducido es positivo
	if (numero >= 0){
		bool cero = numero == 0;
		
		//Cálculos
		binario = (int) (log (numero + cero) / log (2)) + 1;
		
		//Salida de datos
		cout << endl << "Para representar el " << numero << " en binario se "
		<< "necesitan " << binario << " bits";
		
	} else {
		cout << endl << "ERROR: El número introducido no es positivo";
		
	}
		
	return 0;
}
