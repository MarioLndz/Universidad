/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 23: Escribir un programa para calcular la media aritmética 
	muestral y la desviación estándar (o típica) muestral de las alturas de 
	tres personas
	
*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
		double altura1, altura2, altura3;
		double media, desviacion_tipica;
		
	//Recogida de datos
		cout << "Introduzca la altura de la primera persona: ";
		cin >> altura1;
		
		cout << "Introduzca la altura de la segunda persona: ";
		cin >> altura2;
		
		cout << "Introduzca la altura de la tercera persona: ";
		cin >> altura3;
		
	//Cálculos
		media = (altura1 + altura2 + altura3) / 3;
		
		desviacion_tipica = sqrt ((pow ((altura1 - media), 2) + 
		pow ((altura2 - media), 2) + pow ((altura3 - media), 2)) / 3);
		
	//Salida
		cout << endl << "La media es de " << media;
		cout << endl << "La desviación tipica es de " << desviacion_tipica;	
	
	return 0;
}
