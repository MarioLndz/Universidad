/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 3 - V: Declarararemos dos array de datos int con TOPE casillas. 
	Rellenar cada array de la siguiente manera: pediremos que se introduzca por 
	teclado una serie indeterminada de n�meros enteros (terminar� cuando se 
	introduce la palabra FIN).
	
	1) El programa mostrar� el valor medio de los valores introducidos.
	2) Despu�s, indicar� si los dos array contienen los mismos valores y en el 
	   mismo orden.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>
#include <iomanip>

using namespace std;

/*****************************************************************************
//	FUNCIONES
******************************************************************************/

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
	cadena = EliminaUltimosSeparadores (cadena);
	
	int longitud = cadena.length();
	
	//Primero comprobaremos que la cadena no est� vac�a o que solo est� formada
	//por la coma decimal o un signo
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

/****************************************************************************
//	EsEntero
	
	Esta funci�n comprobar� si un string introducido representa a un
	n�mero entero
	
	RECIBE: string
	DEVUELVE: Verdadero o Falso
****************************************************************************/
bool EsEntero (string cadena){
	bool es_entero = true;
	double num_aux;
	
	if (EsNumero(cadena)){
		num_aux = stod(cadena);
			
		if (num_aux - (int)num_aux != 0){
			es_entero = false;
		}
	} else {
		es_entero = false;
	}
	
	return es_entero;
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

/****************************************************************************
//	LeeNumEntero

	Esta funci�n leer� un dato hasta que se introduzca un n�mero entero o 
	el terminador
	
	RECIBE: T�tulo, Terminador
	DEVUELVE: Dato en forma de string
*****************************************************************************/
string LeeNumEntero (string titulo, string terminador){
	string dato;
			
	do {
		cout << titulo;
		getline (cin, dato);
		
		dato = StrToUpper(dato);

	} while (!EsEntero(dato) && dato != terminador);
	
	return dato;
}


/*****************************************************************************/
int main () {
	//Constantes
	const int TOPE = 100;
	const string TERMINADOR = "FIN";
	
	//Variables
	int vector1[TOPE];
	int vector2[TOPE];

	string dato;
	
	int comp_usados_vector1 = 0;	//Componentes usados en el vector 1
	int comp_usados_vector2 = 0;	//Componentes usados en el vector 2
		
	//Llenamos el vector 1
	cout << "VECTOR 1: " << endl;
	do {
		//Leemos un valor y nos aseguramos que sea un n�mero entero o que el
		//usuario escriba 'FIN'
		string titulo = "\tCasilla " + to_string(comp_usados_vector1) + ": ";
		
		dato = LeeNumEntero(titulo, TERMINADOR);
		
		//Si no es el terminador, a�adimos lo introducido al vector
		if (dato != TERMINADOR){
			vector1[comp_usados_vector1] = stoi(dato);			
			comp_usados_vector1++;
		}
	
	} while (comp_usados_vector1 < TOPE && (dato != TERMINADOR));
	
	cout << endl;

	//Llenamos el vector 2
	cout << "VECTOR 2: " << endl;
	do {
		//Leemos un valor y nos aseguramos que sea un n�mero entero o que el
		//usuario escriba 'FIN'
		string titulo = "\tCasilla " + to_string(comp_usados_vector2) + ": ";
		
		dato = LeeNumEntero(titulo, TERMINADOR);
		
		//Si no es el terminador, a�adimos lo introducido al vector
		if (dato != TERMINADOR){
			vector2[comp_usados_vector2] = stoi(dato);			
			comp_usados_vector2++;
		}

	} while (comp_usados_vector2 < TOPE && (dato != TERMINADOR));
	
	//C�LCULOS
	
	//Media Vector 1
	double media_v1 = 0;
	
	if (comp_usados_vector1 != 0){
		for (int n = 0; n < comp_usados_vector1; n++){
			media_v1 += vector1[n];	
		}
		media_v1 /= comp_usados_vector1;
	}
	
	
	//Media Vector 2
	double media_v2 = 0;
	
	if (comp_usados_vector2 != 0){
		for (int n = 0; n < comp_usados_vector2; n++){
			media_v2 += vector2[n];
		}
		media_v2 /= comp_usados_vector2;
	}
	
	//Mismos valores y mismo orden??
	bool vectores_iguales = true;
	
	//Si no tuvieran la misma cantidad de componentes, no pueden ser iguales
	if (comp_usados_vector1 == comp_usados_vector2){
		//Comprobamos cada componente de los vectores
		int t = 0;
		while (t < comp_usados_vector1 && vectores_iguales){
			if (vector1[t] != vector2[t]){
				vectores_iguales = false;
				cout << "Diferentes" << endl;
			}
			
			t++;
		}
	} else {
		vectores_iguales = false;
	}
	
	//SALIDA DE DATOS
	const int margen = 4;
	
	//Vector 1: Componentes, n�mero de componentes y media
	cout << "--------------------------------------------------------" << endl;
	cout << "Vector 1: ";
	cout << endl << endl;
	
	for (int i = 0; i < comp_usados_vector1; i++){
		cout << setw(margen - 1) << "";
		cout << vector1[i]; 
		cout << setw(margen) << "|";
	}
	cout << endl << endl;
	
	cout << "- Se han introducido " << comp_usados_vector1 << " datos" << endl;
	cout << "- Media = " << media_v1 << endl;
	cout << "--------------------------------------------------------" << endl;
	
	//Vector 2: Componentes, n�mero de componentes y media
	cout << "--------------------------------------------------------" << endl;
	cout << "Vector 2:";
	cout << endl << endl;
	
	for (int i = 0; i < comp_usados_vector2; i++){
		cout << setw(margen - 1) << "";
		cout << vector2[i]; 
		cout << setw(margen) << "|";
	}
	cout << endl << endl;
	
	cout << "- Se han introducido " << comp_usados_vector2 << " datos" << endl;
	cout << "- Media = " << media_v2 << endl;
	cout << "--------------------------------------------------------" << endl;
	
	//Indicamos si los dos vectores tienen los mismo valores y en la misma
	//posici�n, es decir, si son iguales
	if (vectores_iguales){
		cout << "Los dos vectores son iguales, tienen los mismos valores en "
			 << "las mismas posiciones" << endl;
	} else {
		cout << "Los dos vectores son diferentes, no tienen los mismos valores"
			 << " en las mismas posiciones" << endl;
	}	
	return 0;
}
