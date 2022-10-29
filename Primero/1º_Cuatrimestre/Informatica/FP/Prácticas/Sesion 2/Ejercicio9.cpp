/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 9: [...] Escribir un programa que calcule y muestre el tiempo 
	umbral de sanción, o sea, el tiempo mínimo en segundos que puede emplear 
	un vehículo en recorrer el tramo completo sin ser sancionado.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double km1 = 5.3, v1 = 80;		//Tramo 1
		double km2 = 8.1, v2 = 100;		//Tramo 2
		double km3 = 6.4, v3 = 80;		//Tramo 3
		double tiempo;
		
	//Cálculos
		tiempo = km1 / v1;
		tiempo = tiempo + (km2 / v2);
		tiempo = tiempo + (km3 / v3);	
		
		//Paso el tiempo de horas a segundos
			tiempo = tiempo * 3600;
		
	//Salida de datos
		cout << "El tiempo umbral en este tramo es de " << tiempo;
		cout << " segundos";
		
	return 0;
}
