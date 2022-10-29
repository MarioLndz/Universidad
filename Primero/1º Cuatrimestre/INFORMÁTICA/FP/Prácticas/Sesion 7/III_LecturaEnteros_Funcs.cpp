/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 18 - III: Este programa servirá para comprobar el funcionamiento
	de tres funciones diferentes:
	
	1) LeeEntero: Leerá y devolverá un dato int. Si el valor leido no fuera un 
	   int, la función volvería a pedirlo hasta que se proporcione un valor 
	   correcto.
	   
	2) LeeEnteroEnRango: Leerá y devolverá un dato int en un rango dado. Si el 
	   valor leido no fuera int ó éste fuera menor que menor o mayor que mayor 
	   la función volvería a pedirlo hasta que se proporcionara un valor 
	   correcto.
	   
	3) LeeEnteroMayorOIgual: Leerá y devolverá un dato int que debe ser mayor o 
	   igual que referencia. Si el valor leido no fuera int ó éste fuera menor 
	   que referencia la función volvería a pedirlo hasta que se proporcionara 
	   un valor correcto.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>

using namespace std;

/*****************************************************************************
//	EsNumero

	Se comprobará si el string introducido está formado por un número real
	
	RECIBE: String a comprobar
	DEVUELVE: Verdadero o Falso
*****************************************************************************/
bool EsNumero (string cadena){
	bool es_numero = true;
	
	int longitud = cadena.length();
	
	//Primero comprobaremos que la cadena no esté vacía o que solo esté formada
	//por la coma decimal
	if (cadena == "." || cadena == ""){
		es_numero = false;
	} else {
		int n = 0;
		int coma_decimal = 0;
		
		//Comprueba que toda la cadena está formada por dígitos (con decimales)
		//si la cadena empieza con un signo, pasará al siguiente caracter
		if (cadena[0] == '-' || cadena[0] == '+'){
			n++;
		}
		
		while (n < longitud && es_numero) {
			//Comprobamos cómo está formada la cadena. Si encontramos una coma
			//decimal, la registramos en un contador. Si no, comprobamos que
			//el carácter es un dígito. Si no fuera un dígito o si hubiera
			//más de una coma decimal devolveremos FALSE
			if (cadena[n] == '.'){
				coma_decimal++;
			} else if (cadena[n] < '0' || cadena[n] > '9'){
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

	Se leerá y devolverá un dato int. Si el valor leido no 
	fuera un int, la función volverá a pedirlo hasta que se proporcione un 
	valor correcto.
	
	RECIBE: Título
	DEVUELVE: Número entero (int)
******************************************************************************/
int LeeEntero (string titulo){
	string num_introducido;
	bool no_caracter;
	
	double numero;
	
	do {
		cout << titulo;
		getline (cin, num_introducido);
		
		no_caracter = EsNumero (num_introducido);
		
		//Si la cadena introducida está formada solo por dígitos, la 
		//transformamos a un double
		if (no_caracter){
			numero = stod(num_introducido);
		}
		
	} while (!no_caracter || (numero - (int)numero != 0));

	return numero;
}

/*****************************************************************************
//	LeeEnteroEnRango:
	
	Se leerá y devolverá un dato int en un rango dado. Si el 
	valor leido no fuera int ó éste fuera menor que menor o mayor que mayor 
	la función volvería a pedirlo hasta que se proporcionara un valor 
 	correcto.
	
	RECIBE: Título, número maximo, número mínimo
	DEVUELVE: Número entero (int)
******************************************************************************/
int LeeEnteroEnRango (string titulo, int menor, int mayor){
	double numero;
	
	cout << "Rango = ["<< menor << ", " << mayor << "]" << endl;
	do {
		numero = LeeEntero (titulo);
	} while (numero < menor || numero > mayor);
	
	return numero;
}

/*****************************************************************************
//	LeeEnteroMayorOIgual
	
	Se leerá y devolverá un dato int que debe ser mayor o igual que referencia. 
	Si el valor leido no fuera int ó éste fuera menor que referencia la función 
	volvería a pedirlo hasta que se proporcionara un valor correcto.
	
	RECIBE: Título, número de referencia
	DEVUELVE: Número entero (int)
******************************************************************************/
int LeeEnteroMayorOIgual (string titulo, int referencia){
	double numero;
	
	cout << "(>= " << referencia << ")" << endl;
	do {
		numero = LeeEntero (titulo);
	} while (numero < referencia);
	
	return numero;
}

/*****************************************************************************/
int main () {
	//Constantes
	const int NUM_MIN = -5;
	const int NUM_MAX = 25;
	
	const int REFERENCIA = -10;
	
	//Variables
	int num_entero;
	int num_entero_enrango;
	int num_entero_conreferencia;
	
	//Entrada de datos
	num_entero = LeeEntero("Introduzca un número entero: ");
	cout << endl;
	
	num_entero_enrango = LeeEnteroEnRango("Número entero en rango: ", 
	NUM_MIN, NUM_MAX);
	cout << endl;
	
	num_entero_conreferencia = LeeEnteroMayorOIgual ("Número entero: ", 
	REFERENCIA);
	cout << endl;
	
	//Salida de datos
	cout << "1) Número entero = " << num_entero << endl;
	
	cout << "2) Número entero en el rango [" << NUM_MIN << ", " << NUM_MAX
		 << "] = " << num_entero_enrango << endl;
		 
	cout << "3) Número entero (>= " << REFERENCIA << ") = " 
		 << num_entero_conreferencia << endl;
	
	return 0;
}
