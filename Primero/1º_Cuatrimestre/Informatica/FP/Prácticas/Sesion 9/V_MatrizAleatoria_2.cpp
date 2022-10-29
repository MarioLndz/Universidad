/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 46 - V: Este programa rellenará y mostrará una matriz con valores
	en un rango previamente determinado. Después calculará cuántas veces 
	aparece cada valor y realizará una prueba de integridad (mostrando el 
	resultado).
	
	La prueba consiste en comprobar si la suma de las apariciones de los 
	posibles valores que se pueden generar coincide con la cantidad de valores 
	de la matriz.
	
	Finalmente mostrará para cada uno de los potenciales valores que pueden 
	generarse cuántas veces aparece y en qué porcentaje sobre el total.

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
	const int NUM_COLUMNAS = 3;
	const int NUM_CASILLAS = NUM_FILAS * NUM_COLUMNAS;
	
	int matriz[NUM_FILAS][NUM_COLUMNAS];
	
	//Inicializamos todas las casillas de la matriz a 0
	for (int n = 0; n < NUM_FILAS; n++){
		for (int i = 0; i < NUM_COLUMNAS; i++){
			matriz [n][i] = 0;
		}
	}
	
	const int MIN_VALOR = 2;
	const int MAX_VALOR = 12;
	const int NUM_VALORES = (MAX_VALOR + 1) - MIN_VALOR;
	
	// -----------------------
	// CALCULOS
	
	time_t t;
	srand(time(&t)); 	// Inicializa el generador de núms. aleatorios
					 	// con el reloj del sistema (hora actual)
	
	//Calculamos la matriz de valores aleatorios	
	for (int n = 1; n <= NUM_CASILLAS; n++){
		bool continuar = true;
		
		int valor = MIN_VALOR + (rand() % NUM_VALORES);
		
		do {
			int fila_r = rand() % NUM_FILAS;
			int columna_r = rand() % NUM_COLUMNAS;
			
			if (matriz[fila_r][columna_r] == 0){
				matriz[fila_r][columna_r] = valor;
				continuar = false;
				
			}
		} while (continuar);
	}
	
	int frecuencias[NUM_VALORES];
	
	//Inicializamos el vector
	for (int i = 0; i < NUM_VALORES; i++){
			frecuencias[i] = 0;
	}
	
	for (int n = 0; n < NUM_FILAS; n++){
		for (int i = 0; i < NUM_COLUMNAS; i++){
			//El valor minimo ocupara la posicion 0, por lo que el valor
			//x ocupara la posicion x - MIN_VALOR
			int x = (matriz[n][i] - MIN_VALOR);
			frecuencias[x]++;
		}
	}
	
	//Sumamos todas las apariciones de algun numero y comprobamos si coincide
	//con el numero de elementos de la matriz (NUM_CASILLAS)
	int suma = 0;
	for (int n = 0; n < NUM_VALORES; n++){
		suma += frecuencias[n];
	}
	
	bool integridad = (suma == NUM_CASILLAS);
	
	
	double porcentajes[NUM_VALORES];

	//Inicializamos el vector
	for (int i = 0; i < NUM_VALORES; i++){
			porcentajes[i] = 0;
	}
	
	if (integridad){
		for (int n = 0; n < NUM_VALORES; n++){
			int num_apariciones = frecuencias[n];
			porcentajes[n] = ((num_apariciones/(double)NUM_CASILLAS) * 100);
		}
	}
	
	// -----------------------
	//	SALIDA
	
	cout << "Generando numeros entre " << setw(3) << MIN_VALOR << " y "
		 << setw(3) << MAX_VALOR << endl << endl;
	
	cout << "Matriz de valores:" << endl << endl;
	for (int n = 0; n < NUM_FILAS; n++){
		for (int i = 0; i < NUM_COLUMNAS; i++){
			cout << "  " << setw(3) << matriz [n][i];
		}
		cout << endl;
	}
	cout << endl;
	
	if (integridad){
		cout << "Integridad verificada" << endl << endl;
		
		cout << "Repeticiones:" << endl << endl;
		
		int valor = MIN_VALOR;
		for (int n = 0; n < NUM_VALORES; n++){
			cout << setw(3) << valor << ": " << setw(5) << frecuencias[n]
				 << "  " << fixed << setw(5) << setprecision(2) 
				 << porcentajes[n] << " %" << endl;
			
			valor++;
		}
	} else {
		cout << "Ha ocurrido un error en el programa. Integridad NO verificada"
			 << endl;
	}
	
	return 0;
}
