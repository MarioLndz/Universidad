/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 41: En este ejercicio se va a procesar el contenido de una cadena 
	de caracteres extrayendo sus componentes.

*****************************************************************************/

#include <iostream>	// Inclusi�n de los recursos de E/S
#include <string>
#include <fstream>	//Para poder leer archivos externos
#include <iomanip>	//Para dar formato

using namespace std;

int main () {
	//Lectura de la cadena a partir de un archivo (redirecci�n de entrada)
		string cadena;
		ifstream indice ("indice.txt");
		
		getline (indice, cadena);
		
	//Separaci�n de la cadena
		string seccion = cadena.substr(0, 3);
		string subseccion = cadena.substr(3, 3);
		string subsubseccion = cadena.substr(6, 3);
		string titulo = cadena.substr(9, 40);
		string pagina = cadena.substr(49, 3);
		
	//Salida por pantalla de los componentes
		cout << "Componentes:" << endl;
			cout << "\t- Secci�n: " << setw(10) << seccion << endl;
			cout << "\t- Subsecci�n: " << setw(7) << subseccion << endl;
			cout << "\t- Subsubsecci�n: " << setw(4) << subsubseccion << endl;
			cout << "\t- P�gina: " << setw(11) << pagina << endl;
			cout << "\t- T�tulo: " << titulo << endl;
			
	//L�nea procesada
		string linea_procesada = seccion + "." + subseccion + "." 
		+ subsubseccion + ". " + titulo + " " + pagina;

		cout << endl << "L�nea procesada: " << linea_procesada;
	 	
	return 0;
}
