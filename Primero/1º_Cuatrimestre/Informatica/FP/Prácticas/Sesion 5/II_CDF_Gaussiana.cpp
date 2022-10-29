/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 51 - II: Este programa calcular� la CDF(x) para un valor de x 
	dado. El programa pedir� los par�metros que definen una funci�n gaussiana 
	(esperanza y desviaci�n) y el valor de la abscisa (x) para el que se va a 
	calcular CDF(x).
	
	Para el c�lculo pr�ctico de CDF(x) la integral se convierte en una suma, 
	y se requiere concretar cu�ntas sumas se van a realizar. Bastar� con 
	indicar:
		a) Un valor inicial para x
		b) Un �salto� entre dos valores consecutivos de x 
		   (usaremos una constante)

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
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
		
		//Desviaci�n t�pica
		cout << "Introduzca el valor de la desviaci�n t�pica: ";
		cin >> desviacion;
		
		while (desviacion < 0){
			cout << "ERROR: La desviaci�n t�pica debe ser mayor o igual que 0. "
				 << "Vuelva a introducirla" << endl;
			
			cout << endl;
			cout << "Introduzca el valor de la desviaci�n t�pica: ";
			cin >> desviacion;
		}
	
	cout << "Introduzca el valor de x: ";
	cin >> x;
	cout << endl;
		
	//C�lculos
	double x_inicial = esperanza - (3 * desviacion);	
	double imagen;
	double cfd = 0;
	
	//CORRECCI�N
	double parte1 = (desviacion * sqrt (2 * PI));
	
	while (x_inicial <= x){
		
		/* ANTES *************************** 
		imagen = 
			exp ((-0.5) * pow (((x_inicial-esperanza) / desviacion), 2)) / 
			(desviacion * sqrt (2 * PI));
		cfd = cfd + imagen * SALTO;
		
		*********************************** */
		
		//Correcci�n
		imagen = 
			exp ((-0.5) * pow (((x_inicial-esperanza) / desviacion), 2));
		
		cfd += imagen;
		
		x_inicial += SALTO;
	}
	//CORRECI�N
	cfd /= parte1;
	cfd *= SALTO;
	
	//Salida de datos
	cout << "La distribuci�n acumulada o CFD en el punto x = " << x << " es: "
		 << cfd << endl;

	return 0;
}
