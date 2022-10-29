/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 35 - II: Este programa leer� un entero positivo n, y calcular� el 
	m�nimo n�mero de d�gitos que se necesitan para su representaci�n. Para 
	simplificar los c�mputos, supondremos que s�lo queremos representar valores 
	enteros positivos (incluido el cero). 
	 
	Para ello, necesitaremos usar el logaritmo en base 2 y obtener la parte 
	entera de un real (se obtiene tras el truncamiento que se produce al 
	asignar un real a un entero)

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		int numero;
		double binario;
		
	//Recogida de datos
		cout << "Introduzca un numero entero: ";
		cin >> numero;
		
	//Comprobaremos si el n�mero introducido es positivo
	if (numero >= 0){
		bool cero = numero == 0;
		
		//C�lculos
		binario = (int) (log (numero + cero) / log (2)) + 1;
		
		//Salida de datos
		cout << endl << "Para representar el " << numero << " en binario se "
		<< "necesitan " << binario << " bits";
		
	} else {
		cout << endl << "ERROR: El n�mero introducido no es positivo";
		
	}
		
	return 0;
}
