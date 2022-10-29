/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 18 - III: Este programa servir� para comprobar el funcionamiento
	de tres funciones diferentes:
	
	1) LeeEntero: Leer� y devolver� un dato int. Si el valor leido no fuera un 
	   int, la funci�n volver�a a pedirlo hasta que se proporcione un valor 
	   correcto.
	   
	2) LeeEnteroEnRango: Leer� y devolver� un dato int en un rango dado. Si el 
	   valor leido no fuera int � �ste fuera menor que menor o mayor que mayor 
	   la funci�n volver�a a pedirlo hasta que se proporcionara un valor 
	   correcto.
	   
	3) LeeEnteroMayorOIgual: Leer� y devolver� un dato int que debe ser mayor o 
	   igual que referencia. Si el valor leido no fuera int � �ste fuera menor 
	   que referencia la funci�n volver�a a pedirlo hasta que se proporcionara 
	   un valor correcto.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>

using namespace std;

/*****************************************************************************
//	EsNumero

	Se comprobar� si el string introducido est� formado por un n�mero real
	
	RECIBE: String a comprobar
	DEVUELVE: Verdadero o Falso
*****************************************************************************/
bool EsNumero (string cadena){
	bool es_numero = true;
	
	int longitud = cadena.length();
	
	//Primero comprobaremos que la cadena no est� vac�a o que solo est� formada
	//por la coma decimal
	if (cadena == "." || cadena == ""){
		es_numero = false;
	} else {
		int n = 0;
		int coma_decimal = 0;
		
		//Comprueba que toda la cadena est� formada por d�gitos (con decimales)
		//si la cadena empieza con un signo, pasar� al siguiente caracter
		if (cadena[0] == '-' || cadena[0] == '+'){
			n++;
		}
		
		while (n < longitud && es_numero) {
			//Comprobamos c�mo est� formada la cadena. Si encontramos una coma
			//decimal, la registramos en un contador. Si no, comprobamos que
			//el car�cter es un d�gito. Si no fuera un d�gito o si hubiera
			//m�s de una coma decimal devolveremos FALSE
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

/*****************************************************************************
//	LeeEnteroEnRango:
	
	Se leer� y devolver� un dato int en un rango dado. Si el 
	valor leido no fuera int � �ste fuera menor que menor o mayor que mayor 
	la funci�n volver�a a pedirlo hasta que se proporcionara un valor 
 	correcto.
	
	RECIBE: T�tulo, n�mero maximo, n�mero m�nimo
	DEVUELVE: N�mero entero (int)
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
	
	Se leer� y devolver� un dato int que debe ser mayor o igual que referencia. 
	Si el valor leido no fuera int � �ste fuera menor que referencia la funci�n 
	volver�a a pedirlo hasta que se proporcionara un valor correcto.
	
	RECIBE: T�tulo, n�mero de referencia
	DEVUELVE: N�mero entero (int)
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
	num_entero = LeeEntero("Introduzca un n�mero entero: ");
	cout << endl;
	
	num_entero_enrango = LeeEnteroEnRango("N�mero entero en rango: ", 
	NUM_MIN, NUM_MAX);
	cout << endl;
	
	num_entero_conreferencia = LeeEnteroMayorOIgual ("N�mero entero: ", 
	REFERENCIA);
	cout << endl;
	
	//Salida de datos
	cout << "1) N�mero entero = " << num_entero << endl;
	
	cout << "2) N�mero entero en el rango [" << NUM_MIN << ", " << NUM_MAX
		 << "] = " << num_entero_enrango << endl;
		 
	cout << "3) N�mero entero (>= " << REFERENCIA << ") = " 
		 << num_entero_conreferencia << endl;
	
	return 0;
}
