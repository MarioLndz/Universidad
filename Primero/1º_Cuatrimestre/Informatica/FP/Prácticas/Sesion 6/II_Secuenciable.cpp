/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 76 - II: Diremos que un número entero positivo es secuenciable si 
	se puede generar como suma de números consecutivos. Por ejemplo: 
		a) 6 = 1 + 2 + 3
		b) 15 = 7 + 8. 
		
	Esta descomposición no tiene por qué ser única. Por ejemplo 
		1) 15 = 7 + 8 
		2) 15 = 4 + 5 + 6 
		3) 15 = 1 + 2 + 3 + 4 + 5.
	
	Este programa leerá un entero y nos dirá cuántas 
	descomposiciones posibles tiene.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;

int main() {
    int entero;
	int contador = 0;
	
	int n;
	int sumatoria;

	/*******************************
			ENTRADA DE DATOS
	*******************************/
	do {
		cout << "Introduzca un número entero positivo: ";
	    cin >> entero;
	    
	    if (entero < 0){
	    	cout << "ERROR: El número introducido no es positivo." << endl;
	    	cout << endl;
		}
	} while (entero < 0);
	
	/*******************************
			CÁLCULOS
	*******************************/
    for (int i = 1; i <= (entero/2); i++){
    	n = i;
    	sumatoria = 0;
    	
		while (sumatoria < entero) {
			sumatoria += n;	
    		n++;
    		
		} 

    	if (sumatoria == entero){
    		contador++;
		}
	}
	
	/*******************************
			SALIDA
	*******************************/
    cout << "El " << entero << " tiene " << contador << " descomposiciones";

}
