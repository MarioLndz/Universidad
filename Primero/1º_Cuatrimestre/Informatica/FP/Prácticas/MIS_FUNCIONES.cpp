#include <iostream>   // Inclusión de los recursos de E/S
#include <string>

using namespace std;

/*****************************************************************************
// 	EliminaPrimerosSeparadores
	
	Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
	separadores de "cadena". Los caracteres separadores son el espacio en 
	blanco, el tabulador y el salto de lÃ­nea. 
	Usaremos la función isspace() para simplificar el cálculo. 
 
	RECIBE:  cadena, string sobre la que se va a trabajar.
	DEVUELVE: el resultado de eliminar los primeros separadores de "cadena".
*****************************************************************************/
string EliminaPrimerosSeparadores (string cadena)
{	
	// Buscar el primer carácter no espacio
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
	
	Devuelve una NUEVA cadena, resultante de eliminar los Ãºltimos caracteres 
	separadores de "cadena". Los caracteres separadores son el espacio en 
	blanco, el tabulador y el salto de línea. 
	Usaremos la función isspace() para simplificar el cálculo. 
	 
	Recibe: cadena, string sobre la que se va a trabajar.
	Devuelve: el resultado de eliminar los últimos separadores de "cadena".
*****************************************************************************/
string EliminaUltimosSeparadores (string cadena)
{
   	while (cadena.length()>0 && isspace(cadena.back()))
		cadena.pop_back();
        
	return (cadena);
}

/*****************************************************************************
//	EsNumero

	Se comprobará si el string introducido está formado por un número real
	
	RECIBE: String a comprobar
	DEVUELVE: Verdadero o Falso
*****************************************************************************/
bool EsNumero (string cadena){
	bool es_numero = true;
	
	cadena = EliminaPrimerosSeparadores (cadena);
	cadena = EliminaUltimosSeparadores  (cadena);
	
	int longitud = cadena.length();
	
	//Primero comprobaremos que la cadena no esté vacía o que solo esté formada
	//por la coma decimal
	if (cadena == "." || cadena == "" || cadena == "-" || cadena == "+"){
		es_numero = false;
	} else {
		int n = 0;
		int coma_decimal = 0;
		
		//Comprueba que toda la cadena está formada por dígitos (con decimales)
		//si la cadena empieza con un signo, pasará al siguiente caracter
		if (cadena.at(0) == '-' || cadena.at(0) == '+'){
			n++;
		}
		
		while (n < longitud && es_numero) {
			//Comprobamos cómo está formada la cadena. Si encontramos una coma
			//decimal, la registramos en un contador. Si no, comprobamos que
			//el carácter es un dígito. Si no fuera un dígito o si hubiera
			//más de una coma decimal devolveremos FALSE
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

/****************************************************************************
//	StrToUpper

	Esta función transforma todos los caracteres que forman una cadena a 
	mayúscula. Los números y los símbolos no se verán modificados.
	
	RECIBE: Cadena
	DEVUELVE: Cadena en mayúsculas
*****************************************************************************/
string StrToUpper (string cadena){
	string cadena_mayus;
	int longitud = cadena.length();
	
	//Transformamos la cadena en otra con los caracteres en mayúsculas
	for (int n = 0; n < longitud; n++){
		cadena_mayus += toupper(cadena.at(n));
	}
	
	return cadena_mayus;
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

/****************************************************************************
//	LeeNumero

	Esta función leerá un dato hasta que se introduzca un número
	
	RECIBE: Título
	DEVUELVE: Dato double leído
*****************************************************************************/
double LeeNumero (string titulo){
	string dato;
	double valor;
	
	do {
		cout << titulo;
		getline (cin, dato);
		
	} while (!EsNumero(dato));
	
	valor = stod(dato);
	
	return valor;
}
