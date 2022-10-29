/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 26 - II: Este programa lee un valor entero en un dato de tipo 
	string. A continuaci�n lo convierte y asigna a un dato int (supondremos que 
	el usuario introduce siempre un entero de tres d�gitos, como por ejemplo 
	351). En pantalla se escribir�n los d�gitos separados por dos espacios en 
	blanco. Con el valor anterior la salida ser�a:
		3  5  1
	Lo que se mostrar� en pantalla es el valor de otro dato string que se forma 
	concatenando tres parejas de valores compuestas de dos espacios en blanco 
	y un d�gito.

*****************************************************************************/

#include <iostream>	// Inclusi�n de los recursos de E/S
#include <string>	//Para poder usar datos tipo string
#include <cctype>

using namespace std;

int main () {
	//Variables
		string numero;
		string cifras;
		const int DIGITOS = 3;
		
	//Recogida del string
		cout << "Introduce un n�mero entero de 3 d�gitos: ";
		cin >> numero;
		
	//Comprobamos si el numero introducido tiene 3 d�gitos
		bool tiene_3_cifras = numero.length() == DIGITOS
	
	if (tiene_3_cifras){	//Longitud v�lida
		//Comprobamos si lo introducido es un d�gito
		bool son_digitos = isdigit(numero[0]) && isdigit(numero[1]) &&
						   isdigit(numero[2]);

		if (son_digitos){	//N�mero v�lido
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
			
			//Creamos la nueva cadena seg�n las condiciones impuestas
			const string SEPARADOR = "  ";
			cifras = SEPARADOR + to_string(centenas) + 
					 SEPARADOR + to_string(decenas) +
					 SEPARADOR + to_string(unidades);
			//Mostramos por pantalla
			cout << endl << cifras;
			
		} else {
			cout << endl;
			cout << "ERROR: No son d�gitos";
			
		}
			
	} else {	//ERROR
		cout << endl << "ERROR: El n�mero introducido no es de 3 d�gitos";
		
	}
	
	return 0;
}
