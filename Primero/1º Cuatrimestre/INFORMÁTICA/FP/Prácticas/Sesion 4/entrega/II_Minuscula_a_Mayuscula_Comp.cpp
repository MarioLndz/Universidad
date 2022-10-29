/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 25 - II: Programa que lee un car�cter (supondremos que el usuario 
	introduce una min�scula), lo pasa a may�scula y lo imprime en pantalla

*****************************************************************************/

#include <iostream>	// Inclusi�n de los recursos de E/S

using namespace std;

int main () {
	//Variables
		char caracter;
		const int conversion = 'a' - 'A';
		
	//Recogida de datos
		cout << "Introduzca un caracter (en min�scula): ";
		cin >> caracter;
	
	//Comprobamos si el caracter introducido es v�lido
	if (caracter >= 'a' && caracter <= 'z') {	//Caracter v�lido
		/* Pasamos a may�scula. (Restaremos la variable "conversion" a la 
		variable caracter, lo que nos dar� el valor en ascii del caracter en 
		may�sculas */
		
	 		caracter -= conversion;
		
		//Salida de datos
			cout << endl << "El car�cter introducido en may�sculas es: "
				 << caracter;
		
	} else {		//Error
		cout << endl << "Error: No se ha introducido un car�cter en min�scula";
	}

	return 0;
}
