/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 25: Diseñar un programa que lea un carácter (supondremos que el 
	usuario introduce una minúscula), lo pase a mayúscula y lo imprima en 
	pantalla. Hacedlo sin usar las funciones toupper ni tolower de la 
	biblioteca cctype

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		char caracter;
		const int conversion = 32;
		
	//Recogida de datos
		cout << "Introduzca un caracter (en minúscula): ";
		cin >> caracter;
		
	/* Pasamos a mayúscula. (Para ello, le restaremos 32 (variable "conversion"
	 a la variable caracter, lo que nos dará el valor en ascii del caracter en 
	 mayúsculas */
	 	caracter -= conversion;
		
	//Salida de datos
		cout << endl << "El carácter introducido en mayúsculas es: "
		<< caracter;

	return 0;
}
