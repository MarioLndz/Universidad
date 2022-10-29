/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 8: La compañía aérea del ejercicio 7 quiere aplicar una política 
	de descuentos al precio del billete. Amplíe el programa anterior para 
	después de imprimir el precio del billete pida un porcentaje de descuento 
	(dato double) y muestre el precio final después de aplicar el descuento 
	indicado.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double precio, kilometros, descuento;
		
	//Recogida de datos
		cout << "Inserte el número de kilómetros al destino: ";
		cin >> kilometros;
		
	//Cálculo 1
		precio = 150 + (0.10 * kilometros);
		
	//Precio sin descuento
		cout << "El precio actual del billete es de " << precio << " euros";
		cout << endl;
	
	//Recogida del descuento
		cout << endl << "Introduce el porcentaje de descuento a aplicar: ";
		cin >> descuento;
		
	//Cálculo 2
		precio = precio * ((100 - descuento)/100);
		
	//Precio con descuento
		cout << "El precio final del billete es de " << precio << " euros";
		
	return 0;
}
