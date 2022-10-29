/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 76 - II: Diremos que un n�mero entero positivo es secuenciable si 
	se puede generar como suma de n�meros consecutivos. Por ejemplo: 
		a) 6 = 1 + 2 + 3
		b) 15 = 7 + 8. 
		
	Esta descomposici�n no tiene por qu� ser �nica. Por ejemplo 
		1) 15 = 7 + 8 
		2) 15 = 4 + 5 + 6 
		3) 15 = 1 + 2 + 3 + 4 + 5.
	
	Este programa leer� un entero y nos dir� cu�ntas 
	descomposiciones posibles tiene.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S

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
		cout << "Introduzca un n�mero entero positivo: ";
	    cin >> entero;
	    
	    if (entero < 0){
	    	cout << "ERROR: El n�mero introducido no es positivo." << endl;
	    	cout << endl;
		}
	} while (entero < 0);
	
	/*******************************
			C�LCULOS
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
