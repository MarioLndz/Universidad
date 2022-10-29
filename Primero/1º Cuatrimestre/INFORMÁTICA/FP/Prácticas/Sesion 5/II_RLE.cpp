/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 45 - II: Este programa leerá una secuencia de números naturales 
	terminada con un número negativo y la codificará mediante el método RLE

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>

using namespace std;

int main () {
	//Variables
	int digito;
	int digito_anterior;
	
	string salida;
	string tramo_anterior;
	const string SEPARADOR = " ";
	 
	int num_digitos = 0;
	
	//Cálculos
	cin >> digito;	/* 
					Como usaremos la redirección de entrada para introducir 
					los datos, no se explicará el funcionamiento del programa, 
					sino que directamente se pedirá introducir el dígito 
					*/
					
	
	while (digito >= 0) {
		if (digito == digito_anterior || num_digitos == 0){ 
				num_digitos++;
			
			} else { 
				salida = salida + tramo_anterior;
				
				num_digitos = 1;
				
			}
		tramo_anterior = to_string (num_digitos) + SEPARADOR +
						 to_string(digito) + SEPARADOR;
		
		digito_anterior = digito;
		
		cin >> digito;
	}
	
	/* Al salir del bucle, el último tramo no se añade a la cadena, por lo que
	debemos añadirlo antes de mostrarlo por pantalla */
	salida = salida + tramo_anterior;
	
	//Salida de datos
	cout << endl;
	cout << salida;
	
	return 0;
}

