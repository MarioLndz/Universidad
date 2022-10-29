/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 8: La compa��a a�rea del ejercicio 7 quiere aplicar una pol�tica 
	de descuentos al precio del billete. Ampl�e el programa anterior para 
	despu�s de imprimir el precio del billete pida un porcentaje de descuento 
	(dato double) y muestre el precio final despu�s de aplicar el descuento 
	indicado.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double precio, kilometros, descuento;
		
	//Recogida de datos
		cout << "Inserte el n�mero de kil�metros al destino: ";
		cin >> kilometros;
		
	//C�lculo 1
		precio = 150 + (0.10 * kilometros);
		
	//Precio sin descuento
		cout << "El precio actual del billete es de " << precio << " euros";
		cout << endl;
	
	//Recogida del descuento
		cout << endl << "Introduce el porcentaje de descuento a aplicar: ";
		cin >> descuento;
		
	//C�lculo 2
		precio = precio * ((100 - descuento)/100);
		
	//Precio con descuento
		cout << "El precio final del billete es de " << precio << " euros";
		
	return 0;
}
