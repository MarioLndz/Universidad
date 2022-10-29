/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 26 - II: Este programa lee un valor entero en un dato de tipo 
	string. A continuación lo convierte y asigna a un dato int (supondremos que 
	el usuario introduce siempre un entero de tres dígitos, como por ejemplo 
	351). En pantalla se escribirán los dígitos separados por dos espacios en 
	blanco. Con el valor anterior la salida sería:
		3  5  1
	Lo que se mostrará en pantalla es el valor de otro dato string que se forma 
	concatenando tres parejas de valores compuestas de dos espacios en blanco 
	y un dígito.

*****************************************************************************/

#include <iostream>	// Inclusión de los recursos de E/S
#include <string>	//Para poder usar datos tipo string
#include <cctype>

using namespace std;

int main () {
	//Variables
		string numero;
		string cifras;
		const int DIGITOS = 3;
		
	//Recogida del string
		cout << "Introduce un número entero de 3 dígitos: ";
		cin >> numero;
		
	//Comprobamos si el numero introducido tiene 3 dígitos
		bool tiene_3_cifras = numero.length() == DIGITOS
	
	if (tiene_3_cifras){	//Longitud válida
		//Comprobamos si lo introducido es un dígito
		bool son_digitos = isdigit(numero[0]) && isdigit(numero[1]) &&
						   isdigit(numero[2]);

		if (son_digitos){	//Número válido
			//Transformamos cada dato de la cadena en un entero
			int centenas;
			int decenas;
			int unidades;
			
			int num_3digitos;
			int num_2digitos;
	
			num_3digitos = stoi(numero);
	
			centenas = num_3digitos / 100;
			num_2digitos = num_3digitos % 100;
	
			decenas = num_2digitos / 10;
			unidades = num_2digitos % 10;
			
			//Creamos la nueva cadena según las condiciones impuestas
			const string SEPARADOR = "  ";
			cifras = SEPARADOR + to_string(centenas) + 
					 SEPARADOR + to_string(decenas) +
					 SEPARADOR + to_string(unidades);
			//Mostramos por pantalla
			cout << endl << cifras;
			
		} else {
			cout << endl;
			cout << "ERROR: No son dígitos";
			
		}
			
	} else {	//ERROR
		cout << endl << "ERROR: El número introducido no es de 3 dígitos";
		
	}
	
	return 0;
}
