/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 36 - III: Este programa leerá un número indefinido de NIFs/NIEs 
	(finaliza cuando se introduzca FIN) y verifique su validez.
	
	Para verificar la validez de un NIF, el algoritmo de cálculo del dígito de 
	control es el siguiente:
	- Se divide el número entre 23 y el resto se sustituye por una letra que se 
	  determina por inspección mediante la siguiente tabla:

		RESTO	0	1	2	3	4	5	6	7	8	9	10	11
		LETRA	T	R	W	A	G	M	Y	F	P	D	X	B
		
		RESTO	12	13	14	15	16	17	18	19	20	21	22
		LETRA	N	J	Z	S	Q	V	H	L	C	K	E
 
	  Por ejemplo, si el número del DNI es 12345678, dividido entre 23 da de 
	  resto 14, luego la letra sería la Z: 12345678Z.
	  
	Los NIE's de extranjeros residentes en España tienen una letra (X, Y, Z), 
	7 números y dígito de control. Para el cálculo del dígito de control se 
	sustituye:
		X --> 0
		Y --> 1
		Z --> 2
	Y se aplica el mismo algoritmo que para el NIF.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
#include <cctype>

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
//	VerificaNIF_NIE

	Esta función verificará el NIF o el NIE, introducido a partir de un dato 
	string.
	Para verificar la validez de un NIF, el algoritmo de cálculo del dígito de 
	control es el siguiente:
	- Se divide el número entre 23 y el resto se sustituye por una letra que se 
	  determina por inspección mediante la siguiente tabla:

		RESTO	0	1	2	3	4	5	6	7	8	9	10	11
		LETRA	T	R	W	A	G	M	Y	F	P	D	X	B
		
		RESTO	12	13	14	15	16	17	18	19	20	21	22
		LETRA	N	J	Z	S	Q	V	H	L	C	K	E
 
	  Por ejemplo, si el número del DNI es 12345678, dividido entre 23 da de 
	  resto 14, luego la letra sería la Z: 12345678Z.
	
	Los NIE's de extranjeros residentes en España tienen una letra (X, Y, Z), 
	7 números y dígito de control. Para el cálculo del dígito de control se 
	sustituye:
		X --> 0
		Y --> 1
		Z --> 2
	Y se aplica el mismo algoritmo que para el NIF.
	
	Una vez calculada la letra que le correspondería, la compararemos con la
	letra introducida inicialmente
	
	RECIBE: String
	DEVUELVE: Verdadero o Falso
	PRE: Se debe introducir el NIF o el NIE a través de un string 
		 formado por 9 caracteres
******************************************************************************/
bool VerificaNIF_NIE (string nif_nie){
	bool nif_nie_ok = false;
	
	//Transformamos los caracteres adicionales del NIE en sus respectivos 
	//valores
	if (nif_nie[0] == 'X'){
		nif_nie = '0' + nif_nie.substr(1, 8);
		
	} else if (nif_nie[0] == 'Y') {
		nif_nie = '1' + nif_nie.substr(1, 8);
		
	} else if (nif_nie[0] == 'Z'){
		nif_nie = '2' + nif_nie.substr(1, 8);
		
	}
	
	//Guardamos en otra cadena la supuesta parte numerica y usando la funcion
	//EsDigito comprobamos que esté formada sólo por dígitos
	string parte_numerica_cadena = nif_nie.substr(0, 8);
	int parte_numerica;
	
	bool parte_numerica_ok = false;
	
	if (EsDigito(parte_numerica_cadena)){
		parte_numerica = stoi(parte_numerica_cadena);
		parte_numerica_ok = true;
	}
	
	int resto;
	char letra;
	
	//Esta constante guardará todas las posibles letras del NIF/NIE. La
	//posición de la letra en el string equivale a su resto
	//Ejemplo:		Resto = 0 --> 'T' --> Posición 0 en el string
	//				Resto = 4 --> 'G' --> Posición 4 en el string
	//			Posición:  0...4
	const string LETRAS = "TRWAGMYFPDXBNJZSQVHLCKE";
	
	//Si la parte numérica está bien escrita, pasaremos a realizar los
	//cálculos de la letra
	if (parte_numerica_ok){
		resto = parte_numerica % 23;
		
		letra = LETRAS[resto];
		
		//Si la letra calculada es la misma que la letra introducida,
		//el NIE o NIF es válido
		if (letra == nif_nie[8]){
			nif_nie_ok = true;
		}
	}
	
	return nif_nie_ok;
}

/*****************************************************************************/
int main () {
	//Constantes
	const int LONGITUD_NIF_NIE = 9;
	
	//Variables
	string opcion;
	bool nif_nie_valido;
	
	bool salir = false;
	
	//ENTRADA
	cout << "Introduzca el NIF o el NIE a comprobar. Para salir del programa, "
		 << "escriba 'FIN'" << endl;
	
	while (!salir){
		string nif_nie;
		
		cout << endl;
		cout << "> ";
		cin >> opcion;
		
		int longitud = opcion.length();
		
		//Transformamos la cadena en otra con los caracteres en mayúsculas
		for (int n = 0; n < longitud; n++){
			nif_nie += toupper(opcion[n]);
		}
		
		//CÁLCULOS
		if (nif_nie == "FIN"){
			salir = true;
			
		} else {
			if (longitud == LONGITUD_NIF_NIE){ //Si tiene 9 caracteres
				nif_nie_valido = VerificaNIF_NIE(nif_nie);
				
			} else {
				nif_nie_valido = false;
			}
		}
		
		//SALIDA
		if (!salir){
			if (nif_nie_valido){
				cout << "Es válido" << endl;
			} else {
				cout << "No es válido" << endl;
			}
		}
	}
	
	return 0;
}
