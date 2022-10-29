/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 13 - III: Este programa probará el funcionamiento de dos 
	funciones:
		a) 	Definiremos la función Redondea, que nos servirá para redondear un 
			número real introducido por el usuario al número de decimales 
			indicado.
		b) 	Definiremos la función Trunca para truncar un número real usando un 
			número de cifras decimales dado.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;

double Potencia (double base, double exponente){
	double resultado = 1;
	
	if (exponente > 0){
		for (int n = 0; n < exponente; n++){
			resultado = resultado * base;					
		}
		
	} else if (exponente < 0){
		for (int n = 0; n > exponente; n--){
			resultado = resultado * (1/base);
		}
	}
	
	return resultado;
}


double Redondea (double numero, int decimales){
	double desplazamiento = Potencia(10, decimales);
	double num_aux = numero * desplazamiento;
	
	double resultado = (int) num_aux;
	double parte_decimal = num_aux - resultado;
	const double umbral_redondeo = 0.5;
	
	if (parte_decimal >= umbral_redondeo){
		resultado++;
	}
	
	resultado = resultado / desplazamiento;
	
	return resultado;
}

double Trunca (double numero, int decimales){
	double desplazamiento = Potencia(10, decimales);
	double resultado;
	
	numero = numero * desplazamiento;

	resultado = (int) numero / desplazamiento;

	return resultado;
}


int main () {
	//Variables
	double numero;
	int cifras_decimales;
	
	/***************************************	
			REDONDEO
	***************************************/
	//ENTRADA DE DATOS
	cout << "Introduzca un número real: ";
	cin >> numero;
	
	do {
		cout << "Número de decimales a redondear: ";
		cin >> cifras_decimales;
		
		if (cifras_decimales < 0){
			cout << "ERROR: Debe ser mayor o igual que 0." << endl << endl;
		}	
	} while (cifras_decimales < 0);
	
	//CÁLCULOS
	double num_redondeado = Redondea(numero, cifras_decimales);
	
	//SALIDA
	cout << "El número redondeado es " << num_redondeado << endl << endl;
	
	/***************************************	
			TRUNCAMIENTO
	***************************************/
	//ENTRADA DE DATOS
	cout << "Introduzca un número real: ";
	cin >> numero;
	
	do {
		cout << "Número de decimales a truncar: ";
		cin >> cifras_decimales;
		
		if (cifras_decimales < 0){
			cout << "ERROR: Debe ser mayor o igual que 0." << endl << endl;
		}	
	} while (cifras_decimales < 0);
	
	//CÁLCULOS
	double num_truncado = Trunca(numero, cifras_decimales);
	
	//SALIDA
	cout << "El número truncado es " << num_truncado << endl;
	
	return 0;
}
