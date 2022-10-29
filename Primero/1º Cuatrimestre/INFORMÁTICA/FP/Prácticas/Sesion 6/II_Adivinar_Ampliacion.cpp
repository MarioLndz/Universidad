/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 55 - II: Este programa servirá para jugar a adivinar un número. 
	En cada jugada el jugador introducirá un valor y el el juego indicará si el 
	número introducido por el jugador está por encima o por debajo del número 
	introducido.
	
	EL juego parará si se acierta o si no se quiere seguir jugando a adivinar 
	ese número (usaremos un valor especial -terminador- para esta opción).
	
	Una vez terminado un juego de adivinación se podrá volver a jugar:
	el programa pedirá si queremos volver a jugar o no.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S

#include<ctime>
#include<cstdlib>

using namespace std;

int main () {
	//Constantes
	const int MIN = 1;
	const int MAX = 100;
	const int NUM_VALORES = MAX-MIN + 1; // Número de valores posibles
	
	const int TERMINADOR = -1;
	
	//Variables
	time_t t;
	srand(time(&t)); 	// Inicializa el generador de núms. aleatorios
						// con el reloj del sistema (hora actual)
	int incognita; 		// Número aleatorio que se genera
	
	int numero;
	bool adivinado;
	bool terminar;
	
	char opcion;
	
	/***************************************
					PROGRAMA
	**************************************/
	
	cout << "Intente adivinar un número del " << MIN << " al " << MAX << endl;
	cout << "El programa te dirá si el número introducido se encuentra por "
		 << "encima o por debajo del número a adivinar" << endl;
	cout << "Si desea parar de jugar en cualquier momento, escriba el "
		 << TERMINADOR << endl;
	
	do {	//"Nueva partida"
		// Generación de "incognita" (MIN <= incognita <= MAX)
		incognita = (rand() % NUM_VALORES) + MIN;
		
		adivinado = false;
		terminar = false;
		
		do {	//Juego
			do {	//Introducción de la predicción
				
				cout << endl;
				cout << "Predicción: ";
				cin >> numero;
				
				if (numero == TERMINADOR){
					terminar = true;
					
				} else if (numero < MIN || numero > MAX){
					cout << "ERROR: Valor fuera del intervalo" << endl;
					
				}
				
			} while ((numero < MIN || numero > MAX) && !terminar);
			
			if (!terminar){
				if (numero < incognita){
					cout << "El " << numero << " está por debajo" << endl;
					
				} else if (numero > incognita) {
					cout << "El " << numero << " está por encima" << endl;
					
				} else {
					adivinado = true;
				}
				
			}
		} while (!adivinado && !terminar); //Fin de Juego
		
		if (adivinado){
			cout << "¡Enhorabuena, has acertado!" << endl;	
		}
		
		do {	//Reiniciar juego?
			cout << endl;
			cout << "¿Desea volver a jugar? (S/N): ";
			cin >> opcion;
			opcion = toupper(opcion);
			
			if (opcion != 'S' && opcion != 'N'){
				cout << "Caracter no valido" << endl;
			}
		
		} while (opcion != 'S' && opcion != 'N');
	
	} while (opcion == 'S');
	
	return 0;
}
