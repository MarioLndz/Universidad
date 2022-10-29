/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 85 - II: Este programa mostrar� la representaci�n decimal de un 
	n�mero expresado en binario.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int main () {
	//Variables
	string num_binario;
	int longitud;
	
	bool num_binario_valido;
	
	
	//Entrada y comprobaci�n de errores
	do {
		num_binario_valido = true;
		
		cout << "Introduzca un n�mero binario: ";
		cin >> num_binario;
		
		longitud = num_binario.length();
		
		//Comprueba que toda la cadena est� formada por 0 y 1
		for (int n = 0; n < longitud; n++){
			if (num_binario[n] != '0' && num_binario[n] != '1'){
				num_binario_valido = false;
		
			}
		}
		
		//Muestra el mensaje de error si est� mal escrita
		if (!num_binario_valido){
			cout << "ERROR: N�mero binario mal escrito. Vuelva a intentarlo"
			 << endl;
		}
		
		cout << endl;
		
	} while (!num_binario_valido);

	//C�lculos
	double posicion = longitud - 1;
	double exponente;
	
	double num_decimal;
	
	while (posicion >= 0){
		if (num_binario.at(posicion) == '1'){
			exponente = longitud - (posicion + 1);
			
			num_decimal = num_decimal + pow (2, exponente);
			
		}
		posicion--;
		
	}
	
	//Salida
	cout << num_binario << " en base decimal es " << num_decimal;
	
	return 0;
}
