/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 28: [...] Construya un programa que lea un entero representando 
	la clave y un car�cter (supondremos que se introduce correctamente una 
	letra may�scula del alfabeto ingl�s). El programa codificar� el car�cter 
	seg�n la clave introducida y lo mostrar� por pantalla

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		char caracter;
		int clave;
		const int min = 65, num_valores = 26;
		
	//Recogida de datos
		cout << "Introduzca el valor de la clave: ";
		cin >> clave;
		
		cout << "Introduzca un caracter (en may�sculas): ";
		cin >> caracter;
		
	//C�lculos
	 	caracter = min + ((caracter - min + clave) % num_valores);
		
	//Salida de datos
		cout << endl << "El car�cter codificado es: " << caracter;

	return 0;
}
