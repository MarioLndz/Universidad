/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 46 - VII: Ampliar la clase TablaRectangularEnteros con un método 
	que busque la fila de la matriz que más se parezca a un vector de enteros 
	(clase SecuenciaEnteros) al que llamaremos referencia. El método devolverá 
	el número de la fila.
	
	La similitud entre dos vectores vendrá dada por la distancia euclídea 
	entre ambos.
	
	Además, la búsqueda solo se hará sobre un conjunto seleccionado de filas de 
	la tabla, enumeradas en la secuencia de enteros filas_a_comparar (un objeto 
	de la clase SecuenciaEnteros).

******************************************************************************/

#include <iostream>	// Inclusión de los recursos de E/S
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Lector{
private:
	string titulo;
public:
	/**************************************************************************/
	//Constructores
	Lector(string el_titulo):
		titulo(el_titulo)
	{
	}
	
	Lector(): titulo("")
	{
	}
	
	/**************************************************************************/
	//LECTURA DE ENTEROS
	/**************************************************************************/
	// Lee un dato int. La lectura está etiquetada con "titulo". La lectura se 
	// efectúa repetidamente hasta que se introduce un valor int correcto. 
	// 
	// Recibe:  titulo, la cadena usada para etiquetar la lectura .
	// Devuelve: el entero válido leído. 
	/**************************************************************************/
	
	int LeeEntero() {
		string cadena;
	
		do {
			cout << titulo;
			getline (cin, cadena);
							
		} while (!EsEntero(cadena));
				
		int numero = stoi(cadena);
	 	
		return (numero);	
	}
	/************************************************************************/
	// Lee un dato int que debe estar entre "menor" y "mayor" y lo devuelve.
	// La lectura estÃ¡ etiquetada con "titulo"
	// PRE: menor <= mayor 
	// POST: menor <= valor devuelto <= mayor
	/************************************************************************/
	int LeeEnteroEnRango(int menor, int mayor){
		int numero;
	
		do {
			numero = LeeEntero ();
		} while ((numero<menor) || (numero>mayor));
		
		return (numero);
	}
	
	/**************************************************************************/
	// Lee y devuelve un dato int. La lectura está etiquetada con "titulo". 
	// Para que se considere correcta la lectura el dato int debe estar 
	// comprendido entre "menor" y "mayor". 
	// 
	// Recibe:  titulo, la cadena usada para etiquetar la lectura .
	// Devuelve: el entero válido leído. 
	//
	// PRE: menor <= mayor 
	// POST: menor <= valor devuelto <= mayor 
	/**************************************************************************/
	
	int LeeEnteroMayorOIgual(int referente)
	{
		int numero;
	
		do {
			numero = LeeEntero ();	
		} while (numero < referente);
		
		return (numero);
	}
	
	/************************************************************************/
	//LECTURA DE REALES
	/**************************************************************************/
	// Lee un dato double.
	// La lectura estÃ¡ etiquetada con "titulo"
	// La lectura se efectÃºa repetidamente hasta que se introduce un valor 
	// double correcto. 
	// 
	// Devuelve: el double vÃ¡lido leÃ­do. 
	
	double LeeReal()
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
	// La lectura estÃ¡ etiquetada con "titulo"
	// PRE: menor <= mayor 
	// POST: menor <= valor devuelto <= mayor 
	
	double LeeRealEnRango(double menor, double mayor)
	{
		double numero;
	
		do {
			numero = LeeReal ();
		} while ((numero<menor) || (numero>mayor));
		
		return (numero);
	}
	
	/************************************************************************/
	// Lee un dato double que debe ser mayor o igual que "menor" y lo devuelve.
	// La lectura estÃ¡ etiquetada con "titulo"
	// POST: menor <= valor devuelto 
	
	double LeeRealMayorOIgual(double menor)
	{
		double numero;
	
		do {
			numero = LeeReal ();
		} while (numero < menor);
		
		return (numero);
	}
	
	/************************************************************************/
	//Método Set
	void SetTitulo(string el_titulo){
		titulo=el_titulo;
	}
	
private:
	/**************************************************************************/
	// Devuelve una NUEVA cadena, resultante de eliminar los Ãºltimos caracteres 
	// separadores de "cadena". Los caracteres separadores son el espacio en 
	// blanco, el tabulador y el salto de lÃ­nea. 
	// 
	// Recibe:  cadena, string sobre la que se va a trabajar.
	// Devuelve: el resultado de eliminar los Ãºltimos separadores de "cadena".
	/**************************************************************************/
	
	string EliminaUltimosSeparadores(string cadena)
	{
	   	while (cadena.length()>0 && isspace(cadena.back()))
			cadena.pop_back();
	        
		return (cadena);
	}
	
	/**************************************************************************/
	// Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
	// separadores de "cadena". Los caracteres separadores son el espacio en 
	// blanco, el tabulador y el salto de línea. 
	// 
	// Recibe:  cadena, string sobre la que se va a trabajar.
	// Devuelve: el resultado de eliminar los primeros separadores de "cadena".
	/**************************************************************************/
	
	string EliminaPrimerosSeparadores(string cadena)
	{	
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
	/**************************************************************************/
	// Comprueba si un string es la representación textual de un dato int
	// 
	// Recibe:  cadena, string sobre la que se va a trabajar.
	// Devuelve: "true" si "cadena"  es la representación textual de un entero
	/**************************************************************************/
	
	bool EsEntero(string cadena) 
	{
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
			
			// Todos los caracteres desde la posición "pos" deben ser dígitos
			
			while ((pos < long_cadena) && es_entero) {
				if (!isdigit(cadena.at(pos))) es_entero = false;
				else pos++;
			}	
		}
		
		return (es_entero);
	}
	
	/**************************************************************************/
	// Devuelve "true" si "cadena" es la representaciÃ³n textual de un entero 
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
/****************************************************************************/
//	SecuenciaEnteros
//	Clase en la que se guardaran en un vector datos de tipo entero
class SecuenciaEnteros {
private:
	
	static const int TAMANIO = 50; // Número de casillas disponibles
	int vector_privado[TAMANIO];

	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:

	/***********************************************************************/
	// Constructores
	
	//------------------------------------------
	//	Constructor sin argumentos

	SecuenciaEnteros (void)
		:	total_utilizados (0)
	{}

	/***********************************************************************/
	// Metodos de Consulta (GET)
	
	//------------------------------------------
	// Número de casillas ocupadas
	int TotalUtilizados (void) {
		return (total_utilizados);
	}

	//------------------------------------------
	// Número de casillas disponibles
	int Capacidad (void) {
		return (TAMANIO);
	}
	
	//------------------------------------------
	//	Calculos
	
	//------------------------------------------
	// Añade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento.
	// 		El nuevo elemento se coloca al final del vector.
	// 		Si no hay espacio, no se hace nada.

	void Aniade (int nuevo) {
		if (total_utilizados < TAMANIO) {
			//Aniadimos el vector
			vector_privado[total_utilizados] = nuevo;
			
			//Actualizamos el numero de total utilizados
			total_utilizados++;
		}
	}

	//------------------------------------------
	// Eliminar el dato de la posición indicada por "indice".
	// Realiza un borrado físico (con desplazamiento y sustitución).
	//
	// PRE: 0 <= indice < total_utilizados

	void Elimina (int indice) {
		// Recorremos de izquierda a derecha toda las componentes
		// que hay a la derecha de la posición a eliminar
		// Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posición del último

			for (int i = indice ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];

			total_utilizados--;
		}
	}

	//------------------------------------------
	// Devuelve el elemento de la casilla "indice"
	//
	// PRE: 0 <= indice < total_utilizados

	int Elemento (int indice) {
		return vector_privado[indice];
	}

	//------------------------------------------
	// Devuelve true si la secuencia está vacía

	bool EstaVacia (void) {
		return (total_utilizados == 0);
	}

	//------------------------------------------
	// "Vacía" una secuencia

	void EliminaTodos (void) {
		total_utilizados = 0;
	}

	//------------------------------------------
	// Devuelve la posición del mínimo valor de la secuencia
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int PosicionMinimo (int izda, int dcha) {
		int posicion_minimo;
		int minimo;

		minimo = vector_privado[izda];
		posicion_minimo = izda;

		for (int i = izda; i <= dcha ; i++) {

			if (vector_privado[i] < minimo){
				minimo = vector_privado[i];
				posicion_minimo = i;
			}
		}

		return (posicion_minimo);
	}

	//------------------------------------------
	// Devuelve la posición del máximo valor de la secuencia
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int PosicionMaximo (int izda, int dcha) {
		int posicion_maximo;
		int maximo;

		maximo = vector_privado[izda];
		posicion_maximo = izda;

		for (int i = izda; i <= dcha ; i++) {

			if (vector_privado[i] > maximo){
				maximo = vector_privado[i];
				posicion_maximo = i;
			}
		}

		return (posicion_maximo);
	}

	//------------------------------------------
	// Devuelve el mínimo de la secuencia.
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int Minimo (int izda, int dcha) {
		return (vector_privado[PosicionMinimo(izda, dcha)]);
	}


	//------------------------------------------
	// Devuelve el máximo de la secuencia.
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int Maximo (int izda, int dcha) {
		return (vector_privado[PosicionMaximo(izda, dcha)]);
	}

	//------------------------------------------
	// Forma un dato string en el que se represente el objeto
	string ToString (void)	{
		string cad;
			
		for (int i = 0; i < total_utilizados; i++){
			
			cad+= to_string(vector_privado[i]) + " ";
		}
			
		return(cad);
	}
};

