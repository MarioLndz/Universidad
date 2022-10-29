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

	
	// Cálculos
	
	int n; // Para copiar y salvaguardar "valor"
	
	string resultado1, resultado2; 
	
	/*
	Versión 1. 
	
	El resultado se muestra "en bruto" sin agrupar los primos. P.e.
			360 = 2 * 2 * 2 * 3 * 3 * 5
			121 = 11 * 11
			11 = 11			
	*/
	
	resultado1 += to_string(valor) + " = "; 

	n = valor; // copia para salvaguardar "valor"
			
	int candidato = 2; 
		
	while (n > 1) {
		
		while (n % candidato == 0) { // Es divisible --> considerar "candidato"
			
			resultado1 += to_string(candidato); 
			
			n = n / candidato; // Actualizar "n"
				
			if (n > 1) resultado1 += " * "; // evitar el último *
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
	
	resultado2 += to_string(valor) + " = "; 

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

			resultado2 += to_string(candidato); // base
			
			// Se escribe el exponente solo si es mayor que 1
			if (veces_candidato > 1) 
				resultado2 += " ^ " + to_string(veces_candidato);
			
			if (n > 1) resultado2 += " * "; // evitar el último *
		}
	
		candidato++;  // A por otro candidato a primo
	}


	// Resultados
	
	cout << endl; 
	cout << "--------------------------------------" << endl;
	cout << endl; 
	
	cout << resultado1 << endl; 
	cout << resultado2 << endl; 	
	
	cout << endl; 
	cout << "--------------------------------------" << endl;
	cout << endl; 
	
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
