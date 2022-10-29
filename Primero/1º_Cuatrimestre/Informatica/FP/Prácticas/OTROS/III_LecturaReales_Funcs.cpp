/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
//
/*
	1) Leer un real 
	2) Leer un real en un rango dado
	3) Leer un real mayor o igual que otro
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std; 


/***************************************************************************/
// Devuelve una NUEVA cadena, resultante de eliminar los últimos caracteres 
// separadores de "cadena". Los caracteres separadores son el espacio en 
// blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: el resultado de eliminar los últimos separadores de "cadena".
/***************************************************************************/

string EliminaUltimosSeparadores (string cadena)
{
   	while (cadena.length()>0 && isspace(cadena.back()))
		cadena.pop_back();
        
	return (cadena);
}

/***************************************************************************/
// Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
// separadores de "cadena". Los caracteres separadores son el espacio en 
// blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: el resultado de eliminar los primeros separadores de "cadena".
/***************************************************************************/

string EliminaPrimerosSeparadores (string cadena)
{	
	// Buscar el primer car�cter no espacio
	int pos = 0;
	while (pos < (int)cadena.length() && isspace(cadena.at(pos))) pos++;

	string local; 
	
	// Copiar todos los que quedan
	while (pos < (int)cadena.length()) {
		local.push_back(cadena.at(pos));
		pos++;
	}
		
	return (local);
}

/***************************************************************************/
// Devuelve "true" si "cadena" es la representación textual de un entero 

bool EsReal (string cadena) 
{
	bool es_real = true;

	cadena = EliminaPrimerosSeparadores (cadena);
	cadena = EliminaUltimosSeparadores  (cadena);

	int long_cadena = (int)cadena.length();
			
	if (long_cadena == 0) es_real = false; // No hay nada
	else {	// long_cadena > 0 
			
		// Si el primer carácter es '+' ó '-', perfecto. En ese caso 
		// se pasa al siguiente carácter (posición 1).
		 		
		int pos;
		if (cadena.at(0)=='-'|| cadena.at(0) == '+') pos=1;
		else pos=0;

		// Bandera que se activa al encontrar un punto
		bool encontrado_un_punto = false;

		while ((pos < long_cadena) && es_real) {
				
			char c = cadena.at(pos);

			if (!isdigit(c)) {
		
				// Solo puede haber un punto. 
				// Si se ha encontrado un punto y ya se había 
				// encontrado otro, error. Si no, activar la bandera 
				// "encontrado_un_punto" (ya no puede haber más).
				
				if (c=='.') {
					if (encontrado_un_punto) es_real= false; 
					else encontrado_un_punto = true; 
				}
				// Si no es un punto ni un dígito --> error
				else es_real= false; 
			}
						
			pos++; 		
				
		}	// while ((pos < long_cadena) && es_real)
						
	} // else de if (long_cadena == 0)
	
	return (es_real);
}

/***************************************************************************/
// Lee un dato double.
// La lectura está etiquetada con "titulo"
// La lectura se efectúa repetidamente hasta que se introduce un valor 
// double correcto. 
// 
// Devuelve: el double válido leído. 

double LeeReal (string titulo)
{
	string cadena;

	do {
		cout << titulo;
		getline (cin, cadena);
						
	} while (!EsReal(cadena));
		 	
	return (stod(cadena));
}

/************************************************************************/
// Lee un dato double que debe estar entre "menor" y "mayor" y lo devuelve.
// La lectura está etiquetada con "titulo"
// PRE: menor <= mayor 
// POST: menor <= valor devuelto <= mayor 

double LeeRealEnRango (string titulo, double menor, double mayor)
{
	double numero;

	do {
				
		numero = LeeReal (titulo);
				
	} while ((numero<menor) || (numero>mayor));
	
	return (numero);
}

/************************************************************************/
// Lee un dato double que debe ser mayor o igual que "menor" y lo devuelve.
// La lectura está etiquetada con "titulo"
// POST: menor <= valor devuelto 

double LeeRealMayorOIgual (string titulo, double menor)
{
	double numero;

	do {
		
		numero = LeeReal (titulo);
		
	} while (numero < menor);
	
	return (numero);
}

/***************************************************************************/
/***************************************************************************/

int main()
{	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);	

	// Lectura de un valor real arbitrario 
	
	double temperatura = LeeReal ("Temperatura (con decimales): "); 
	
	cout << endl;
	cout << "Valor de la temperatura = " 
	     << setw(8) << setprecision(4) << temperatura << endl;
	cout << endl << endl;
	
	
	// Lectura de un real acotado superior e inferiormente 
		 
	double iva = LeeRealEnRango ("IVA -entre 4.0 y 21.0-: ", 4.0, 21.0);
	
	cout << endl;
	cout << "Valor del IVA = " << setw(8) << setprecision(4) << iva << endl;
	cout << endl << endl;
	
	
	// Lectura de un real acotado superior e inferiormente 

	iva = LeeRealMayorOIgual ("Introduzca IVA (>=4.0): ", 4.0);
	
	cout << endl;
	cout << "Valor del IVA = " << setw(8) << setprecision(4) << iva << endl;
	cout << endl << endl;
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
