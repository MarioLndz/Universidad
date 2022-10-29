/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 14 - VI: Comprobaremos el uso de la clase ManipuladorString. 
	Esta clase se encargar� de modificar un dato string y realizar c�lculos 
	complejos sobre �l con funciones no ofertadas por la clase string.

*****************************************************************************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std; 

class ManipuladorString{
	private:
		string cadena;
	
	public:
		/***********************************************************/
		//	CONSTRUCTORES
		
		ManipuladorString()
			: cadena("")
		{}
		
		ManipuladorString(string la_cadena)
			: cadena(la_cadena)
		{}
		
		/***********************************************************/
		//	METODOS SET Y GET
		
		void SetCadena (string la_cadena){
			cadena = la_cadena;
		}
		
		string GetCadena (){
			return cadena;
		}
		
		/***********************************************************/
		//	METODOS
		
		//------------------------------------------------------------------
		// 	Eliminaa los ultimos caracteres separadores de "cadena". Los 
		//	caracteres separadores son el espacio en blanco, el tabulador y el 
		//	salto de linea. 
		
		void EliminaUltimosSeparadores () {
		   	while (cadena.length()>0 && isspace(cadena.back()))
				cadena.pop_back();
				
		}
		
		//------------------------------------------------------------------
		// 	Elimina los primeros caracteres separadores de "cadena". Los 
		//	caracteres separadores son el espacio en blanco, el tabulador y el 
		//	salto de l�nea. 
		
		void EliminaPrimerosSeparadores () {	
			// Buscar el primer caracter no espacio
			int pos = 0;
			while (pos < (int)cadena.length() && isspace(cadena.at(pos))) pos++;
		
			string local; 
			
			// Copiar todos los que quedan
			while (pos < (int)cadena.length()) {
				local.push_back(cadena.at(pos));
				pos++;
			}
				
			cadena = local;
		}
		
		//------------------------------------------------------------------
		// 	Eliminara los primeros y los ultimos caracteres separadores de 
		//	"cadena". Los caracteres separadores son 
		//	el espacio en blanco, el tabulador y el salto de l�nea. 
		
		void EliminaPrimerosYUltimosSeparadores (){
			EliminaPrimerosSeparadores();
			EliminaUltimosSeparadores();
		}
		
		//------------------------------------------------------------------
		// Convierte toda la cadena a may�sculas

		void ConvierteAMayusculas () {
			int longitud = cadena.length();
			for (int i = 0; i < longitud; i++){
				cadena.at(i)=toupper(cadena.at(i));
			}
		}
		
		//------------------------------------------------------------------
		// Convierte toda la cadena a min�sculas

		void ConvierteAMinusculas () {
			int longitud = cadena.length();
			for (int i = 0; i < longitud; i++){
				cadena.at(i)=tolower(cadena.at(i));
			}
		}
	
};

/***************************************************************************/
/***************************************************************************/
int main () {
	string cadena_leida;
	
	cout << "> ";
	getline(cin, cadena_leida);
	
	ManipuladorString cadena (cadena_leida);
	
	//Cadena sin espacios iniciales
	cadena.EliminaPrimerosSeparadores();

	cout << "Cadena sin espacios iniciales: #" << cadena.GetCadena() << "#"
		 << endl;

	//Cadena sin espacios finales
	cadena.SetCadena(cadena_leida);
	cadena.EliminaUltimosSeparadores();

	cout << "Cadena sin espacios finales: #" << cadena.GetCadena() << "#" 
		 << endl;

	//Cadena sin espacios iniciales ni finales
	cadena.SetCadena(cadena_leida);
	cadena.EliminaPrimerosYUltimosSeparadores();

	cout << "Cadena sin espacios iniciales ni finales: #" << cadena.GetCadena() 
		 << "#" << endl;

	//Cadena en min�scula
	cadena.SetCadena(cadena_leida);
	cadena.ConvierteAMinusculas();

	string cadena_minuscula = cadena.GetCadena();
	cout << "Cadena en minuscula: " << cadena.GetCadena() << endl;
	
	//Cadena en may�scula
	cadena.SetCadena(cadena_leida);
	cadena.ConvierteAMayusculas();

	cout << "Cadena en mayuscula: " << cadena.GetCadena() << endl;
	
	return 0;
}
