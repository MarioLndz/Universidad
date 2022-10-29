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
		double segundos, velocidad;
		int minutos;
		
	//Recogida de datos
		cout << "Introduzca el valor de la velocidad en km/h: ";
		cin >> velocidad;
		
	//C�lculos
		minutos = 60 / velocidad;/*	Gracias a que minutos es entero nos 
									podemos quedar solo con la parte entera */
		segundos = ((60 / velocidad) - minutos) * 60;

	//Salida de datos
		cout << endl << "El atleta corre a " << minutos << " min y " 
		<< segundos << " segundos por kil�metro";

	return 0;
}
