/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 20: [...] Realizar un programa que lea los coeficientes reales 
	(mu) y (sigma) de una función gaussiana. A continuación el programa leerá 
	un valor de abscisa x y se imprimirá el valor que toma la función en x.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double esperanza, desviacion, x, resultado;
		const double PI = 3.1416, E = 2.71828;
		
	//Recogida de datos
		cout << "Introduzca el valor de la esperanza o media: ";
		cin >> esperanza;
		
		cout << "Introduzca el valor de la desviación típica: ";
		cin >> desviacion;
		
		cout << "Introduzca el valor de x: ";
		cin >> x;
		
	//Cálculos
		resultado = (1 / (desviacion * sqrt (2 * PI))) * 
				pow (E, ((-0.5) * (pow (((x - esperanza) / desviacion), 2))));
		
	//Salida de datos
		cout << endl << "f(" << x << ") = " << resultado;

	return 0;
}
