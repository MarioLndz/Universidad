/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 45 - II: Este programa leer� una secuencia de n�meros naturales 
	terminada con un n�mero negativo y la codificar� mediante el m�todo RLE

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
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
	
	//C�lculos
	cin >> digito;	/* 
					Como usaremos la redirecci�n de entrada para introducir 
					los datos, no se explicar� el funcionamiento del programa, 
					sino que directamente se pedir� introducir el d�gito 
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
	
	/* Al salir del bucle, el �ltimo tramo no se a�ade a la cadena, por lo que
	debemos a�adirlo antes de mostrarlo por pantalla */
	salida = salida + tramo_anterior;
	
	//Salida de datos
	cout << endl;
	cout << salida;
	
	return 0;
}

