/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 39 - III: Este programa pedir� un valor binario (se leer�
	sobre un dato string), se verificar�, se simplificar� y finalmente se 
	calcular� su valor decimal y se mostrar� el resultado.
	
	Para estos c�lculos, usaremos diferentes funciones.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

bool EsBinario (string num_binario){
	bool num_binario_valido = true;
	
	int longitud = num_binario.length();
		
	//Comprueba que toda la cadena est� formada por 0 y 1
	for (int n = 0; n < longitud; n++){
		if (num_binario[n] != '0' && num_binario[n] != '1'){
			num_binario_valido = false;
	
		}
	}
	
	return (num_binario_valido);
}

string NumBinarioSimplificado (string num_binario){
	string num_binario_simplificado;
	bool parar = false;
	int posicion = 0;
	
	int longitud = num_binario.length();
	
	//Calcula la posici�n del primer bit diferente de 0
	while (!parar && posicion < longitud){
		if (num_binario[posicion] == '1'){
				parar = true;
				
			} else {
				posicion++;
			}
	}
	
	//Crea una subcadena a partir del primer bit significativo
	if (posicion == longitud){
		num_binario_simplificado = '0';
		
	} else {
		int bits_estrictos = longitud - posicion;
		
		num_binario_simplificado = num_binario.substr(posicion, bits_estrictos);
		
	}
	
	return (num_binario_simplificado);
}

int BinToDec (string num_binario){
	int longitud = num_binario.length();
	
	double posicion = longitud - 1;
	double exponente;
	
	int num_decimal;
	
	while (posicion >= 0){
		if (num_binario.at(posicion) == '1'){
			exponente = longitud - (posicion + 1);
			
			num_decimal = num_decimal + pow (2, exponente);
			
		}	
		posicion--;
	}
	
	return (num_decimal);
}

int main () {
	//Variables
	string num_binario;
	string num_binario_estricto;
	int num_decimal;
	
	bool num_binario_valido;
	
	//ENTRADA DE DATOS Y COMPROBACI�N DE ERRORES
	do {
		num_binario_valido = true;
		
		cout << "Introduzca un n�mero binario: ";
		cin >> num_binario;
		
		num_binario_valido = EsBinario(num_binario);
		
		//Muestra el mensaje de error si est� mal escrita
		if (!num_binario_valido){
			cout << "ERROR: N�mero binario mal escrito. Vuelva a intentarlo"
			 << endl;
		}
		cout << endl;
		
	} while (!num_binario_valido);
	
	//C�LCULOS
	num_binario_estricto = NumBinarioSimplificado(num_binario);
	num_decimal = BinToDec(num_binario_estricto);

	//SALIDA
	cout << num_binario << " simplificado es " << num_binario_estricto << endl;
	cout << num_binario_estricto << " en base decimal es " << num_decimal;
	
	return 0;
}
