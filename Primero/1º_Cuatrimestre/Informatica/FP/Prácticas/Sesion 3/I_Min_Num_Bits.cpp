/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 35: Se pide crear un programa que lea un entero positivo n, y 
	calcule el m�nimo n�mero de d�gitos que se necesitan para su 
	representaci�n. Para simplificar los c�mputos, suponed que s�lo queremos 
	representar valores enteros positivos (incluido el cero). Consejo: se 
	necesitar� usar el logaritmo en base 2 y obtener la parte entera de un
	real (se obtiene tras el truncamiento que se produce al asignar un real a 
	un entero)

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
		
		bool cero = numero != 0;
		
	//C�lculos
		binario = (cero * (int) (log (numero) / log (2))) + 1;
		
	//Salida de datos
		cout << endl << "Para representar el " << numero << " en binario se "
		<< "necesitan " << binario << " bits";
		
	return 0;
}