/***************************************************************************/
//	TablaRectangularEnteros
//	Representa una tabla formada por enteros. La tabla se formara a partir de
//	una matriz
class TablaRectangularEnteros {
private:
    static const int NUM_FILS = 50; // Filas disponibles
    static const int NUM_COLS = 40; // Columnas disponibles
    
    int  matriz_privada[NUM_FILS][NUM_COLS];

    // PRE: 0 <= filas_utilizadas <= NUM_FILS
    // PRE: 0 <= col_utilizadas < NUM_COLS
    
    int filas_utilizadas;
    int cols_utilizadas;

public:
	//****************************************************************
	//	CONSTRUCTORES
	
	//------------------------------------------------
	// Constructor sin argumentos - Crea matriz nula

	TablaRectangularEnteros(void)
		: 	filas_utilizadas(0), 
			cols_utilizadas(0) 
	{}
	
	//------------------------------------------------
	// Recibe "numero_de_columnas" que indica el número de 
	// columnas que deben tener TODAS las filas. 
	// PRE: numero_de_columnas <= MAX_COL

	TablaRectangularEnteros (int numero_de_columnas) 
		: 	filas_utilizadas(0), 
		  	cols_utilizadas(numero_de_columnas)
	{}

	//------------------------------------------------
	//	Recibe una secuencia de enteros. El número de 
	// 	elementos de la secuencia es el valor que se usa como "col_utilizadas"
	// 	PRE: primera_fila.TotalUtilizados() <= MAX_COL

