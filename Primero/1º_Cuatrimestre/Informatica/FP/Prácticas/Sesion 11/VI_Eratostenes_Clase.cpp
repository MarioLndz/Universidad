/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 22 - VI: La criba de Erat�stenes permite hallar todos los n�meros
	primos menores que un n�mero natural dado n. Hemos trabajado sobre este 
	problema en el ejercicio 14 de la Relaci�n de Ejercicios V. En esta ocasi�n 
	se trata de definir una clase llamada Eratostenes. Un objeto de la clase 
	podr� almacenar los n�meros primos calculados en un vector de enteros
	
	la criba consistira en escribir todos los naturales 
	comprendidos entre 2 y n y eliminar aquellos que no son	primos de la 
	siguiente manera:

	    El primero (el 2) se declara primo y se tachan todos sus m�ltiplos;
		se busca el siguiente n�mero entero que no ha sido tachado, 
		se declara primo y se procede a tachar todos sus m�ltiplos, y as� 
		sucesivamente. El proceso termina cuando el cuadrado del n�mero entero 
		es mayor o igual que el valor de n.

******************************************************************************/

#include <iostream> // Inclusi�n de los recursos de E/S
#include <iomanip>
#include <cmath> // Inclusi�n de los recursos matem�ticos

using namespace std;

/******************************************************************************/
//-------------------------------------------
class Eratostenes 
{
	private:
		static const int TAMANIO = 10;
		int vector_privado[TAMANIO] = {0};
		//PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados; // N�mero de casillas ocupadas
		
		int referencia = 0;
		
	public:
		//-------------------------------------------
		// Constructor
		Eratostenes (void): total_utilizados (0)
		{}
		
		//-------------------------------------------
		// M�todo que calcula los primos menores que n para almacenarlos en el
		// vector dato miembro de la clase
		//PRE: 1 <= n <= TAMANIO
		
		void CalculaHasta (int n) {
			bool es_primo[TAMANIO*2];
			
			//Inicializamos todos los numeros a true
			for (int i=0; i < n && i < (TAMANIO*2); i++){
				es_primo[i] = true;
			} 

			// Criba
			for (int num = 2; num*num <= n && num < (TAMANIO*2); num++){ 					        			
				if (es_primo[num]) {
					for (int k=2; k*num <= n && (k*num) < (TAMANIO*2); k++) {    
						es_primo[k*num] = false;
					}
				} // Fin if(es_primo)
			} // Fin criba
		
			// Ya est�n "tachados" los n�meros no-primos en "es_primo".  
			// Ahora recorremos "es_primo" completamente y copiamos a 
			// "primos" �nicamente los que permacenen a "true". 
			for (int i = 2; i <= n && i < TAMANIO; i++) { 
				if (es_primo[i]) {			 
					vector_privado[total_utilizados] = i;
					total_utilizados++;  		   		  
				}
			}
			referencia = n;
			
		}
		
		//-------------------------------------------
		// Devuelve cu�ntos primos hay almacenados actualmente
		
		int TotalCalculados (void) {
			return (total_utilizados);
		}
		
		//-------------------------------------------
		// Devuelve el k-�simo primo
		
		int Elemento (int k) {
			return (vector_privado[k]);
		}
		
		//-------------------------------------------
		// Devuelve el el valor que se suministr� para calcular los primos (el 
		// valor del campo n).
		
		int GetReferencia (){
			return referencia;
		}
		
		//-------------------------------------------
		// Devuelve el menor valor entero mayor o igual a todos los primos del 
		// vector. Si se pudieron guardar todos los primos solicitados, n y 
		// n_real coincidir�n.
		
		int GetReferenciaReal(){
			int n_real;
			if (total_utilizados + 1 > TAMANIO){
				n_real = vector_privado[total_utilizados-1];
			} else {
				n_real = referencia;
			}
			
			return n_real;
		}
};

/****************************************************************************/
/****************************************************************************/
int main() { 
	Eratostenes primos;
	
	cout << "Calculando primos" << endl;
	primos.CalculaHasta(100000);
	
	cout << "Primos <= " << primos.GetReferencia() << endl;

	cout << "Obtenidos <= " << primos.GetReferenciaReal() << endl;
	
	cout << "El mayor es: "
		 << primos.Elemento(primos.TotalCalculados()-1) << endl;
	
	cout << "Primos: " << endl;
	

	for (int i = 0; i < primos.TotalCalculados(); i++){
		cout << setw(5) << primos.Elemento(i);
		
		if ((i+1) % 8 == 0){
			cout << endl;
			
		}
	}
	
	return 0;
}
