/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 7: Una compañía aérea establece el precio del billete como sigue: 
	en primer lugar se fija una tarifa base de 150 euros, la misma para todos 
	los destinos. A continuación se suman 10 céntimos por cada kilómetro de 
	distancia al destino. Cree un programa que lea el número de kilómetros al 
	destino y calcule el precio final del billete.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double precio_final, kilometros;
		
	//Recogida de datos
		cout << "Inserte el número de kilómetros al destino: ";
		cin >> kilometros;
		
	//Cálculos
		precio_final = 150 + (0.10 * kilometros);
		
	//Salida
		cout << endl;
		cout << "El precio final del billete es de " << precio_final; 
		cout << " euros";
		
	return 0;
}
