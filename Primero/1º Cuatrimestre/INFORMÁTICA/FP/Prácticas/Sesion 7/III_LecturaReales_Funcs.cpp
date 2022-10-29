/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 19 - III: Este programa servirá para comprobar el funcionamiento
	de una función que leerá y devolverá un dato double.

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
//	LeeReal

	Se leerá y devolverá un dato double. Si el valor leido no 
	fuera un double, la función volverá a pedirlo hasta que se proporcione un 
	valor correcto.
	
	RECIBE: Título
	DEVUELVE: Número real (double)
******************************************************************************/
double LeeReal (string titulo){
	string num_introducido;
	bool no_caracter;
	
	double numero;
	
	do {
		cout << titulo;
		getline (cin, num_introducido);
		
		no_caracter = EsNumero (num_introducido);
		
		//Si la cadena está formada por dígitos (no posee ningún caracter), la
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
	num_real = LeeReal("Introduzca un número real: ");
	cout << endl;
		
	//Salida de datos
	cout << "1) Número real = " << num_real << endl;
	
	return 0;
}
