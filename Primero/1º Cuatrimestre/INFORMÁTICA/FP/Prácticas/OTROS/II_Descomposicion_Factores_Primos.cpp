/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2 
/*	
	Calcular y mostrar la descomposición en factores primos de un número.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Entrada
	
	int valor; 
	
	do {
		cout << "Valor (>1) a descomponer: ";
		cin >> valor;
	} while (valor <= 1);

	
	// Calculos y resultado 
	
	int n; // Para copiar y salvaguardar "valor"
	
	/*
	Versión 1. 
	
	El resultado se muestra "en bruto" sin agrupar los primos. P.e.
			360 = 2 * 2 * 2 * 3 * 3 * 5
			121 = 11 * 11
			11 = 11			
	*/
	
	cout << endl; 
	cout << "--------------------------------------" << endl;
	cout << endl; 

	cout << valor << " = "; 

	n = valor; // copia para salvaguardar "valor"
			
	int candidato = 2; 
		
	while (n > 1) {
		
		while (n % candidato == 0) { // Es divisible --> considerar "candidato"
			
			cout << candidato; 
			
			n = n / candidato; // Actualizar "n"
				
			if (n > 1) cout << " * "; // evitar el último *
		}
		
		candidato++; // A por otro candidato a primo
	}
	

	/*
	Versión 2. 

	Se aagrupan los primos en forma de potencias. P.e. 
			360 = 2^3 * 3^2 * 5
			121 = 11^2
			11 = 11 		
	*/
	
	cout << endl; 
	cout << "--------------------------------------" << endl;
	cout << endl; 
	
	cout << valor << " = "; 

	n = valor; // copia para salvaguardar "valor"
		
	candidato = 2; 
		
	while (n > 1) {
		
		int veces_candidato = 0; 	// Contador de las veces que es divisible 
									// "n" por "candidato" 
									
		while (n % candidato == 0) { // Es divisible --> considerar "candidato"
		
			veces_candidato++; // Incrementar el contador
			n = n / candidato; // Actualizar "n"
		}
		
		if (veces_candidato > 0) { // No se muestran los valores no primos

			cout << candidato;  // base

			// Se escribe el exponente solo si es mayor que 1
			if (veces_candidato > 1) cout <<  "^" << veces_candidato;
			
			if (n > 1) cout << " * "; // evitar el último *
		}
	
		candidato++;  // A por otro candidato a primo
	}

	cout << endl; 
	cout << "--------------------------------------" << endl;
	cout << endl; 
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
