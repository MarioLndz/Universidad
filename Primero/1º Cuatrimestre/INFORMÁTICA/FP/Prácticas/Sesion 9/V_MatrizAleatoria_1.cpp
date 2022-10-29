/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 45 - V: Suponga una matriz que puede guardar datos enteros cuyas 
	dimensiones son NUM_FILAS y NUM_COLS columnas. Queremos rellenar 
	completamente la matriz con todos los valores comprendidos entre 1 y 
	NUM_FILAS*NUM_COLS pero colocándolos en posiciones aleatorias. También 
	queremos saber cuántos intentos hemos necesitado para cada valor, el 
	total de intentos para llenar la matriz y cuál es la media de intentos 
	por valor.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
#include <iomanip>

#include <ctime>
#include <cstdlib>

using namespace std;


/*****************************************************************************/
int main () {
	const int NUM_FILAS = 5;
	const int NUM_COLUMNAS = 5;
	const int NUM_CASILLAS = NUM_FILAS * NUM_COLUMNAS;
	
	int matriz[NUM_FILAS][NUM_COLUMNAS];
	
	//Inicializamos todas las casillas de la matriz a 0
	for (int n = 0; n < NUM_FILAS; n++){
		for (int i = 0; i < NUM_COLUMNAS; i++){
			matriz [n][i] = 0;
		}
	}
	
	// -----------------------
	// CALCULOS
	
	time_t t;
	srand(time(&t)); 	// Inicializa el generador de núms. aleatorios
					 	// con el reloj del sistema (hora actual)
					 	
	string intentos;
	int num_intentos_total = 0;
	
	for (int n = 1; n <= NUM_CASILLAS; n++){
		int num_intentos = 0;
		bool continuar = true;
		
		do {
			int fila_r = rand() % NUM_FILAS;
			int columna_r = rand() % NUM_COLUMNAS;
			
			if (matriz[fila_r][columna_r] == 0){
				matriz[fila_r][columna_r] = n;
				continuar = false;
			}
			
			num_intentos++;
		} while (continuar);
		
		intentos += "\t" + to_string(num_intentos);
		//Cada 10 números añadiremos un salto de línea
		if (n%10 == 0){
			intentos += "\n";
		}
		
		num_intentos_total += num_intentos;
	}
	double media_intentos = num_intentos_total/(double)NUM_CASILLAS;
	
	// -----------------------
	//	SALIDA
	
	cout << "Intentos para alojar los valores:" << endl << endl;
	cout << intentos << endl << endl;
	
	cout << "Intentos totales = " << setw(4) << num_intentos_total << endl;
	cout << "Media = " << setw(4) << media_intentos << endl;
	
	cout << endl << endl;
	cout << "Matriz de valores:" << endl << endl;
	for (int n = 0; n < NUM_FILAS; n++){
		for (int i = 0; i < NUM_COLUMNAS; i++){
			cout << "  " << setw(3) << matriz [n][i];
		}
		cout << endl;
	}
	
	
	return 0;
}
