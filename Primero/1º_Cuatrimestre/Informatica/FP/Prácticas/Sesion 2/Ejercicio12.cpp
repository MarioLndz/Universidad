/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 12: Escribir un programa para una caja de un supermercado que 
	lea un precio desde el teclado y una cantidad (se supone que cantidad >= 
	precio) e indique el número de monedas de 1 euro, 50 céntimos, 10 céntimos, 
	5 céntimos y 1 céntimo que se deben dar de cambio. Se indicará el menor 
	número de monedas de cada clase

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double precio, cantidad, cambio, cent;
		int euro, L_cent, X_cent, V_cent;
		
	//Recogida de datos
		cout << "Introduzca el precio a pagar en euros: ";
		cin >> precio;
		
		cout << "Introduzca el dinero usado para pagar: ";
		cin >> cantidad;
		
	//Cálculos
		cambio = cantidad - precio;
		
		euro = cambio;
		cambio -= euro;
		
		L_cent = cambio/0.5;
		cambio -= (0.5*L_cent);
		
		X_cent = cambio/0.1;
		cambio -= (0.1 * X_cent);
		
		V_cent = cambio/0.05;
		cambio -= (0.05 * V_cent);
		
		cent = cambio / 0.01;
		
	//Salida de datos
		cout << endl << "Se dará de cambio:" << endl;
			cout << "\t" << euro << " monedas de 1 euro" << endl;
			cout << "\t" << L_cent << " monedas de 50 centimos" << endl;
			cout << "\t" << X_cent << " monedas de 10 centimos" << endl;
			cout << "\t" << V_cent << " monedas de 5 centimos" << endl;
			cout << "\t" << cent << " monedas de 1 centimo" << endl;

	return 0;
}