	TablaRectangularEnteros (SecuenciaEnteros primera_fila)
			: 	filas_utilizadas(0), 
				cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}
	
	
	//*****************************************************************
	//	Metodos de lectura
	
	//------------------------------------------------
	// Número máximo de filas

	int CapacidadFilas (void) {
		return (NUM_FILS);
	}

	//------------------------------------------------
	// Número máximo de columnas

	int CapacidadColumnas (void) {
		return (NUM_COLS);
	}

	//------------------------------------------------
	// Número real de filas usadas
	
	int FilasUtilizadas (void) {
		return (filas_utilizadas);
	}

	//------------------------------------------------
	// 	Número real de columnas usadas

	int ColumnasUtilizadas (void) {
		return (cols_utilizadas);
	}

	//------------------------------------------------
	// 	Devuelve el dato que ocupa la casilla de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	int Elemento (int fila, int columna) {
		return (matriz_privada[fila][columna]);
	}
	
	//**********************************************************************
	//	Calculos
	
	//------------------------------------------------
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void) {
		return (filas_utilizadas == 0);
	}
	
	//------------------------------------------------
	// Devuelve una fila completa (un objeto "SecuenciaEnteros")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaEnteros Fila (int indice_fila) {
		SecuenciaEnteros fila;

		for (int col=0; col<cols_utilizadas; col++)
			fila.Aniade(matriz_privada[indice_fila][col]);

		return (fila);
	}

	//------------------------------------------------
	// Devuelve una columna completa (un objeto "SecuenciaEnteros")
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaEnteros Columna (int indice_columna) {
		SecuenciaEnteros columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade (matriz_privada[fil][indice_columna]);

		return (columna);
	}

	//------------------------------------------------
	// Añade una fila completa (un objeto "SecuenciaEnteros")
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaEnteros fila_nueva) {
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[filas_utilizadas][col]=fila_nueva.Elemento(col);

			filas_utilizadas++;
		}
	}

	//------------------------------------------------
	// "Vacía" una tabla

	void EliminaTodos (void) {
		filas_utilizadas = 0;
	}
	
	//------------------------------------------------
	// Calcula si dos matrices rectangulares son iguales
	// Compara la tabla implícita con "otra" (tabla explícita) 

	bool EsIgual (TablaRectangularEnteros otra_tabla) {
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra_tabla.FilasUtilizadas()) ||  
			 (cols_utilizadas != otra_tabla.ColumnasUtilizadas()))		
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				int c=0; 
				
				while (c<cols_utilizadas && son_iguales) {
			
					if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
						son_iguales = false;
						
					c++;
					
				} // while c
	
				f++;
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}
	
	//------------------------------------------------
	// Devuelve la traspuesta de la matriz (si es posible calcularse)
	// Si no se puede calcular la traspuesta se devuelve una matriz nula. 
	//
	// PRE: filas_utilizadas <= MAX_COL
	// PRE: cols_utilizadas  <= MAX_FIL

	TablaRectangularEnteros Traspuesta (void) {		
	    TablaRectangularEnteros traspuesta; // Inicialmente vacía
		
		if ((filas_utilizadas <= NUM_COLS) && (cols_utilizadas  <= NUM_FILS)) {
		
			// La traspuesta tiene tantas filas como columnas tiene la
			// matriz original
	
			TablaRectangularEnteros solucion (filas_utilizadas);
	
	
			SecuenciaEnteros columna; 	// Las filas de "traspuesta" serán las
										// columnas de la tabla implícita
	
			for (int col = 0; col < cols_utilizadas; col++){
	
				columna = Columna(col);
				solucion.Aniade(columna);
			}
			
			traspuesta = solucion;
		} 

		return (traspuesta);
	}			
	

	//------------------------------------------------
	// Calcula si una matriz es simétrica.
	//
	// Este método comprueba directamente si cada componente es igual a
	// su simétrica, parando el recorrido cuando encuentre una componente
	// que no lo verifique.
	//
	// Evita el cálculo de la traspuesta, y el problema que puede surgir
	// si no se puede calcular la traspuesta de la matriz por problemas de
	// capacidad.
	//
	// PRE: La matriz debe ser cuadrada. 

	bool EsSimetrica (void) {
		bool es_simetrica = true;

		// Si el número de filas y columnas no coinciden, no hay que seguir
		// porque la matriz no es simétrica.

		es_simetrica = (filas_utilizadas == cols_utilizadas);

		if (es_simetrica) {

			int f=0;

			while (f<filas_utilizadas && es_simetrica) {

				int c=0;

				while (c<cols_utilizadas && es_simetrica) {

					if (matriz_privada[f][c] != matriz_privada[c][f])
						es_simetrica = false;

					c++;

				} // while c

				f++;

			} // while f

		} // if (es_simetrica)

		return (es_simetrica);
	}
					
	//------------------------------------------------
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaEnteros".
	// 
	// Recibe: 	num_fila, la posición que ocupará "fila_nueva" cuando se 
	//			inserte en la tabla.
	//		   	fila_nueva, la secuencia que se va a insertar. Se trata 
	//			de un objeto de la clase "SecuenciaEnteros". 
	//
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaEnteros fila_nueva) {
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {
				
				for (int col = 0; col < numero_columnas_fila_nueva; col++)
					matriz_privada[fil][col]=matriz_privada[fil-1][col];
			}
			
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[num_fila][col]=fila_nueva.Elemento(col);	
			
			filas_utilizadas++; // Actualización del tamaño de la tabla.
		}
	}

	//------------------------------------------------
	// Elimina una fila completa, dada una posición. 
	// 
	// Recibe: num_fila, la posición de la fila a eliminar.
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila) {		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posición "num_fila" se copia la que está en la posición
			// siguiente ("num_fila"+1), en su lugar se copia que está en 
			// "num_fila"+2, ... y en la posición "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {
			
				int num_columnas = cols_utilizadas;
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
			}
			
			filas_utilizadas--; // Actualización del tamaño de la tabla.
		}
	}	
	
	//------------------------------------------------
	// Devuelve TRUE si la matriz contiene el valor "buscado"
	
	bool Contiene (int buscado) {
		bool encontrado = false;

		// Recorrido por columnas 

		int col = 0;

		while (col < cols_utilizadas && !encontrado) {

			int fil=0;

			while (fil < filas_utilizadas && !encontrado) {

				if (matriz_privada[fil][col] == buscado)
					encontrado = true;
				
				fil++;

			} // while fil

			col++; 

		} // while col

		return (encontrado);
	}
		
	//------------------------------------------------
	// 	Busca en la matriz privada del objeto la fila más 
	// 	parecida a un vector de referencia entre unas filas determinadas
	// 	de la matriz, que vienen dadas por la secuencia filas_a_comparar
	//
	// 	Recibe: SecuenciaEnteros referencia, SecuenciaEnteros filas_a_comparar
	// 	Devuelve: la posición de la fila
	//
	// 	PRE: referencia.TotalUtilizados() = cols_utilizadas
	// 	PRE: 0 < filas_a_comparar.TotalUtilizados <= filas_utilizadas
	// 	PRE: filas_a_comparar.Elemento(i) 
	// 	con i = 0, 1,..., filas_a_comparar.TotalUtilizados() - 1 sea >= 0 y
	// 	<= filas_utilizadas - 1
	
	int FilaMasCercana (SecuenciaEnteros referencia, 
						SecuenciaEnteros filas_a_comparar) {
		double distancia = 0;
		double distancia_min = 0;
		int fila_mas_cercana=0;
		
		// En caso de que solo hubiese una fila con la que comparar, se 
		// establece la distancia mínima calculando la distancia euclídea
		// con respecto a la primera fila y la fila más cercana sería la 0
		
		for (int i = 0; i < cols_utilizadas; i++){
			
			distancia_min += 
			pow((referencia.Elemento(i)-
			Elemento(filas_a_comparar.Elemento(0), i)), 2);
		}
		
		distancia_min = sqrt(distancia_min);
		
		
		// En caso de que haya más de una fila con la que comparar, se repite
		// el proceso anterior a partir de la segunda fila.
		
		for (int i = 1; i < filas_a_comparar.TotalUtilizados(); i++){
			
			for (int j = 0; j < cols_utilizadas; j++){
				
				distancia += 
				pow ((referencia.Elemento(j)
				-Elemento(filas_a_comparar.Elemento(i), j)), 2);
			}
			
			distancia = sqrt(distancia);
			
			// En caso de que la distancia que se calcule sea menor que la 
			// la distancia mínima, esta se actualiza, y se establece como 
			//fila más cercana la i
			
			if (distancia < distancia_min){
				
				distancia_min = distancia;
				fila_mas_cercana=i;
			}
			
			// Tras todo este proceso, se borra la distancia calculada para
			// la siguiente iteración
			
			distancia = 0;
		}
		
		return fila_mas_cercana;
	}
	
	//------------------------------------------------
	// Representa mediante un dato string el estado del objeto. En este caso,
	// muestra los elementos de la matriz dato miembro del objeto dispuestos 
	// por filas y columnas
	
	string ToString (void) {
		string cad;
		
		for (int i = 0; i < filas_utilizadas; i++){
			cad += "\t";
			
			for (int j = 0; j < cols_utilizadas; j++){
				
				cad += to_string(matriz_privada[i][j]) + " ";
			}
			
			cad+= "\n";
		}
		
		return(cad);
	}
	
};

