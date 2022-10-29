/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 42 - V: Este programa leera la posici�n inicial pos (fila y 
	columna, por separado) y la secuencia de �rdenes a ejecutar. Si el string 
	es correcto, el array ord se rellenar� a partir de cad_ordenes, siendo lon 
	la longitud de cad_ordenes.
	
	Despu�s de la lectura de los datos se har� lo siguiente:
		- Si la serie de �rdenes es correcta, muestre cu�ntas veces se visit� 
		  cada posici�n. Use una representaci�n bidimensional (figura 29).
		
		- Si la serie de �rdenes NO es correcta, el programa terminar� 
		  indicando cu�ntas �rdenes se pudieron ejecutar.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>
#include <iomanip>

using namespace std;

struct Posicion {
	int fila;
	int col;
};

/*****************************************************************************
// 	EliminaPrimerosSeparadores
	
	Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
	separadores de "cadena". Los caracteres separadores son el espacio en 
	blanco, el tabulador y el salto de línea. 
	Usaremos la funci�n isspace() para simplificar el c�lculo. 
 
	RECIBE:  cadena, string sobre la que se va a trabajar.
	DEVUELVE: el resultado de eliminar los primeros separadores de "cadena".
*****************************************************************************/
string EliminaPrimerosSeparadores (string cadena)
{	
	// Buscar el primer car�cter no espacio
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

/*****************************************************************************
//	EliminaUltimosSeparadores
	
	Devuelve una NUEVA cadena, resultante de eliminar los últimos caracteres 
	separadores de "cadena". Los caracteres separadores son el espacio en 
	blanco, el tabulador y el salto de l�nea. 
	Usaremos la funci�n isspace() para simplificar el c�lculo. 
	 
	Recibe: cadena, string sobre la que se va a trabajar.
	Devuelve: el resultado de eliminar los �ltimos separadores de "cadena".
*****************************************************************************/
string EliminaUltimosSeparadores (string cadena)
{
   	while (cadena.length()>0 && isspace(cadena.back()))
		cadena.pop_back();
        
	return (cadena);
}

/*****************************************************************************
//	EsNumero

	Se comprobar� si el string introducido est� formado por un n�mero real
	
	RECIBE: String a comprobar
	DEVUELVE: Verdadero o Falso
*****************************************************************************/
bool EsNumero (string cadena){
	bool es_numero = true;
	
	cadena = EliminaPrimerosSeparadores (cadena);
	cadena = EliminaUltimosSeparadores  (cadena);
	
	int longitud = cadena.length();
	
	//Primero comprobaremos que la cadena no est� vac�a o que solo est� formada
	//por la coma decimal
	if (cadena == "." || cadena == "" || cadena == "-" || cadena == "+"){
		es_numero = false;
	} else {
		int n = 0;
		int coma_decimal = 0;
		
		//Comprueba que toda la cadena est� formada por d�gitos (con decimales)
		//si la cadena empieza con un signo, pasar� al siguiente caracter
		if (cadena.at(0) == '-' || cadena.at(0) == '+'){
			n++;
		}
		
		while (n < longitud && es_numero) {
			//Comprobamos c�mo est� formada la cadena. Si encontramos una coma
			//decimal, la registramos en un contador. Si no, comprobamos que
			//el car�cter es un d�gito. Si no fuera un d�gito o si hubiera
			//m�s de una coma decimal devolveremos FALSE
			if (cadena.at(n) == '.'){
				coma_decimal++;
			} else if (cadena.at(n) < '0' || cadena.at(n) > '9'){
				es_numero = false;
			}
			
			if (coma_decimal > 1){
				es_numero = false;
			}
			
			n++;
		}
	}
	return es_numero;
}

/*****************************************************************************
//	LeeEntero

	Se leer� y devolver� un dato int. Si el valor leido no 
	fuera un int, la funci�n volver� a pedirlo hasta que se proporcione un 
	valor correcto.
	
	RECIBE: T�tulo
	DEVUELVE: N�mero entero (int)
******************************************************************************/
int LeeEntero (string titulo){
	string num_introducido;
	bool no_caracter;
	
	double numero;
	
	do {
		cout << titulo;
		getline (cin, num_introducido);
		
		no_caracter = EsNumero (num_introducido);
		
		//Si la cadena introducida est� formada solo por d�gitos, la 
		//transformamos a un double
		if (no_caracter){
			numero = stod(num_introducido);
		}
		
	} while (!no_caracter || (numero - (int)numero != 0));

	return numero;
}

/***************************************************************************/
// Devuelve si la cadena de ordenes es v�lida

bool OrdenesOk(string ord){
	
	int longitud = ord.length();
	
	bool ordenes_ok = true;
	
	int pos = 0;
	while(pos < longitud && ordenes_ok){
		char orden = ord.at(pos);
		
		if(orden!='I' && orden!='D' && orden!='A' && orden!='B' ){
			ordenes_ok = false;
		}
			
		pos++;
	}
	
	return ordenes_ok;
}

/****************************************************************************
//	StrToUpper

	Esta funci�n transforma todos los caracteres que forman una cadena a 
	may�scula. Los n�meros y los s�mbolos no se ver�n modificados.
	
	RECIBE: Cadena
	DEVUELVE: Cadena en may�sculas
*****************************************************************************/
string StrToUpper (string cadena){
	string cadena_mayus;
	int longitud = cadena.length();
	
	//Transformamos la cadena en otra con los caracteres en may�sculas
	for (int n = 0; n < longitud; n++){
		cadena_mayus += toupper(cadena.at(n));
	}
	
	return cadena_mayus;
}

/*****************************************************************************/
/*****************************************************************************/

int main (){
	const int FILAS = 20;
	const int COLUMNAS = 20;
	int frecuencias[FILAS][COLUMNAS];
	
	//Inicializo la matriz a 0
	for(int n=0; n < FILAS; n++){
		for(int i=0; i < COLUMNAS; i++){
			frecuencias[n][i] = 0;
		}
	}
	
	//-------------------------------
	//	ENTRADA	
	
	Posicion pos;
	
	cout << "Posicion inicial: " << endl;
	do{
		pos.fila = LeeEntero("\tx = ");	
	} while (pos.fila < 1 || pos.fila > FILAS);
	
	
	do{
		pos.col = LeeEntero("\ty = ");
	} while (pos.col < 1 || pos.col > COLUMNAS);
	
	pos.fila = FILAS - pos.fila;	// "Invertimos" la posicion x
	pos.col -= 1;				// Convertimos la posicion y (matriz empieza en 0
							// pero el tablero en 1)
	
	const int MAX_ORD = 100;
	char ordenes[MAX_ORD];
	
	string ord;
	
	do {
		cout << "Introduzca las ordenes (I/D/A/B): ";
		getline(cin, ord);
		
		ord = EliminaPrimerosSeparadores(ord);
		ord = EliminaUltimosSeparadores(ord);
		ord = StrToUpper(ord);
		
	} while (!OrdenesOk(ord));
	
	//Pasamos cada orden del string al array
	int lon = ord.length();
	
	for (int i = 0; i < lon; i++){
		ordenes[i] = ord.at(i);
	}
	
	//-------------------------------
	//	CALCULOS
	
	bool orden_ok = true;
	int num_ord_ejecutadas = 0;
	
	frecuencias[pos.fila][pos.col]++;	//Posicion inicial +1
	
	while (orden_ok && num_ord_ejecutadas < lon){
		switch (ordenes[num_ord_ejecutadas]){
			case ('I'):	//Se mueve a la Izquierda
				pos.col--;
				break;
					
			case ('D'):	//Se mueve a la Derecha
				pos.col++;
				break;
				
			case ('A'):	//Se mueve hacia Arriba
				pos.fila--;
				break;
				
			case ('B'):	//Se mueve hacia Abajo
				pos.fila++;
				break;
		}
		frecuencias[pos.fila][pos.col]++;
		
		
		if ((pos.fila >= 0 && pos.fila < FILAS) && 
			(pos.col >= 0 && pos.col < COLUMNAS)){
			num_ord_ejecutadas++;
			
		} else {
			orden_ok = false;			
		}
	}
	
	string tablero[FILAS][COLUMNAS];
	
	if (orden_ok){
		for (int n = 0; n < FILAS; n++){
			for (int i = 0; i < COLUMNAS; i++){
				if (frecuencias[n][i] != 0){
					tablero[n][i] = to_string(frecuencias[n][i]);
					
				} else {
					tablero[n][i] = ".";
				}
				
			}
		}
	}
	
	//-------------------------------
	//	SALIDA
	
	if (orden_ok){
		cout << endl;
		cout << "La serie de ordenes es correcta" << endl;
		cout << "Se ejecutaron " << num_ord_ejecutadas << " ordenes" << endl;
		
		cout << endl << endl;
		//Margen superior
		cout << setw(6) << ":"; 
		for (int n = 1; n <= COLUMNAS; n++){
			cout << setw(5) << n;
		}
		cout << endl;
		
		cout << setw(5) << " "; 
		for (int n = 0; n < (COLUMNAS*5) + 3; n++){
			cout << "-";
		}
		cout << endl;
		
		//Tablero
		for (int i = 0; i < FILAS; i++){
			//Margen izquierdo
			cout << setw(4) << (FILAS - i)  << " :";
			
			//Tablero
			for (int n = 0; n < COLUMNAS; n++){
				cout  << "   " << setw(2) << frecuencias[i][n];
			}
			
			//Margen derecho
			cout << " : " << setw(3) << (FILAS - i) ;
			
			cout << endl;
		}
		
		//Margen inferior
		cout << setw(5) << " "; 
		for (int n = 0; n < (COLUMNAS*5) + 3; n++){
			cout << "-";
		}
		cout << endl;
		
		cout << setw(6) << ":"; 
		for (int n = 1; n <= COLUMNAS; n++){
			cout << setw(5) << n;
		}
		cout << endl;
		
		
	} else {
		cout << endl;
		cout << "La serie de ordenes NO es correcta" << endl;
		cout << "Se ejecutaron " << num_ord_ejecutadas << " ordenes" << endl;
	}
	
	return 0;
}

