/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 7: Una compa��a a�rea establece el precio del billete como sigue: 
	en primer lugar se fija una tarifa base de 150 euros, la misma para todos 
	los destinos. A continuaci�n se suman 10 c�ntimos por cada kil�metro de 
	distancia al destino. Cree un programa que lea el n�mero de kil�metros al 
	destino y calcule el precio final del billete.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double precio_final, kilometros;
		
	//Recogida de datos
		cout << "Inserte el n�mero de kil�metros al destino: ";
		cin >> kilometros;
		
	//C�lculos
		precio_final = 150 + (0.10 * kilometros);
		
	//Salida
		cout << endl;
		cout << "El precio final del billete es de " << precio_final; 
		cout << " euros";
		
	return 0;
}
