/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 83 - II: Este programa mostrará la representación binaria de un 
	número entero (positivo o cero) expresado en base 10.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>

using namespace std;

int main () {
	//Variables
	int num_decimal;
	int num_aux, resto;
	string num_binario;
	
	//Entrada
	cout << "Introduzca un número entero positivo: ";
	cin >> num_decimal;
		
	while (num_decimal < 0){
		cout << "ERROR: El número introducido no es positivo, vuelva "
			 << "a intentarlo" << endl;
		
		cout << endl;
		cout << "Introduzca un número entero positivo: ";
		cin >> num_decimal;	
		
	}
	
	//Cálculos
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
	
	//Salida
	cout << endl;
	cout << num_decimal << " en binario es: " << num_binario;
	
	return 0;
}

