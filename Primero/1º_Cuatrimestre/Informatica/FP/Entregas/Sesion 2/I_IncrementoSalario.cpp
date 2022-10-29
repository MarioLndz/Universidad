/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 11: Construya un programa para leer el valor de una variable 
	salario_base de tipo double, la incremente un 2% e imprima el resultado 
	en pantalla.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double salario_base, salario_final;
		
	//Recogida de datos
		cout << "Introduzca el valor del salario base: ";
		cin >> salario_base;
		
	//Cálculos
		salario_final = salario_base * 1.02;
		
	//Salida de datos
		cout << endl << "El salario final es de " << salario_final;


	/* *********************************************************************
		He decidido usar la opción b para realizar este ejercicio, es decir, he
		realizado el ejercicio usando una variable llamada "salario_final". Lo
		he hecho de esta forma debido a que así puedo tener más control acerca 
		del valor de la variable "salario_base" y no modificarla. En este 
		ejercicio quizás no hubiera habido inconveniente en cambiar su valor,
		pues es una operación sencilla, pero en otros ejercicios más complejos 
		es importante tener ese control	sobre el valor de las variables que 
		utilices para no complicar los cálculos.
	************************************************************************ */
	
	return 0;
}
