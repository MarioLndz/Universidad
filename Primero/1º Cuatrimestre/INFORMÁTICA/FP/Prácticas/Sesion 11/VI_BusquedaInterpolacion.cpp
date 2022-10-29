/*****************************************************************************
//	Mario Líndez Martínez
//	Grupo: A2

	Ejercicio 42 - VI: Se implementara la Búsqueda por Interpolación en la 
	clase SecuenciaEnteros. El método busca un valor buscado entre las 
	posiciones izda y dcha.

******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class SecuenciaEnteros {

	private:

    	static const int TAMANIO = 100; // Núm.casillas disponibles
    	int vector_privado[TAMANIO];

    	// PRE: 0<=total_utilizados<=TAMANIO

    	int total_utilizados; // Núm.casillas ocupadas

	public:
		//****************************************************/
		//	CONSTRUCTORES
		
    	//------------------------------------------------
    	// Constructor sin argumentos

    	SecuenciaEnteros (void) : total_utilizados (0)
    	{}
		
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

    	void Aniade (int nuevo) {
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
            	cadena += to_string(vector_privado[i]);
			}
			
			cadena += "}";
        	return (cadena);
    	}
    	
    	//------------------------------------------------
    	// Busca un elemento en el vector privado (debera ordenarse previamente)
    	// a traves del metodo de busqueda por interpolacion y devolvera la
    	// posicion en la q se encuentra
    	//
    	// PRE: El vector debe estar distribuido uniformemente:
    	//		v[x] - v[x+1] = v[x+2] - v[x+3]
    	// POST: El vector se ordenara y dara la posicion del elemento relativa
    	//		 al vector ordenado. Si no lo encontrara, enviara un -1
    	
    	int BusquedaPorInterpolacion(int buscado){
			OrdenaVector();
			
			int izda = 0;
    		int dcha = total_utilizados - 1;
    		int centro = (((buscado - vector_privado[izda])*(dcha - izda)) /
    					  (vector_privado[dcha] - vector_privado[izda])) + izda;
    					  
    		bool encontrado = false;
    		
    		while (izda <= dcha && !encontrado){
    			if (vector_privado[centro] == buscado){
    				encontrado = true;
				
				} else if (buscado < vector_privado[centro]){
					dcha = centro - 1;
				} else {
					izda = centro + 1;
				}
				
				centro = (((buscado - vector_privado[izda])*(dcha - izda)) /
    					  (vector_privado[dcha] - vector_privado[izda])) + izda;
			}
			
			int pos_buscado = -1;
			if (encontrado){
				pos_buscado = centro;
			}
			
			return pos_buscado;
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
			
};

/****************************************************************************/
/****************************************************************************/
int main() {	// Programa principal
	// Declaración de datos
	string cadena;
	
	SecuenciaEnteros secuencia;
	
	//-------------------------------------------
	//	ENTRADA
	
	// Hemos añadido los impares del 1 al 21 para formar una secuencia
	// distribuida uniformemente. Esto se podria haber hecho automaticamente
	// con un bucle for, pero asi probamos tambien que el vector se ordena
	// correctamente
	secuencia.Aniade(21);
	secuencia.Aniade(11);
	secuencia.Aniade(5);
	secuencia.Aniade(15);
	secuencia.Aniade(7);
	secuencia.Aniade(1);
	secuencia.Aniade(19);
	secuencia.Aniade(3);
	secuencia.Aniade(13);
	secuencia.Aniade(9);
	secuencia.Aniade(17);
	
	/*	Otra alternativa para añadir los impares
	for (int n = 1; n <= 10; n++){
		int numero = (2*n) - 1;
		secuencia.Aniade(numero)
	}
	*/
	
	cout << "La secuencia introducida es: " << secuencia.ToString() << " y "
		 << "tiene " << secuencia.TotalUtilizados() << " elementos" << endl
		 << endl;
	
	secuencia.OrdenaVector();
	
	cout << "La secuencia ordenada es " << secuencia.ToString() << endl;
	
	int buscado;
	cout << "Elemento a buscar: ";
	cin >> buscado;
	
	//--------------------------------------------------
	//	CALCULOS
	int pos_buscado = secuencia.BusquedaPorInterpolacion(buscado);
		
	
	//--------------------------------------------------
	//	SALIDA
	if (pos_buscado == -1){
		cout << "Este elemento no se encuentra en la secuencia" << endl;
	} else {
		cout << "El elemento buscado (" << buscado << ") se encuentra en la "
			 << "posicion " << pos_buscado << endl;
	}
	
	return 0;
}
