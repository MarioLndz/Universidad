/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 19 - III: Este programa servir� para comprobar el funcionamiento
	de una funci�n que leer� y devolver� un dato double.

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
//	LeeReal

	Se leer� y devolver� un dato double. Si el valor leido no 
	fuera un double, la funci�n volver� a pedirlo hasta que se proporcione un 
	valor correcto.
	
	RECIBE: T�tulo
	DEVUELVE: N�mero real (double)
******************************************************************************/
double LeeReal (string titulo){
	string num_introducido;
	bool no_caracter;
	
	double numero;
	
	do {
		cout << titulo;
		getline (cin, num_introducido);
		
		no_caracter = EsNumero (num_introducido);
		
		//Si la cadena est� formada por d�gitos (no posee ning�n caracter), la
		//transformamos
		if (no_caracter){
			numero = stod(num_introducido);
		}
		
	} while (!no_caracter);

	return numero;
}

/*****************************************************************************/
int main () {
	//Variables
	double num_real;
	
	//Entrada de datos
	num_real = LeeReal("Introduzca un n�mero real: ");
	cout << endl;
		
	//Salida de datos
	cout << "1) N�mero real = " << num_real << endl;
	
	return 0;
}
