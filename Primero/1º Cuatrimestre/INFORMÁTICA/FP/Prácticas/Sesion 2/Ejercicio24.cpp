/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 20: [...] Realizar un programa que lea los coeficientes reales 
	(mu) y (sigma) de una funci�n gaussiana. A continuaci�n el programa leer� 
	un valor de abscisa x y se imprimir� el valor que toma la funci�n en x.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double esperanza, desviacion, x, resultado;
		const double PI = 3.1416, E = 2.71828;
		
	//Recogida de datos
		cout << "Introduzca el valor de la esperanza o media: ";
		cin >> esperanza;
		
		cout << "Introduzca el valor de la desviaci�n t�pica: ";
		cin >> desviacion;
		
		cout << "Introduzca el valor de x: ";
		cin >> x;
		
	//C�lculos
		resultado = (1 / (desviacion * sqrt (2 * PI))) * 
				pow (E, ((-0.5) * (pow (((x - esperanza) / desviacion), 2))));
		
	//Salida de datos
		cout << endl << "f(" << x << ") = " << resultado;

	return 0;
}
