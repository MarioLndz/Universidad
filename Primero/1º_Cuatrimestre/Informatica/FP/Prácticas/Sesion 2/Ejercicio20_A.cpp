/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 20: En atletismo se expresa la rapidez de un atleta en t�rminos 
	de ritmo (minutos y segundos por kil�metro) m�s que en unidades de 
	velocidad (kil�metros por hora). Escribid dos programas para convertir 
	entre estas dos medidas:
		a) El primero leer� el ritmo (minutos y segundos, por separado) y 
		mostrar� la velocidad (kil�metros por hora).
		b) El segundo leer� la velocidad (kil�metros por hora) y mostrar� el 
		ritmo (minutos y segundos).

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double minutos, segundos, velocidad;
		
	//Recogida de datos
		cout << "Introduzca el valor del ritmo: ";
		
		cout << endl << "\t Introduzca los minutos: ";
		cin >> minutos;
		
		cout << "\t Introduzca los segundos: ";
		cin >> segundos;
		
	//C�lculos
		velocidad = 60 / (minutos + (segundos / 60));
		
	//Salida de datos
		cout << endl << "El atleta corre a " << velocidad << "km/h";

	return 0;
}
