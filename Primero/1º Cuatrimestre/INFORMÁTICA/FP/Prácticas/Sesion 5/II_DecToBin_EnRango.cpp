/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 84 - II: Este programa mostrar� la representaci�n binaria de un 
	n�mero entero (positivo o cero) expresado en base 10.
	
	En primer lugar se pedir� el n�mero de bits	que tendr�n los valores 
	binarios con los que se va a trabajar y se har� la representaci�n binaria 
	teniendo en cuenta el n�mero de bits.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>
#include <cmath>

using namespace std;

int main () {
	//Variables
	int num_decimal;
	int num_aux, resto;
	string num_binario;
	
	int num_bits;
	
	//Entrada
		//Numero de bits
		cout << "Introduzca el n�mero de bits: ";
		cin >> num_bits;
		
		while (num_bits <= 0){
			cout << "ERROR: El n�mero de bits debe ser mayor que 0. ";
			cout << "Vuelva a intentarlo" << endl;
			
			cout << endl;
			cout << "Introduzca el n�mero de bits: ";
			cin >> num_bits;
		}	
		
		int num_representables = pow (2, num_bits) - 1;
		
		//N�mero a representar
		cout << "Introduzca un n�mero entero positivo en el intervalo [0, "
			 << num_representables << "]: ";
		cin >> num_decimal;

		while (num_decimal < 0 || num_decimal > num_representables){
			if (num_decimal < 0){
				cout << "ERROR: El n�mero introducido no es positivo. ";
				
			} else {
				cout << "El n�mero introducido no es representable con "
					 << num_bits << " bits. ";
					 
			}
			cout << "Vuelva a intentarlo" << endl;
			
			cout << endl;
			cout << "Introduzca un n�mero entero positivo en el intervalo [0, "
			 	 << num_representables << "]: ";
			cin >> num_decimal;	
			
		}
	
	//C�lculos
	num_aux = num_decimal;
	
	if (num_aux == 0){
		num_binario = '0';
		
	} else {
		while (num_aux != 0){
			resto = num_aux % 2;
			num_aux = num_aux / 2;
			
			if (resto == 0) {
				num_binario = '0' + num_binario;
				
			} else {
				num_binario = '1' + num_binario;
				
			}
		}
	}

	int longitud = num_binario.length();
	
	while (longitud < num_bits){
		num_binario = '0' + num_binario;
		longitud++;
		
	}
	
	//Salida
	cout << endl;
	cout << num_decimal << " en binario es: " << num_binario;
	
	return 0;
}

