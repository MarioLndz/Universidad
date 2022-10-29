/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 28: [...] Construya un programa que lea un entero representando 
	la clave y un carácter (supondremos que se introduce correctamente una 
	letra mayúscula del alfabeto inglés). El programa codificará el carácter 
	según la clave introducida y lo mostrará por pantalla

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
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
		
		cout << "Introduzca un caracter (en mayúsculas): ";
		cin >> caracter;
		
	//Cálculos
	 	caracter = min + ((caracter - min + clave) % num_valores);
		
	//Salida de datos
		cout << endl << "El carácter codificado es: " << caracter;

	return 0;
}