/****************************************************************************/
/****************************************************************************/
int main () {
   	// Datos
	
	int filas_utilizadas;
	int cols_utilizadas;
	
	const int MAX_FIL = 50;
	const int MAX_COL = 40;
	
	Lector lector;

	//------------------------------------------------
	//	ENTRADA
		
	cout << "Buscaremos la fila que mas proxima este a un vector de referencia";
	cout << endl << endl;
	
	cout << "Defina la matriz:" << endl;
	
	lector.SetTitulo("\t- Nº de filas: ");
	filas_utilizadas = lector.LeeEnteroEnRango(1, MAX_FIL);
	
	lector.SetTitulo("\t- Nº de columnas: ");
	cols_utilizadas = lector.LeeEnteroEnRango(1, MAX_COL);
	
	TablaRectangularEnteros tabla (cols_utilizadas);
	
	lector.SetTitulo("Introduzca un número real: ");
	SecuenciaEnteros a_aniadir;
	
	for (int i = 0; i < filas_utilizadas; i++){
		
		cout << endl;
		cout << "Valores de la fila " + to_string(i+1) + ": ";
		cout << endl;
		
		for (int j = 0; j < cols_utilizadas; j++){		
			lector.SetTitulo("\t A" + to_string(i+1) + "." + to_string (j+1) 
							 + "= ");
			
			a_aniadir.Aniade(lector.LeeEntero());
			
		}
		
		tabla.Aniade(a_aniadir);
		
		a_aniadir.EliminaTodos();
	}
	
	// Mostraremos la matriz
	cout << endl;
	cout << "La tabla introducida es: " << endl;
	cout << tabla.ToString() << endl;
	
	// Pedimos el vector a buscar en dicha matriz
	cout << "Introduzca el vector a comparar en la matriz "
		 << "(componente a componente): " << endl;
	lector.SetTitulo("> ");
	
	SecuenciaEnteros referencia;
	
	for (int i = 0; i < cols_utilizadas; i++){
		referencia.Aniade(lector.LeeEntero());
	}
	
	cout << endl;
	
	// Entrada del vector de filas a comparar
	lector.SetTitulo ("Nº de filas entre las que se va a buscar: ");
	int tamanio_posiciones = lector.LeeEnteroEnRango(1, filas_utilizadas);
	
	lector.SetTitulo("Posición: ");
	SecuenciaEnteros posiciones;
	
	for (int i = 0; i < tamanio_posiciones; i++) {
		posiciones.Aniade(lector.LeeEnteroEnRango(0, filas_utilizadas-1));
	}
	
	//------------------------------------------------
	//	CALCULOS
	
	int fila_mas_cercana = tabla.FilaMasCercana(referencia, posiciones);
	
	//------------------------------------------------
	//	SALIDA
	
	cout << endl << endl;
	cout << "La fila más similar al vector introducido es la de índice  : "  
		 << fila_mas_cercana << endl << endl;
	
	return 0;
}
