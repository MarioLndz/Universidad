/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 55 - II: Este programa servir� para jugar a adivinar un n�mero. 
	En cada jugada el jugador introducir� un valor y el el juego indicar� si el 
	n�mero introducido por el jugador est� por encima o por debajo del n�mero 
	introducido.
	
	EL juego parar� si se acierta o si no se quiere seguir jugando a adivinar 
	ese n�mero (usaremos un valor especial -terminador- para esta opci�n).
	
	Una vez terminado un juego de adivinaci�n se podr� volver a jugar:
	el programa pedir� si queremos volver a jugar o no.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S

#include<ctime>
#include<cstdlib>

using namespace std;

int main () {
	//Constantes
	const int MIN = 1;
	const int MAX = 100;
	const int NUM_VALORES = MAX-MIN + 1; // N�mero de valores posibles
	
	const int TERMINADOR = -1;
	
	//Variables
	time_t t;
	srand(time(&t)); 	// Inicializa el generador de n�ms. aleatorios
						// con el reloj del sistema (hora actual)
	int incognita; 		// N�mero aleatorio que se genera
	
	int numero;
	bool adivinado;
	bool terminar;
	
	char opcion;
	
	/***************************************
					PROGRAMA
	**************************************/
	
	cout << "Intente adivinar un n�mero del " << MIN << " al " << MAX << endl;
	cout << "El programa te dir� si el n�mero introducido se encuentra por "
		 << "encima o por debajo del n�mero a adivinar" << endl;
	cout << "Si desea parar de jugar en cualquier momento, escriba el "
		 << TERMINADOR << endl;
	
	do {	//"Nueva partida"
		// Generaci�n de "incognita" (MIN <= incognita <= MAX)
		incognita = (rand() % NUM_VALORES) + MIN;
		
		adivinado = false;
		terminar = false;
		
		do {	//Juego
			do {	//Introducci�n de la predicci�n
				
				cout << endl;
				cout << "Predicci�n: ";
				cin >> numero;
				
				if (numero == TERMINADOR){
					terminar = true;
					
				} else if (numero < MIN || numero > MAX){
					cout << "ERROR: Valor fuera del intervalo" << endl;
					
				}
				
			} while ((numero < MIN || numero > MAX) && !terminar);
			
			if (!terminar){
				if (numero < incognita){
					cout << "El " << numero << " est� por debajo" << endl;
					
				} else if (numero > incognita) {
					cout << "El " << numero << " est� por encima" << endl;
					
				} else {
					adivinado = true;
				}
				
			}
		} while (!adivinado && !terminar); //Fin de Juego
		
		if (adivinado){
			cout << "�Enhorabuena, has acertado!" << endl;	
		}
		
		do {	//Reiniciar juego?
			cout << endl;
			cout << "�Desea volver a jugar? (S/N): ";
			cin >> opcion;
			opcion = toupper(opcion);
			
			if (opcion != 'S' && opcion != 'N'){
				cout << "Caracter no valido" << endl;
			}
		
		} while (opcion != 'S' && opcion != 'N');
	
	} while (opcion == 'S');
	
	return 0;
}
