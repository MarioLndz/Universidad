/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 16: Escriba un programa que calcule el consumo de gasolina. 
	Pedir� la distancia recorrida (en kms), los litros de gasolina consumidos y 
	los litros que quedan en el dep�sito. El programa debe informar el consumo 
	en km/litro, los litros/100 km y cuantos kil�metros de autonom�a le restan 
	con ese nivel de consumo.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
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
		
		cout << "Introduzca los litros de gasolina que quedan en el dep�sito: ";
		cin >> litros_deposito;
		
	//C�lculos
		km_litro = distancia / litros_consumidos;
		
		litro_100km = (100 * litros_consumidos) / distancia;
		
		autonomia = litros_deposito * km_litro;
		
	//Salida
		cout << endl << "El consumo es de " << km_litro << " km/litro � de " 
		<< litro_100km << " litro/100 km";
		
		cout << endl << "Con " << litros_deposito << " litros en el dep�sito" 
		<< " se tendr� una autonom�a de " << autonomia << " km";
		
	
	return 0;
}
