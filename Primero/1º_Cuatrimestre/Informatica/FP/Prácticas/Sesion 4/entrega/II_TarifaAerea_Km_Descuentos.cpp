/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 5 - II: Una compa��a a�rea establece el precio del billete como 
	sigue:
		- La tarifa base de 150 euros, la misma para todos los destinos.
	
		1) Si el destino est� a menos de 300 kil�metros, el precio final es la 
		  tarifa base
	
		2) Para destinos a m�s de 300 Km, se suman 10 c�ntimos por cada 
		  kil�metro de distancia al destino
	
	Una vez calculada la tarifa se le aplicar�n los siguientes descuentos:
		a) Un primer descuento est� determinado por el n�mero de kil�metros 
		   del trayecto. Si el trayecto es mayor de 700 km, se aplica un 
		   descuento del 2%
		   
		b) El segundo descuento depender� del n�mero de puntos de la tarjeta 
		   de fidelizaci�n del cliente. Si el n�mero de puntos es mayor de 
		   100, se aplica un descuento del 3% y si es mayor de 200, se aplica 
		   un descuento del 4 %.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
using namespace std;

int main () {
	//Variables
		double precio_tarifa, kilometros;
		
		const double PRECIO_BASE = 150;
		
	//Recogida de datos
		cout << "Inserte el n�mero de kil�metros al destino: ";
		cin >> kilometros;
		
	//C�lculo de la tarifa
		if (kilometros < 300){		//Opci�n 1
			precio_tarifa = PRECIO_BASE;

		} else {					//Opci�n 2
			precio_tarifa = PRECIO_BASE + (kilometros * 0.10);

		}
	
		cout << "El precio del billete sin descuentos ser� de " 
		 	 << precio_tarifa << " euros" << endl << endl;
		 
	//Descuentos
		double descuento = 0;
		
		int puntos_fidelidad;
		
		cout << "Introduzca el n�mero de puntos de fidelidad que posee el "
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
		
	//C�lculos
		double precio_descuento;
		
		precio_descuento = (precio_tarifa * (100 - descuento)) / 100;
		
	//Salida
		cout << "El precio final del billete aplicando un " 
			 << descuento << "% de descuento ser� de " << precio_descuento 
			 << " euros" << endl;
	
	return 0;
}
