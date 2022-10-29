/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 22 - VI: La criba de Eratóstenes permite hallar todos los números
	primos menores que un número natural dado n. Hemos trabajado sobre este 
	problema en el ejercicio 14 de la Relación de Ejercicios V. En esta ocasión 
	se trata de definir una clase llamada Eratostenes. Un objeto de la clase 
	podrá almacenar los números primos calculados en un vector de enteros
	
	la criba consistira en escribir todos los naturales 
	comprendidos entre 2 y n y eliminar aquellos que no son	primos de la 
	siguiente manera:

	    El primero (el 2) se declara primo y se tachan todos sus múltiplos;
		se busca el siguiente número entero que no ha sido tachado, 
		se declara primo y se procede a tachar todos sus múltiplos, y así 
		sucesivamente. El proceso termina cuando el cuadrado del número entero 
		es mayor o igual que el valor de n.

******************************************************************************/

#include <iostream> // Inclusión de los recursos de E/S
#include <iomanip>
#include <cmath> // Inclusión de los recursos matemáticos

using namespace std;

/******************************************************************************/
//-------------------------------------------
class Eratostenes 
{
	private:
		static const int TAMANIO = 10;
		int vector_privado[TAMANIO] = {0};
		//PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados; // Número de casillas ocupadas
		
		int referencia = 0;
		
	public:
		//-------------------------------------------
		// Constructor
		Eratostenes (void): total_utilizados (0)
		{}
		
		//-------------------------------------------
		// Método que calcula los primos menores que n para almacenarlos en el
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
		
			// Ya están "tachados" los números no-primos en "es_primo".  
			// Ahora recorremos "es_primo" completamente y copiamos a 
			// "primos" únicamente los que permacenen a "true". 
			for (int i = 2; i <= n && i < TAMANIO; i++) { 
				if (es_primo[i]) {			 
					vector_privado[total_utilizados] = i;
					total_utilizados++;  		   		  
				}
			}
			referencia = n;
			
		}
		
		//-------------------------------------------
		// Devuelve cuántos primos hay almacenados actualmente
		
		int TotalCalculados (void) {
			return (total_utilizados);
		}
		
		//-------------------------------------------
		// Devuelve el k-ésimo primo
		
		int Elemento (int k) {
			return (vector_privado[k]);
		}
		
		//-------------------------------------------
		// Devuelve el el valor que se suministró para calcular los primos (el 
		// valor del campo n).
		
		int GetReferencia (){
			return referencia;
		}
		
		//-------------------------------------------
		// Devuelve el menor valor entero mayor o igual a todos los primos del 
		// vector. Si se pudieron guardar todos los primos solicitados, n y 
		// n_real coincidirán.
		
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
