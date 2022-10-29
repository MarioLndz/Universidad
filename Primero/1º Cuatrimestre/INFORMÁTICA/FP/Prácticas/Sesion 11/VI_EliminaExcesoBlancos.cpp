/*****************************************************************************
//	Mario Líndez Martínez
//	Grupo: A2

	Ejercicio 36 - VI:Añadir un método EliminaExcesoBlancos() para eliminar el 
	exceso de caracteres en blanco, es decir, que sustituya todas las 
	secuencias de espacios en blanco por un sólo espacio. 
	
	Por ejemplo, si el vector original es: {' ','a','h',' ',' ',' ','c'}, 
	que contiene una secuencia de tres espacios	consecutivos, el vector 
	resultante debe ser {' ','a','h',' ','c'}.

******************************************************************************/

#include <iostream>
#include <string>

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
    		StringACaracteres (cadena);
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
		// Borra el exceso de espacios en blanco
		void EliminaExcesoBlancos() {
			int pos_lectura = 0;	//Apuntador de lectura
			int pos_escritura = 0;	//Apuntador de escritura
			
			int num_espacios = 0;
				
			// Recorreremos el vector, e ira contabilizando el numero de 
			// espacios consecutivos que encuentra. Si encuentra dos espacios
			// consecutivos, saltara al siguiente caracter sin escribirlo en
			// el vector
			for (pos_lectura = 0; pos_lectura < total_utilizados; 
				 pos_lectura++){			
				if(!isspace(vector_privado[pos_lectura])){	//No es espacio
	    			vector_privado[pos_escritura] = vector_privado[pos_lectura];
	    			pos_escritura++;
	    			num_espacios = 0;	//Reinicia el contador de espacios
	    			
	    		} else {
	    			if (num_espacios == 0){	//Se escribe el primer espacio
	    				vector_privado[pos_escritura] = 
													vector_privado[pos_lectura];
	    				pos_escritura++;
	    				num_espacios++;
	    				
	    			}else{
	    				num_espacios++;
	    			}
	    		}
			}
		
			total_utilizados = pos_escritura;
		}
			

	
	private:
		//------------------------------------------------
		// Método que rellena el vector privado del objeto a partir de un
		// dato string
		
		void StringACaracteres (string cadena) {
			int longitud = cadena.length();
			for (int i = 0; i < longitud; i++){
				
				Aniade(cadena.at(i));
			}
		}

};

/****************************************************************************/
/****************************************************************************/
int main() // Programa principal
{
	// Declaración de datos
	string cadena;
	
	//-------------------------------------------
	//	ENTRADA
	
	cout << "Introduzca una secuencia de caracteres: " << endl;
	cout << "> ";
	getline(cin, cadena);
	
	SecuenciaCaracteres secuencia(cadena);
	
	cout << "La secuencia introducida es: " << secuencia.ToString() << " y "
		 << "tiene " << secuencia.TotalUtilizados() << " elementos" << endl
		 << endl;
	
	//--------------------------------------------------
	//	CALCULOS
	
	secuencia.EliminaExcesoBlancos();
	
	//--------------------------------------------------
	//	SALIDA
	
	cout << endl;
	cout << "La secuencia simplificada (eliminando los excesos de espacios en "
		 << "blanco) es: " << secuencia.ToString() << endl;
	
	return 0;
}
