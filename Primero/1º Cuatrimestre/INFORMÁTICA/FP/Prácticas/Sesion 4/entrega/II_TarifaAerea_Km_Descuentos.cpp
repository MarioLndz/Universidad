/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 5 - II: Una compañía aérea establece el precio del billete como 
	sigue:
		- La tarifa base de 150 euros, la misma para todos los destinos.
	
		1) Si el destino está a menos de 300 kilómetros, el precio final es la 
		  tarifa base
	
		2) Para destinos a más de 300 Km, se suman 10 céntimos por cada 
		  kilómetro de distancia al destino
	
	Una vez calculada la tarifa se le aplicarán los siguientes descuentos:
		a) Un primer descuento está determinado por el número de kilómetros 
		   del trayecto. Si el trayecto es mayor de 700 km, se aplica un 
		   descuento del 2%
		   
		b) El segundo descuento dependerá del número de puntos de la tarjeta 
		   de fidelización del cliente. Si el número de puntos es mayor de 
		   100, se aplica un descuento del 3% y si es mayor de 200, se aplica 
		   un descuento del 4 %.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;

int main () {
	//Variables
		double precio_tarifa, kilometros;
		
		const double PRECIO_BASE = 150;
		
	//Recogida de datos
		cout << "Inserte el número de kilómetros al destino: ";
		cin >> kilometros;
		
	//Cálculo de la tarifa
		if (kilometros < 300){		//Opción 1
			precio_tarifa = PRECIO_BASE;

		} else {					//Opción 2
			precio_tarifa = PRECIO_BASE + (kilometros * 0.10);

		}
	
		cout << "El precio del billete sin descuentos será de " 
		 	 << precio_tarifa << " euros" << endl << endl;
		 
	//Descuentos
		double descuento = 0;
		
		int puntos_fidelidad;
		
		cout << "Introduzca el número de puntos de fidelidad que posee el "
			 << "cliente: ";
		cin >> puntos_fidelidad;
		
		//Descuento A
			if (kilometros > 700) {
			descuento += 2;
			
			}
		
		//Descuento B
			if (puntos_fidelidad > 200){
				descuento += 4;
			
			} else if (puntos_fidelidad > 100){
				descuento += 3;
			
			}
		
	//Cálculos
		double precio_descuento;
		
		precio_descuento = (precio_tarifa * (100 - descuento)) / 100;
		
	//Salida
		cout << "El precio final del billete aplicando un " 
			 << descuento << "% de descuento será de " << precio_descuento 
			 << " euros" << endl;
	
	return 0;
}
