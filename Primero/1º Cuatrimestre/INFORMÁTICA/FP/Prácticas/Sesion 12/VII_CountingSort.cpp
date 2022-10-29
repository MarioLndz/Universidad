/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 10 - VII: Sobre la clase SecuenciaCaracteres se implementara el
	algoritmo Counting Sort para ordenar sus valores.
		SecuenciaCaracteres CountingSort()
	El método no modificará las componentes del vector privado sino que debe 
	construir una secuencia nueva y devolverla.

******************************************************************************/

#include <iostream>	// Inclusión de los recursos de E/S
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;


class SecuenciaCaracteres {
private:

	static const int TAMANIO = 50; // Núm.casillas disponibles
	char vector_privado[TAMANIO];

	// PRE: 0<=total_utilizados<=TAMANIO

	int total_utilizados; // Núm.casillas ocupadas

public:
	//****************************************************/
	//	CONSTRUCTORES
	
	//------------------------------------------------
	// Constructor sin argumentos

	SecuenciaCaracteres (void) : total_utilizados (0)
	{}
	
	//------------------------------------------------
	// Constructor con argumentos
	
	SecuenciaCaracteres (string cadena) : total_utilizados (0)
	{
		int longitud = cadena.length();
		
		for (int i = 0; i < longitud; i++){
			vector_privado[i] = cadena.at(i);
		}
		total_utilizados = longitud;
	}
	
	/******************************************************/
	//	METODOS
	
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
	// "Vacía" completamente la secuencia

	void EliminaTodos() {
		total_utilizados = 0;
	}

	//------------------------------------------------
	// Añade un elemento ("nuevo") al vector.
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay alguna casilla disponible.
	// 		El nuevo elemento se coloca al final del vector.
	// 		Si no hay espacio, no se hace nada.

	void Aniade (char nuevo) {
    	if (total_utilizados < TAMANIO){
        	vector_privado[total_utilizados] = nuevo;
        	total_utilizados++;
    	}
	}

	//------------------------------------------------
	// Devuelve el elemento de la casilla "indice"
	// PRE: 0 <= indice < total_utilizados

	char Elemento (int indice) {
    	return (vector_privado[indice]);
	}

	//------------------------------------------------
	// Cambia el contenido de la casilla "indice" por el valor "nuevo"
	// PRE: 0 <= indice < total_utilizados

	void Modifica (int indice, char nuevo) {
		if ((indice >= 0) && (indice < total_utilizados))
			vector_privado[indice] = nuevo;
	}


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
	// Inserta el carácter "nuevo" en la posición dada por "indice".
	// Desplaza todos los caracteres una posición a la derecha antes de 
	// copiar en "indice" en valor "nuevo".
	// PRE: 0 <= indice < total_utilizados
	// PRE: total_utilizados < TAMANIO
	// 		La inserción se realiza si hay alguna casilla disponible.
	// 		Si no hay espacio, no se hace nada.

	void Inserta (int indice, char valor_nuevo) {
    	if ((indice >= 0) && (indice < total_utilizados)
	    	&& (total_utilizados < TAMANIO)) {
	
			for (int i = total_utilizados ; i > indice ; i--){
				vector_privado[i] = vector_privado[i-1];
			}
		
			vector_privado[indice] = valor_nuevo;
			total_utilizados++;		
		}
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
        	cadena += vector_privado[i];
		}
		
		cadena += "}";
    	return (cadena);
	}

	//-------------------------------------------------
	// Borra de la secuencia de caracteres un caracter dado por
	// el usuario.

	void EliminaOcurrencias (char a_borrar) {
		int pos_lectura = 0;	//Apuntador de lectura
		int pos_escritura = 0;	//Apuntador de escritura
		
		// Recorreremos el vector, si el caracter en la posicion de lectura
		// es distinto del caracter a borrar, lo escribe en la posicion
		// de escritura (esta aumenta en cada iteracion), si fuera el
		// caracter a borrar, lo "salta"
		while (pos_lectura < total_utilizados){
			if (vector_privado[pos_lectura] != a_borrar){
				vector_privado[pos_escritura] = vector_privado[pos_lectura];
				pos_escritura++;
			
			}
			pos_lectura++;
		
		}
	
		total_utilizados = pos_escritura;
	}
	
	//-------------------------------------------------
	//	Devuelve una secuencia de caracteres ordenada aplicando el algoritmo
	//	de counting sort, el cual usa el conteo de cada caracter.
	
	SecuenciaCaracteres CountingSort(){
		//Calculo del caracter minimo y del maximo
    	char minimo = vector_privado[0]; 
    	char maximo = vector_privado[0];
    	
    	for (int i = 1; i < total_utilizados; i++){
    		if (vector_privado[i] < minimo){
    			minimo = vector_privado[i];
			}
			
			if (vector_privado[i] > maximo){
    			maximo = vector_privado[i];
			}
			
    	}
    	
    	// Llamada al método CountingSortEntre
    	SecuenciaCaracteres secuencia_ord (CountingSortEntre(minimo, maximo));
    	
    	return secuencia_ord;
    }
    
	//-------------------------------------------------
	// 	Ordena los valores de la secuencia que hay entre un carácter 
	//	izquierda y otro carácter derecha
	SecuenciaCaracteres CountingSortEntre(char min, char max){
    	const int NUM_FREC = 300;
    	int frecuencias[NUM_FREC] = {0};
    	int num_caracteres = (max - min) + 1;
    	
    	//	Recorremos el vector privado realizando el conteo de las 
    	//	apariciones de cada caracter a traves del vector de frecuencias
    	for (int i = 0; i < total_utilizados; i++){
    		for (int j = 0; j < num_caracteres; j++){
    			if (vector_privado[i] == (min + j)){
    				frecuencias[j]++;
    				
				}
    		}
    	}
		
		SecuenciaCaracteres secuencia_ordenada;
		
		//	Añadiremos al vector ordenado cada caracter el numero de veces
		//	que indique el vector de frecuencias
		for (int i = 0; i < num_caracteres; i++){
			if (frecuencias[i] != 0){
				for (int j = 0; j < frecuencias[i]; j++){
					secuencia_ordenada.Aniade(min + i);
					
				}
			}
		}
		
		return (secuencia_ordenada);
	}
};

/****************************************************************************/
/****************************************************************************/
int main () {
	
	//-------------------------------------------------
	//	ENTRADA
	string cadena;
	
	cout << "Introduzca la secuencia de caracteres a ordenar: ";
	getline (cin, cadena);
	
	SecuenciaCaracteres secuencia_a_ordenar(cadena);
	
	//-------------------------------------------------
	//	CALCULOS
	
	SecuenciaCaracteres secuencia_ordenada (secuencia_a_ordenar.CountingSort());
	
	//-------------------------------------------------
	//	SALIDA
	
	cout << endl;
	cout << "Secuencia de caracteres sin ordenar: " 
		 << secuencia_a_ordenar.ToString() << endl;
		 
	cout << "Secuencia de caracteres ordenada: " 
		 << secuencia_ordenada.ToString() << endl;

	return 0;
}
