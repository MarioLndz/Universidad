/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 25: Dise�ar un programa que lea un car�cter (supondremos que el 
	usuario introduce una min�scula), lo pase a may�scula y lo imprima en 
	pantalla. Hacedlo sin usar las funciones toupper ni tolower de la 
	biblioteca cctype

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		char caracter;
		const int conversion = 32;
		
	//Recogida de datos
		cout << "Introduzca un caracter (en min�scula): ";
		cin >> caracter;
		
	/* Pasamos a may�scula. (Para ello, le restaremos 32 (variable "conversion"
	 a la variable caracter, lo que nos dar� el valor en ascii del caracter en 
	 may�sculas */
	 	caracter -= conversion;
		
	//Salida de datos
		cout << endl << "El car�cter introducido en may�sculas es: "
		<< caracter;

	return 0;
}
