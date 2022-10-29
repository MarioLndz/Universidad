/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
/*	
	Una recta r viene determinada por tres coeficientes A, B, C, de forma 
	que todos los puntos (x, y) del plano que pertenecen a la recta verifican:
		r : Ax + By + C = 0 (ecuación general)
	
	Es más frecuente utilizar la ecuación explícita de la recta, en la que 
	se expresa la abscisa en función de la pendiente de la recta (m) y de 
	la ordenada en origen (n):
		r : y = mx + n  (ecuación explícita)
	de manera que m = -A/B y n = -C/B
	
	Este programa: 
	
		a) 	Pide los coeficientes de dos rectas,
		b) 	Muestra los puntos (x, y) por los que pasan las rectas para 
			valores de x = -10, -9, ..., 10 con Incr_x = +1 y para 
			y = -5,- 4, .... 5 con Incr_y = 0.5
			
			Usa las funciones:
				double Ordenada (double A, double B, double C, double x);
				double Abscisa  (double A, double B, double C, double y);
			
			para calcular la ordenada "y" dada la abscisa "x" (y viceversa)  
			para la recta Ax+By+C=0
			
		c) Escribe la ecuación explícita de las dos rectas
		
			i) con una función que escribe directamente la ecuación:
				void PintaEcuacionExplicita (double A, double B, double C);
		
			ii) con una función que devuelve un string con la expresión de 
				la ecuación:
				string ObtenEcuacionExplicita (double A, double B, double C);
				
			En ambos casos se calcula la pendiente y la ordenada en el origen 
			con sendas funciones:
				double Pendiente (double A, double B, double C);
				double OrdenadaEnOrigen (double A, double B, double C);				
					
		d) 	Indica si las rectas son paralelas, secantes o coincidentes 
			usando las funciones:
				bool SonCoincidentes (double A1, double B1, double C1, 
									  double A2, double B2, double C2); 			
				bool SonParalelas    (double A1, double B1, double C1, 
									  double A2, double B2, double C2); 			
				bool SonSecantes     (double A1, double B1, double C1, 
									  double A2, double B2, double C2); 			
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/***************************************************************************/
// Calcula la ordenada "y" dada la abscisa "x" para la recta Ax+By+C=0
// Recibe: A, B, y C: parámetros de la recta.
//         x, valor de la abscisa.
// PRE: B != 0
/***************************************************************************/

double Ordenada (double A, double B, double C, double x)
{
	return ((-A*x -C) / B);
}

/***************************************************************************/
// Calcula la abscisa "x" dada la ordenada "y" para la recta Ax+By+C=0
// Recibe: A, B, y C: parámetros de la recta.
//         y, valor de la ordenada.
// PRE: A != 0
/***************************************************************************/

double Abscisa  (double A, double B, double C, double y)
{
	return ((-B*y -C) / A);	
}
	
/***************************************************************************/
// Devuelve la pendiente de la recta (m = -A/B)
// Recibe: A, B, y C: parámetros de la recta.
// PRE: B != 0
/***************************************************************************/

double Pendiente (double A, double B, double C)
{
	return (-A/B);
}
		
/***************************************************************************/
// Devuelve la ordenada en origen de la recta (n = -C/B)
// Recibe: A, B, y C: parámetros de la recta.
// PRE: B != 0
/***************************************************************************/

double OrdenadaEnOrigen (double A, double B, double C)
{
	return (-C/B);	
}
			
/***************************************************************************/
// Escribe directamente la ecuación explícita de una recta
// Recibe: A, B, y C: parámetros de la recta.
// PRE: B != 0
/***************************************************************************/

void PintaEcuacionExplicita (double A, double B, double C)
{
	double m = Pendiente (A, B, C);
	double n = OrdenadaEnOrigen (A, B, C);	
	
	cout << " y = ";
	
	if (m!=0) 
		cout << setw(5) << setprecision(2) << m <<  " x ";	

	if (n != 0) {
		
		if (n>0) cout << " +";
		else     cout << " -";
		
		// cout << ((n > 0) ? " +" : " -");
	}
	
	cout << setw(5) << setprecision(2) << fabs(n);	
}
		
/***************************************************************************/
// Devuelve un string con la expresión de la ecuación explicita
// Recibe: A, B, y C: parámetros de la recta.
// Devuelve: un string con la ecuación explícita de la recta.
// PRE: B != 0
/***************************************************************************/

string ObtenEcuacionExplicita (double A, double B, double C)
{
	double m = Pendiente (A, B, C);
	double n = OrdenadaEnOrigen (A, B, C);	
	
	string explicita;
	
	explicita = "y = ";
	
	if (m!=0) explicita = explicita +to_string (m) + " x ";	
	
	if (n != 0) {
		
		if (n>0) explicita = explicita + " +";
		else     explicita = explicita + " -";
		
		// explicita = explicita + ((n > 0) ? " +" : " -");
	}
	
	explicita = explicita + to_string (fabs(n));	
	
	return (explicita);
}
			
/***************************************************************************/
// Calcula si dos rectas son coincidentes.
// Recibe: A1, B1, y C1: parámetros de la recta 1.
//         A2, B2, y C2: parámetros de la recta 2.
// Devuelve: "true" si las rectas son coincidentes.
/***************************************************************************/

bool SonCoincidentes (double A1, double B1, double C1, 
					  double A2, double B2, double C2)
{
	double razon = A1/A2;
	return ((razon == B1/B2) && (razon==C1/C2));
}
					 			
