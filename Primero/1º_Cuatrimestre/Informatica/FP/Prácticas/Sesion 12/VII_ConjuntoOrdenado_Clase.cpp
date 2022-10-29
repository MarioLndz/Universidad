/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 11 - VII: Se definira la clase ConjuntoOrdenado para almacenar
	una secuencia ordenada de números enteros sin repetidos

******************************************************************************/

#include <iostream>	// Inclusión de los recursos de E/S
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class ConjuntoOrdenado {
private:
	static const int TAMANIO = 500;
	int vector_privado[TAMANIO];
	
	// PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados; // Núm.casillas ocupadas
	
public:
	/***********************************************************************/
	//	Constructores
	
	//------------------------------------------------
	// Constructor sin argumentos
	ConjuntoOrdenado (void) : total_utilizados (0)
	{}
	
	/***********************************************************************/
	//	Consultas
	
	//------------------------------------------------
	// Devuelve el número de casillas ocupadas
	int TotalUtilizados (void) {
    	return (total_utilizados);
	}
	
	//------------------------------------------------
	// Devuelve el número de casillas disponibles
	int Capacidad (void) {
    	return (TAMANIO);
	}
	
	//------------------------------------------------
	// Devuelve el elemento de la casilla "indice"
	// PRE: 0 <= indice < total_utilizados
	int Elemento (int indice) {
    	return (vector_privado[indice]);
	}
	
	//------------------------------------------------
	// Compone un string con todos los caracteres que están
	// almacenados en la secuencia y lo devuelve.

	string ToString() {
    	string cadena = "{";
    	const string SEPARADOR = ", ";

    	for (int i=0; i<total_utilizados; i++){
        	if (i != 0){
        		cadena += SEPARADOR;
			}
        	cadena += to_string(vector_privado[i]);
		}
		
		cadena += "}";
    	return (cadena);
	}
	
	/***********************************************************************/
	//	Calculos
	
	//------------------------------------------------
	// Eliminar el carácter de la posición dada por "indice".
	// Realiza un borrado físico (desplazamiento y sustitución).
	// PRE: 0 <= indice < total_utilizados
	void Elimina (int indice) {
    	if ((indice >= 0) && (indice < total_utilizados)) {

        	int tope = total_utilizados-1; // posic. del último

        	for (int i = indice ; i < tope ; i++)
            	vector_privado[i] = vector_privado[i+1];

        	total_utilizados--;
    	}
	}
	
	//------------------------------------------------
	// Añade un elemento ("nuevo") al vector.
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay alguna casilla disponible.
	// 		El nuevo elemento se coloca al final del vector siempre que no
	//		se encuentre ya, y luego se ordenara de forma creciente
	// 		Si no hay espacio, no se hace nada.
	void Aniade (int nuevo) {
    	bool num_ya_existente = false;
		
		if (total_utilizados < TAMANIO){
        	for (int i = 0; i < total_utilizados; i++){
        		if (vector_privado[i] == nuevo){
					num_ya_existente = true;
				}
				
			}
			
			if (!num_ya_existente){
				vector_privado[total_utilizados] = nuevo;
	        	total_utilizados++;
	        	
	        	OrdenaVector();
			}
    	}
	}
	
	//------------------------------------------------
	// Ordena el vector de forma creciente utilizando el algoritmo de
	// ordenacion por insercion
	void OrdenaVector(){
		int a_insertar;
		
		for (int izda = 1; izda < total_utilizados; izda++){
			a_insertar = vector_privado[izda];
			
			// Se busca la posición en la zona ordenada
			int i=izda;
			while(i > 0 && (a_insertar < vector_privado[i-1])){
				vector_privado[i] = vector_privado[i-1];
				i--;
			}
				
			vector_privado[i] = a_insertar;
		}
	}
	
	//------------------------------------------------
    //	Calcula la union con otro conjunto ordenado
    // 	Devuelve un objeto de clase ConjuntoOrdenado
    //	PRE: La suma del número de enteros de ambos conjuntos no puede 
	//	ser mayor que TAMANIO
    ConjuntoOrdenado Union (ConjuntoOrdenado otro_conjunto){
    	ConjuntoOrdenado conjunto_union(otro_conjunto);
    	
    	for (int i = 0; i < total_utilizados; i++){
    		conjunto_union.Aniade(vector_privado[i]);
    	}
    	
    	return conjunto_union;
    }
    
    //------------------------------------------------
    // 	Calcula la intersección de dos conjuntos ordenados.
    // 	Devuelve un objeto de la clase ConjuntoOrdenado
    //	PRE: La suma del número de enteros de ambos conjuntos no puede 
	//	ser mayor que TAMANIO
    ConjuntoOrdenado Interseccion(ConjuntoOrdenado otro_conjunto){
    	ConjuntoOrdenado interseccion;
    	
    	for (int i = 0; i < total_utilizados; i++){
			bool seguir=true;
    		
			int j = 0;
    		while(j < otro_conjunto.total_utilizados && seguir){
				//Si encuentra un caracter igual en ambos Conjuntos, lo aniade,
				//como estan ordenados solo habra que buscar hasta encontrar 
				//en el otro conjunto numeros menores que el.
				if (vector_privado[i] == otro_conjunto.vector_privado[j]){
					interseccion.Aniade(vector_privado[i]);
					seguir = false;
					
				} else if (otro_conjunto.vector_privado[j] > vector_privado[i]){
					seguir = false;
				}
    				
    			j++;
			}
    	}
    	
    	return interseccion;
    }
};

/****************************************************************************/
/****************************************************************************/
int main () {
	const int TERMINADOR = -100;
	
    //------------------------------------------------
    //	ENTRADA
    
	int numero;
	
	cout << "Inserte dos secuencias de enteros (para acabar, introduzca " 
		 << TERMINADOR << " )" << endl;
	
	//Secuencia 1
	ConjuntoOrdenado conjunto1;
	
	cout << "\t" << "Secuencia 1:" << endl;
	cout << "\t" << "> ";
	cin >> numero;
	
	while (numero != TERMINADOR){
		conjunto1.Aniade(numero);
		cout << "\t" << "> ";
		cin >> numero;
		
	}
	
	//Secuencia 2
	ConjuntoOrdenado conjunto2;
	
	cout << endl;
	cout << "\t" << "Secuencia 2:" << endl;
	cout << "\t" << "> ";
	cin >> numero;
	
	while(numero != TERMINADOR){
		conjunto2.Aniade(numero);
		cout << "\t" << "> ";
		cin >> numero;
	}
	
	//------------------------------------------------
    //	CALCULOS
    
	ConjuntoOrdenado conjunto_union (conjunto1.Union(conjunto2));
	ConjuntoOrdenado interseccion (conjunto1.Interseccion(conjunto2));
	
	//------------------------------------------------
    //	SALIDA
    
	cout << endl;
	cout << "**************************************************" << endl;
	cout << "Conjunto 1 = " << conjunto1.ToString() << endl;
	cout << "Conjunto 2 = " << conjunto2.ToString() << endl;
	cout << endl;
	
	cout << "**************************************************" << endl;
	cout << "OPERACIONES" << endl << endl;
	cout << "\t" << "- Union = " << conjunto_union.ToString() << endl;
	cout << "\t" << "- Interseccion = " << interseccion.ToString() << endl;
	
	return 0;
}
