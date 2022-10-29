/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 13 - VI: Comprobaremos el uso de una clase (Lector) que 
	ofrezca un conjunto de métodos seguros de lectura etiquetada de datos int y 
	double.

*****************************************************************************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std; 

class Lector {
	private:
		string titulo;
	
	public:
		Lector (string cadena)
			: titulo(cadena)
		{}
		
		Lector ()
			: titulo("")
		{}
		
		/*******************************************************************/
		//	ENTEROS
		/*******************************************************************/
		
		//------------------------------------------------------------------
		//	LeeEntero
		// 	Leera un dato hasta que se introduzca un entero
		// 
		//	DEVUELVE: Entero leido
		
		int LeeEntero() {
			string cadena;
		
			do {
				cout << titulo;
				getline (cin, cadena);
								
			} while (!EsEntero(cadena));
					
			int numero = stoi(cadena);
		 	
			return (numero);	
		}
		
		//------------------------------------------------------------------
		//	LeeEnteroEnRango
		// 	Lee un dato int que debe estar entre "menor" y "mayor" y lo 
		//	devuelve.
		// 	La lectura esta etiquetada con "titulo"
		// 	PRE: menor <= mayor 
		// 	POST: menor <= valor devuelto <= mayor 
		
		int LeeEnteroEnRango (double menor, double mayor) {
			double numero;
		
			do {
				numero = LeeEntero();
			} while ((numero<menor) || (numero>mayor));
			
			return (numero);
		}
		
		//------------------------------------------------------------------
		// Lee y devuelve un dato int. La lectura está etiquetada con "titulo". 
		// Para que se considere correcta la lectura el dato int debe estar 
		// comprendido entre "menor" y "mayor". 
		// 
		// Recibe:  titulo, la cadena usada para etiquetar la lectura .
		// Devuelve: el entero válido leído. 
		//
		// PRE: menor <= mayor 
		// POST: menor <= valor devuelto <= mayor 
		
		int LeeEnteroMayorOIgual(int referente)	{
			int numero;
		
			do {
				numero = LeeEntero ();	
			} while (numero < referente);
			
			return (numero);
		}
		
		/*******************************************************************/
		//	REALES
		/*******************************************************************/
		
		//------------------------------------------------------------------
		// Lee un dato double.
		// La lectura esta etiquetada con "titulo"
		// La lectura se efectua repetidamente hasta que se introduce un valor 
		// double correcto. 
		// 
		// Devuelve: el double valido leido. 
		
		double LeeReal() {
			string cadena;
		
			do {
				cout << titulo;
				getline (cin, cadena);
			} while (!EsReal(cadena));
				 	
			return (stod(cadena));
		}
		
		//------------------------------------------------------------------
		// 	Lee un dato double que debe estar entre "menor" y "mayor" y lo 
		//	devuelve.
		// 	La lectura esta etiquetada con "titulo"
		// 	PRE: menor <= mayor 
		// 	POST: menor <= valor devuelto <= mayor 
		
		double LeeRealEnRango(double menor, double mayor){
			double numero;
		
			do {
				numero = LeeReal();
			} while ((numero<menor) || (numero>mayor));
			
			return (numero);
		}
		
		//------------------------------------------------------------------
		// 	Lee un dato double que debe ser mayor o igual que "menor" y lo 
		//	devuelve.
		// 	La lectura esta etiquetada con "titulo"
		// 	POST: menor <= valor devuelto 
		
		double LeeRealMayorOIgual(double menor) {
			double numero;
		
			do {
				numero = LeeReal ();
			} while (numero < menor);
			
			return (numero);
		}
		
		/*******************************************************************/
		//	METODOS SET
		/*******************************************************************/
		void SetTitulo(string nuevo_titulo){
			titulo = nuevo_titulo;
		}
		
	private:
		//------------------------------------------------------------------
		// 	Devuelve una NUEVA cadena, resultante de eliminar los ultimos 
		//	caracteres separadores de "cadena". Los caracteres separadores son 
		//	el espacio en blanco, el tabulador y el salto de linea. 
		// 
		// 	RECIBE:  cadena, string sobre la que se va a trabajar.
		// 	DEVUELVE: el resultado de eliminar los Ãºltimos separadores de 
		//			 "cadena".
		
		string EliminaUltimosSeparadores(string cadena) {
		   	while (cadena.length()>0 && isspace(cadena.back()))
				cadena.pop_back();
		        
			return (cadena);
		}
		
		//------------------------------------------------------------------
		// 	Devuelve una NUEVA cadena, resultante de eliminar los primeros 
		//	caracteres separadores de "cadena". Los caracteres separadores son 
		//	el espacio en blanco, el tabulador y el salto de línea. 
		// 
		// 	RECIBE:  cadena, string sobre la que se va a trabajar.
		// 	DEVUELVE: el resultado de eliminar los primeros separadores de 
		//			  "cadena".
		