/***************************************************************************/
// Calcula si dos rectas son paralelas.
// Recibe: A1, B1, y C1: parámetros de la recta 1.
//         A2, B2, y C2: parámetros de la recta 2.
// Devuelve: "true" si las rectas son paralelas.
/***************************************************************************/

bool SonParalelas    (double A1, double B1, double C1, 
					  double A2, double B2, double C2)		
{
	double razon = A1/A2;
	return ((razon == B1/B2) && (razon!=C1/C2));
}

/***************************************************************************/
// Calcula si dos rectas son secantes.
// Recibe: A1, B1, y C1: parámetros de la recta 1.
//         A2, B2, y C2: parámetros de la recta 2.
// Devuelve: "true" si las rectas son secantes.
/***************************************************************************/

bool SonSecantes     (double A1, double B1, double C1, 
					  double A2, double B2, double C2)
{
	double razon = A1/A2;	
	return (razon != B1/B2);
}
									  
									  				
/***************************************************************************/
/***************************************************************************/

int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	double A1, B1, C1;  // PRE: A1 y B1 no pueden ser ambos 0 
	double A2, B2, C2;  // PRE: A2 y B2 no pueden ser ambos 0 
	
	// a) Lectura de los coeficientes de las dos rectas

	cout << endl;	
	cout << "Recta 1: ";

	do 	{
		cout << endl; 
		cout << "\tA: ";
		cin >> A1;
		cout << "\tB: ";
		cin >> B1;
	} while (A1==0 && B1==0);

	cout << "\tC: ";
	cin >> C1;
	
	cout << endl;	
	cout << "Recta 2: ";
	
	do 	{
		cout << endl; 
		cout << "\tA: ";
		cin >> A2;
		cout << "\tB: ";
		cin >> B2;
	} while (A2==0 && B2==0);

	cout << "\tC: ";
	cin >> C2;
	
	cout << endl;	


	// b) Mostrar puntos (x,y) por los que pasan las rectas
	
	if (B1!=0) {
		cout << endl;	
		cout << "Recta 1. x=-10.0, -9.0, ..., 10.0" << endl;
		cout << endl;	
		
		for (double x=-10.0; x<=10.0; x++) {
			
			cout << "\t(" << setw(6) << setprecision(2) << x << ", " 
			     << setw(6) << setprecision(2) 
				 << Ordenada (A1,B1,C1,x) << ")" << endl;
		}
	}
	else // B1==0
		cout << "Recta 1 paralela al eje Y--> x = " 
		     << setw(6) << setprecision(2) << (-C1/A1) << endl;
	cout << endl;	
	
	if (A1!=0) {
		cout << endl;
		cout << "Recta 1. y=-5.0, -4.5, -4.0, ..., 5.0" << endl; 
		cout << endl;	
		
		for (double y=-5.0; y<=5.0; y+=0.5) {
			
			cout << "\t(" << setw(6) << setprecision(2) 
			     << Abscisa (A1,B1,C1,y)  << ", " 
			     << setw(6) << setprecision(2) << y << ")" << endl;
		}
	}
	else // A1==0
		cout << "Recta 1 paralela al eje X--> y = " 
		     << setw(6) << setprecision(2) << (-C1/B1) << endl;
	cout << endl;
		
	if (B2!=0) {
		cout << endl;		
		cout << "Recta 2. x=-10.0, -9.0, ..., 10.0" << endl;
		cout << endl;	
		
		for (double x=-10.0; x<=10.0; x++) {
			
			cout << "\t(" << setw(6) << setprecision(2) << x << ", " 
			     << setw(6) << setprecision(2) 
				 << Ordenada (A2,B2,C2,x) << ")" << endl;
		}
	}
	else // B2==0
		cout << "Recta 2 paralela al eje Y--> x = " 
		     << setw(6) << setprecision(2) << (-C2/A2) << endl;
	cout << endl;

	if (A2!=0) {			 	
		cout << endl;
		cout << "Recta 2. y=-5.0, -4.5, -4.0, ..., 5.0" << endl; 
		cout << endl;	
	
		for (double y=-5.0; y<=5.0; y+=0.5) {
			
			cout << "\t(" << setw(6) << setprecision(2) 
			     << Abscisa (A2,B2,C2,y)  << ", " 
			     << setw(6) << setprecision(2) << y << ")" << endl;
		}
	}
	else
		cout << "Recta 2 paralela al eje X--> y = " 
		     << setw(6) << setprecision(2) << (-C2/B2) << endl;
	cout << endl;	
				
					 		
	// c) Escribir la ecuación explícita de las dos rectas
	
	if (B1 != 0) {
		cout << "Recta 1: " << endl;
		PintaEcuacionExplicita (A1, B1, C1);
		cout << endl;
		
		cout << endl;
		cout << "Recta 1: " << ObtenEcuacionExplicita (A1, B1, C1) << endl;
		cout << endl;
	}
	
	if (B2 != 0) {		
		cout << endl;
		cout << "Recta 2: " << endl;
		PintaEcuacionExplicita (A2, B2, C2);
		cout << endl;
	
		cout << endl;
		cout << "Recta 2: " << ObtenEcuacionExplicita (A2, B2, C2) << endl;
		cout << endl;
	}

	// d) Posición relativa de las dos rectas
	
	cout << endl;
	cout << "Las rectas son ";	
	
	if (SonCoincidentes(A1,B1,C1,A2,B2,C2))
		cout << " COINCIDENTES" << endl; 
	else if (SonParalelas(A1,B1,C1,A2,B2,C2))
		cout << " PARALELAS" << endl; 
	else if (SonSecantes(A1,B1,C1,A2,B2,C2))
		cout << " SECANTES" << endl;	
	cout << endl << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/

