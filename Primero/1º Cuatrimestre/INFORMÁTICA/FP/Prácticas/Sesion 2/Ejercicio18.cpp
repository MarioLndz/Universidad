/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 15: Leed desde teclado tres variables correspondientes a un 
	número de horas, minutos y segundos, respectivamente. Diseñar un algoritmo 
	que calcule las horas, minutos y segundos dentro de su rango 
	correspondiente.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		int dias, horas, minutos, segundos, resto;
		
	//Recogida de datos
		cout << "Introduzca las horas: ";
		cin >> horas;
		
		cout << "Introduzca los minutos: ";
		cin >> minutos;
		
		cout << "Introduzca los segundos: ";
		cin >> segundos;
		
	//Cálculos
		resto = segundos / 60;
		segundos = segundos % 60;
		
		minutos += resto;
		resto = minutos / 60;
		minutos = minutos % 60;
		
		horas += resto;
		resto = horas / 24;
		horas = horas % 24;
		
		dias = resto;
		
	//Salida de datos
		cout << endl << "Tenemos " << dias << " días, " << horas << " horas, " 
		<< minutos << " minutos y " << segundos << " segundos" << endl;

	return 0;
}