		string EliminaPrimerosSeparadores(string cadena) {	
			// Buscar el primer carÃ¡cter no espacio
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
		
		//------------------------------------------------------------------
		//	EsEntero
		// 	Comprueba si un string contiene exclusivamente a un dato entero
		// 
		// 	RECIBE: Cadena a comprobar
		// 	DEVUELVE: True o False
		
		bool EsEntero(string cadena) {
			bool es_entero = true;
		
			cadena = EliminaPrimerosSeparadores(cadena);
			cadena = EliminaUltimosSeparadores(cadena);
		
			int long_cadena = cadena.length();
					
			if (long_cadena == 0) es_entero = false;
			else {	
			
				// Si el primer carácter es '+' ó '-', perfecto. En ese caso 
				// se pasa al siguiente carácter (posición 1).
				 		
				int pos;
				if (cadena.at(0)=='-'|| cadena.at(0) == '+') {
					if (long_cadena>1) pos=1;	
					else es_entero = false; // Solo hay '-' ó '+'
				}
				else pos=0;
				
				//Todos los caracteres desde la posición "pos" deben ser dígitos
				
				while ((pos < long_cadena) && es_entero) {
					if (!isdigit(cadena.at(pos))) es_entero = false;
					else pos++;
				}	
			}
			
			return (es_entero);
		}
		
		//------------------------------------------------------------------
		// Devuelve "true" si "cadena" es la representacion textual de un real
		
		bool EsReal (string cadena) {
			bool es_real = true;
		
			cadena = EliminaPrimerosSeparadores(cadena);
			cadena = EliminaUltimosSeparadores(cadena);
		
			int long_cadena = (int)cadena.length();
					
			if (long_cadena == 0) es_real = false; // No hay nada
			else {	// long_cadena > 0 
					
				// Si el primer carÃ¡cter es '+' ó '-', perfecto. 
				// En ese caso (si hay algo más) en la cadena se pasa al 
				// siguiente carácter (posición 1).
				 		
				int pos;
				if (cadena.at(0)=='-'|| cadena.at(0) == '+') {
					if (long_cadena>1) pos=1;	
					else es_real = false; // Solo hay '-' ó '+'
				}
				else pos=0;
		
				// Bandera que se activa al encontrar un punto
				bool encontrado_un_punto = false;
		
				while ((pos < long_cadena) && es_real) {
						
					char c = cadena.at(pos);
		
					if (!isdigit(c)) {
				
						// Solo puede haber un punto. 
						// Si se ha encontrado un punto y ya se habÃ­a 
						// encontrado otro, error. Si no, activar la bandera 
						// "encontrado_un_punto" (ya no puede haber mÃ¡s).
						
						if (c=='.') {
							if (encontrado_un_punto) es_real= false; 
							else encontrado_un_punto = true; 
						}
						// Si no es un punto ni un dÃ­gito --> error
						else es_real= false; 
					}
								
					pos++; 		
						
				}	// while ((pos < long_cadena) && es_real)
								
			} // else de if (long_cadena == 0)
			
			return (es_real);
		}
};

/***************************************************************************/
/***************************************************************************/
int main () {
	// Lectura de un entero
	Lector lector_temp("Temperatura: ");
	int temp = lector_temp.LeeEntero();
	
	cout << "Temperatura leida = " << temp << endl << endl;
	
	// Lectura de enteros acotados superior e inferiormente
	Lector lector_hora;
	
	lector_hora.SetTitulo("Introduzca hora: ");
	int h = lector_hora.LeeEnteroEnRango (0, 23);
	
	lector_hora.SetTitulo("Introduzca minuto: ");
	int m = lector_hora.LeeEnteroEnRango (0, 59);
	
	lector_hora.SetTitulo("Introduzca segundo: ");
	int s = lector_hora.LeeEnteroEnRango (0, 59);
	
	cout << "Hora: " << h << ":" << m << ":" << s << endl << endl;
	
	// Lectura de un entero acotado inferiormente
	Lector lector_ingreso("Cantidad a ingresar: ");
	int ingreso = lector_ingreso.LeeEnteroMayorOIgual (0);
	
	cout << "Valor del ingreso = " << ingreso << endl << endl;
	
	//Lectura de un real
	Lector lector_altura("Altura (m):");
	double altura = lector_altura.LeeReal();
	
	cout << "Mide " << altura << " metros" << endl << endl;
	
	//Lectura de un real acotado superior e inferiormente
	Lector lector_nota("Nota del examen: ");
	double nota = lector_nota.LeeRealEnRango(0, 10);
	
	cout << "Ha sacado un " << nota << " en el examen" << endl << endl;
	
	// Lectura de un real acotado inferiormente
	Lector lector_radio("Radio de la circunferencia (m): ");
	double radio = lector_radio.LeeRealMayorOIgual (0);
	
	cout << "La circunferencia tiene un radio de " << radio << " m" << endl;
	return 0;
}
