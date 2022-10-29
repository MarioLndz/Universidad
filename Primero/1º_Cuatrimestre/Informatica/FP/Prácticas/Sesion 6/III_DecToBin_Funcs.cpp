/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 38 - III: Este programa pedirá un número entero n (n >= 0) y un 
	número de bits t (t > 0) y mostrará la representación binaria de todos los 
	valores 0 <= x <= n.

	El resultado se mostrará en forma de tabla, con tres columnas: la primera 
	mostrará x, la segunda la representación binaria -estricta- de x y la 
	tercera la representación binaria de x con t bits.
	
	Para realizar estos cálculos, usaremos funciones.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <iomanip>
#include <string>
using namespace std;

string DecToBin_Bits (int num_decimal, int num_bits){
	int num_aux = num_decimal;
	int resto;
	string num_binario;
	
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
	
	return num_binario;
}

string DecToBinEstricto (int num_decimal){
	int num_aux = num_decimal;
	int resto;
	string num_binario;
	
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
	
	return num_binario;
}

void ComienzoTabla (int ancho, int num_bits){
	const int COLUMNAS = 3;
	string BITS = to_string(num_bits) + " bits";
	
	cout << "|";
	cout << fixed << setw(ancho);
	cout << "x" << "|";
	
	cout << fixed << setw(ancho);
	cout << "ESTRICTO" << "|";
	
	cout << fixed << setw(ancho);
	cout << BITS << "|" << endl;
	
	cout << "|";
	for (int n = 0; n < COLUMNAS; n++){
		for (int x = 0; x < ancho; x++){
			cout << "-";
		}
		cout << "|";
	}
	cout << endl;
}

int main () {
	//Variables
	int num_max;
	string num_binario;
	string num_binario_estricto;
	
	int num_bits;
	
	//ENTRADA DE DATOS
	//Número a representar
	
	do {
		cout << "Máximo valor a codificar en binario: ";
		cin >> num_max;
		
		if (num_max < 0){
			cout << "ERROR: El número introducido no es positivo. ";
			
		}
		
	} while (num_max < 0);
	
	//Numero de bits
	do {
		cout << "Número de bits: ";
		cin >> num_bits;
		
		if (num_bits <= 0){
			cout << "ERROR: El número de bits debe ser mayor que 0. ";
			cout << "Vuelva a intentarlo" << endl;
		}

	} while (num_bits <= 0);
	cout << endl;
	
	//TABLA
	const int margen = 2;
	int ancho = num_bits + margen;
	
	if (ancho < 8){
		ancho = 8;
	}
	
	ComienzoTabla(ancho, num_bits);
	
	//CÁLCULOS 
	for (int x = 0; x <= num_max; x++){
		
		num_binario_estricto = DecToBinEstricto(x);
		num_binario = DecToBin_Bits (x, num_bits);
		
		
		//SALIDA DE DATOS
		cout << "|";
		
		cout << fixed << setw(ancho);
		cout << x << "|";
		
		cout << fixed << setw(ancho);
		cout << num_binario_estricto << "|";
		
		cout << fixed << setw(ancho);
		cout << num_binario << "|";
		
		cout << endl;
		
	}

	return 0;
}
