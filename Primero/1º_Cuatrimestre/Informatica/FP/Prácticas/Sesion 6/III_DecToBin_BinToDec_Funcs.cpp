/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 40 - III: Usaremos las funciones implementadas en el ejercicio 39 
	para verificar los resultados del ejercicio 38.
	
	Usaremos el código de dichos ejercicios y ampliaremos la tabla añadiendo 
	una nueva columna para comprobar que tomando la representación binaria con 
	t bits, simplificándola y convirtiéndola a decimal, el resultado es igual 
	al valor decimal inicial

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <iomanip>
#include <string>
#include <cmath>
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

bool EsBinario (string num_binario){
	bool num_binario_valido = true;
	
	int longitud = num_binario.length();
		
	//Comprueba que toda la cadena está formada por 0 y 1
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
	
	//Calcula la posición del primer bit diferente de 0
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

void ComienzoTabla (int ancho, int num_bits){
	const int COLUMNAS = 4;
	string BITS = to_string(num_bits) + " bits";
	
	cout << "|";
	cout << fixed << setw(ancho);
	cout << "x" << "|";
	
	cout << fixed << setw(ancho);
	cout << "ESTRICTO" << "|";
	
	cout << fixed << setw(ancho);
	cout << BITS << "|"; 
	
	cout << fixed << setw(ancho);
	cout << "dec" << "|";
	
	cout << endl;
	
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
	int num_bits;
	
	string num_binario;
	string num_binario_estricto;
	
	string num_binario_simplificado;
	int num_decimal;
	
	
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
	
	//TABLA Y CÁLCULOS
	const int margen = 2;
	int ancho = num_bits + margen;
	
	if (ancho < 8){
		ancho = 8;
	}
	
	ComienzoTabla(ancho, num_bits);
	
		//Cálculo de valores
		for (int x = 0; x <= num_max; x++){
			num_binario_estricto = DecToBinEstricto(x);
			num_binario = DecToBin_Bits (x, num_bits);
			
			//Verifico que el número binario calculado es correcto
			bool binario_ok = EsBinario(num_binario);
			
			if (binario_ok){
				//Simplifico el número binario
				num_binario_simplificado = NumBinarioSimplificado(num_binario);
			
				//Paso a decimal
				num_decimal = BinToDec(num_binario_simplificado);
				
			} else {
				num_binario = "ERROR";
				num_binario_estricto = "ERROR";
				num_decimal = -1;
			}
			
			//SALIDA DE DATOS
			cout << "|";
			
			cout << fixed << setw(ancho);
			cout << x << "|";
			
			cout << fixed << setw(ancho);
			cout << num_binario_estricto << "|";
			
			cout << fixed << setw(ancho);
			cout << num_binario << "|";
			
			cout << fixed << setw(ancho);
			cout << num_decimal << "|";
			
			cout << endl;
			
		}

	return 0;
}
