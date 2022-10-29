/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 25 - II: Programa que lee un carácter (supondremos que el usuario 
	introduce una minúscula), lo pasa a mayúscula y lo imprime en pantalla

*****************************************************************************/

#include <iostream>	// Inclusión de los recursos de E/S

using namespace std;

int main () {
	//Variables
		char caracter;
		const int conversion = 'a' - 'A';
		
	//Recogida de datos
		cout << "Introduzca un caracter (en minúscula): ";
		cin >> caracter;
	
	//Comprobamos si el caracter introducido es válido
	if (caracter >= 'a' && caracter <= 'z') {	//Caracter válido
		/* Pasamos a mayúscula. (Restaremos la variable "conversion" a la 
		variable caracter, lo que nos dará el valor en ascii del caracter en 
		mayúsculas */
		
	 		caracter -= conversion;
		
		//Salida de datos
			cout << endl << "El carácter introducido en mayúsculas es: "
				 << caracter;
		
	} else {		//Error
		cout << endl << "Error: No se ha introducido un carácter en minúscula";
	}

	return 0;
}
