/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 17: Queremos construir un programa que simule un juego inspirado 
	en el de los triles (del que procede el nombre de trilero). Suponemos que 
	hay dos participantes y cada uno tiene una caja etiquetada con su nombre. 
	Dentro de cada caja hay una cantidad de dinero y el objetivo es 
	intercambiar las cantidades que hay dentro.
	
*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double caja_izda, caja_dcha, control;
		
	//Recogida de datos
		cout << "Introduzca la cantidad de dinero en la caja izquierda: ";
		cin >> caja_izda;
		
		cout << "Introduzca la cantidad de dinero en la caja derecha: ";
		cin >> caja_dcha;
		
	//Cálculos
		control = caja_dcha;
		caja_dcha = caja_izda;
		caja_izda = control;
		
		/* ***************************************************************
			Para realizar este ejercicio me he ayudado de una variable de
			control que tendrá el valor inicial de la caja derecha para
			"guardar" ese valor y poder asignárselo luego a la caja izquierda
		****************************************************************** */
		
	//Salida
		cout << endl << "La caja derecha vale " << caja_dcha << " euros";
		cout << endl << "La caja izquierda vale " << caja_izda << " euros";		
	
	return 0;
}
