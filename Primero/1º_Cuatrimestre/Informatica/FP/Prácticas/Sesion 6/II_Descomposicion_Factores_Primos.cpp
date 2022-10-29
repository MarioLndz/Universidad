/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 47 - II: Este programa leerá un número entero positivo y mostrará
	su descomposición en factores primos. El resultado se mostrará de dos
	maneras. 
		a) La primera consistirá en enumerar todos los primos de la 
		descomposición (en el caso de que un primo intervenga más de una vez se 
		mostrará tantas veces como sea preciso).
		
		b) La segunda consistirá en expresar el resultado como el producto de 
		potencias (en el caso de que un primo intervenga más de una vez se 
		mostrará una potencia cuya base sea el valor del primo y el exponente 
		será el número de veces que se repite). Evitaremos potencias triviales 
		(de exponente 1) escribiendo, en ese caso, únicamente la base (el valor 
		del primo).

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
#include <cmath>

using namespace std;

bool EsPrimo (int valor){
	bool es_primo;
	int divisor;
	
	es_primo = true;
	for (divisor = 2 ; divisor < valor && es_primo ; divisor++){
		if (valor % divisor == 0){
			es_primo = false;
		}
	}
			
	return es_primo;
}

int main () {
	//Variables
	int numero;
	
	/*****************************
			ENTRADA
	*****************************/
	do {
		cout << "Introduzca un número entero positivo: ";
		cin >> numero;
		
		//Mensaje de error (cuando el numero introducido es negativo)
		if (numero < 0){
			cout << "ERROR: El número introducido no es positivo" << endl
				 << endl;
			
		}
		
	} while (numero < 0);
	
	/*****************************
			CÁLCULOS
	*****************************/
	int posible_primo;	
	int num_aux;
	
	string resultado1 = to_string(numero) + " = ";
	
	int exponente;
	string resultado2 = to_string(numero) + " = ";
	
	//Método 1
	if (numero == 0){
		resultado1 += '0';
		resultado2 = resultado1;
		
	} else {
		for (posible_primo = 2; posible_primo <= numero; posible_primo++){
			num_aux = numero;
		
			if (EsPrimo(posible_primo)) {	//Comprueba que es un número primo
				// Comprobamos si el primo con el que estamos trabajando es un 
				// divisor
				while (num_aux % posible_primo == 0) {
					resultado1 += to_string(posible_primo) + " * ";
					
					num_aux = num_aux / posible_primo;
				}
			}
		}
		
		//Método 2
		
		for (posible_primo = 2; posible_primo <= numero; posible_primo++){
			num_aux = numero;
			exponente = 0;
			
			if (EsPrimo (posible_primo)){
				while (num_aux % posible_primo == 0) {
					exponente += 1;
					
					num_aux = num_aux / posible_primo;
				}
				
				if (exponente == 1){	//Si el exponente es 1, lo omitiremos
					resultado2 += to_string(posible_primo) + " * ";
				
				} else if (exponente != 0){
					resultado2 += to_string(posible_primo) + "^" + 
						  		  to_string(exponente) + " * ";
					
				}
			}
		}
		
		// Eliminaremos los 3 últimos caracteres de cada cadena, 
		// correspondientes al símbolo del producto " * "
		for (int n = 0; n < 3; n++) {
			resultado1.pop_back();
			resultado2.pop_back();
		}
	}
	
	
	/*****************************
			SALIDA DE DATOS
	*****************************/
		//Forma 1
		cout << "MÉTODO 1" << endl;
		cout << resultado1 << endl;
		
		//Forma 2
		cout << endl;
		cout << "MÉTODO 2" << endl;
		
		cout << resultado2 << endl;
		
	return 0;
}
