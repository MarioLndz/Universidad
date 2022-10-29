/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 16: Escriba un programa que calcule el consumo de gasolina. 
	Pedirá la distancia recorrida (en kms), los litros de gasolina consumidos y 
	los litros que quedan en el depósito. El programa debe informar el consumo 
	en km/litro, los litros/100 km y cuantos kilómetros de autonomía le restan 
	con ese nivel de consumo.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double distancia, litros_consumidos, litros_deposito;
		double km_litro, litro_100km, autonomia;
		
	//Recogida de datos
		cout << "Introduzca la distancia recorrida en km: ";
		cin >> distancia;
		
		cout << "Introduzca los litros de gasolina consumidos: ";
		cin >> litros_consumidos;
		
		cout << "Introduzca los litros de gasolina que quedan en el depósito: ";
		cin >> litros_deposito;
		
	//Cálculos
		km_litro = distancia / litros_consumidos;
		
		litro_100km = (100 * litros_consumidos) / distancia;
		
		autonomia = litros_deposito * km_litro;
		
	//Salida
		cout << endl << "El consumo es de " << km_litro << " km/litro ó de " 
		<< litro_100km << " litro/100 km";
		
		cout << endl << "Con " << litros_deposito << " litros en el depósito" 
		<< " se tendrá una autonomía de " << autonomia << " km";
		
	
	return 0;
}
