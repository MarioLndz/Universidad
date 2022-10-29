/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 51 - II: Este programa calculará la CDF(x) para un valor de x 
	dado. El programa pedirá los parámetros que definen una función gaussiana 
	(esperanza y desviación) y el valor de la abscisa (x) para el que se va a 
	calcular CDF(x).
	
	Para el cálculo práctico de CDF(x) la integral se convierte en una suma, 
	y se requiere concretar cuántas sumas se van a realizar. Bastará con 
	indicar:
		a) Un valor inicial para x
		b) Un “salto” entre dos valores consecutivos de x 
		   (usaremos una constante)

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int main () {
	//Variables
	const double PI = 3.1415927;
	const double SALTO = 0.01;
	
	double esperanza, desviacion, x;
	
		
	//Recogida de datos
		//Esperanza
		cout << "Introduzca el valor de la esperanza o media: ";
		cin >> esperanza;
		
		//Desviación típica
		cout << "Introduzca el valor de la desviación típica: ";
		cin >> desviacion;
		
		while (desviacion < 0){
			cout << "ERROR: La desviación típica debe ser mayor o igual que 0. "
				 << "Vuelva a introducirla" << endl;
			
			cout << endl;
			cout << "Introduzca el valor de la desviación típica: ";
			cin >> desviacion;
		}
	
	cout << "Introduzca el valor de x: ";
	cin >> x;
	cout << endl;
		
	//Cálculos
	double x_inicial = esperanza - (3 * desviacion);	
	double imagen;
	double cfd = 0;
	
	//CORRECCIÓN
	double parte1 = (desviacion * sqrt (2 * PI));
	
	while (x_inicial <= x){
		
		/* ANTES *************************** 
		imagen = 
			exp ((-0.5) * pow (((x_inicial-esperanza) / desviacion), 2)) / 
			(desviacion * sqrt (2 * PI));
		cfd = cfd + imagen * SALTO;
		
		*********************************** */
		
		//Corrección
		imagen = 
			exp ((-0.5) * pow (((x_inicial-esperanza) / desviacion), 2));
		
		cfd += imagen;
		
		x_inicial += SALTO;
	}
	//CORRECIÓN
	cfd /= parte1;
	cfd *= SALTO;
	
	//Salida de datos
	cout << "La distribución acumulada o CFD en el punto x = " << x << " es: "
		 << cfd << endl;

	return 0;
}
