/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 43 - II: Este programa calculará cuándo se produjo la mayor 
	secuencia de días consecutivos con temperaturas crecientes. Se leerá una 
	secuencia de reales representando temperaturas y se calculará la 
	subsecuencia de números ordenada, de menor a mayor, de mayor 
	longitud. El programa nos debe decir la posición donde comienza la 
	subsecuencia y su longitud.
	
	La lectura de datos finalizará cuando se introduce un valor fuera de un 
	rango establecido entre los valores MIN_TEMP_VALIDA y MAX_TEMP_VALIDA.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;

int main () {
	//Constantes
	const double MIN_TEMP_VALIDA = -50;
	const double MAX_TEMP_VALIDA = 50; 
	
	//Variables
	double temperatura;
	double temperatura_anterior = MIN_TEMP_VALIDA;
	
	double inicio_subsecuencia, final_subsecuencia;
	double inicio_subsecuencia_mayor, final_subsecuencia_mayor;
	 
	int longitud = 0;
	int longitud_max = -1;
	
	int posicion = 0;
	int posicion_inicio, posicion_inicio_secuencia_mayor;
	
	//Información de uso
	cout << "La lectura de datos se interrumpirá cuando se introduzca un dato " 
		 << "fuera del intervalo [" << MIN_TEMP_VALIDA << ", " 
		 << MAX_TEMP_VALIDA << "]" << endl;
	
	//Entrada de datos
	cout << endl;
	cout << "Introduzca la secuencia de temperaturas: " << endl; 
	cin >> temperatura;
	
	//Cálculos
	inicio_subsecuencia = temperatura;
	
	while (temperatura >= MIN_TEMP_VALIDA && temperatura <= MAX_TEMP_VALIDA) {
		posicion++;
		
		if (temperatura >= temperatura_anterior){
			longitud++;
			final_subsecuencia = temperatura;
			
			//Guardamos los datos de la subsecuencia mayor
			if (longitud > longitud_max){
				longitud_max = longitud;
				inicio_subsecuencia_mayor = inicio_subsecuencia;
				final_subsecuencia_mayor = final_subsecuencia;
				posicion_inicio_secuencia_mayor = posicion_inicio;
			
			}
			
		} else {	//"Reiniciamos" la subsecuencia
			inicio_subsecuencia = temperatura;
			posicion_inicio = posicion;
			longitud = 1;
		}
		
		temperatura_anterior = temperatura;
		
		cin >> temperatura;
		
	} 
	
	//Salida de datos
	if (posicion != 0){
		cout << endl;
		cout << "La mayor subsecuencia empieza en la posición " 
		 	 << posicion_inicio_secuencia_mayor << " (en el " 
		 	 << inicio_subsecuencia_mayor << ") y tiene longitud "
		 	 << longitud_max << " (termina en " << final_subsecuencia_mayor 
			 << ")";
			 
	} else {
		cout << endl;
		cout << "La primera temperatura no está dentro del intervalo, por lo "
			 << "que no se ha producido la lectura de ningún dato";
	}
	
	return 0;
}
