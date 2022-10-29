/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 22: Queremos construir una expresi�n num�rica que desplace un 
	entero un n�mero dado de posiciones, pero lo mantenga dentro de un 
	intervalo.
	
*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		int minimo, maximo, desplazamiento, a_desplazar, posicion_final;
		
	//Recogida de datos
		cout << "Introduzca el valor m�nimo del intervalo: ";
		cin >> minimo;
		
		cout << "Introduzca el valor m�ximo del intervalo: ";
		cin >> maximo;

		cout << "Introduzca el n�mero de posiciones a desplazar (el valor del"
		<< " desplazamiento): ";
		cin >> desplazamiento;
		
		cout << "Introduzca el n�mero a desplazar: ";
		cin >> a_desplazar;
		
	//C�lculos
		posicion_final = a_desplazar + desplazamiento;
		
		//No se me ha ocurrido una forma de hacerlo sin utilizar "if"
		
		if (posicion_final > maximo) {
			posicion_final = (minimo - 1) + (posicion_final - maximo);
		}
		
	//Salida
		cout << endl << "La posici�n final es " << posicion_final;	
	
	return 0;
}
