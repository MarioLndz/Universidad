/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 28 - V: Se dispone de un robot que se mueve en una l�nea, 
	utilizando pasos de longitud fija. Inicialmente, el robot se ubica en la 
	posici�n pos, siendo pos un valor entero positivo 1 <= pos <= 100. Luego, 
	el robot ejecuta una serie de �rdenes, indicadas mediante un array ord de 
	tipo char, con longitud lon. Cada orden es una letra I � D, indicando si 
	el robot se mueve a la izquierda (decrementando la posici�n actual pos en 
	1 unidad) o a la derecha (incrementando la posici�n actual pos en 1 
	unidad). Las posiciones v�lidas del robot cumplen 1 <= pos <= 100. Se dice 
	que una serie de �rdenes es correcta si el robot nunca se sale de las 
	posiciones v�lidas.
	
	Se implementar� un programa para que, dada una posici�n inicial pos y una 
	lista de �rdenes ord de longitud lon, haga lo siguiente:
	
		a) Si la serie de �rdenes es correcta, muestre cu�ntas veces se visit� 
		   cada posici�n.
		b) Si la serie de �rdenes NO es correcta, el programa terminar� 
		   indicando cu�ntas �rdenes se pudieron ejecutar
*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>

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

/*****************************************************************************
//	LeeOrden

	Se leer� y devolver� una orden: 'I' o 'D'. Si el valor leido no 
	fuera una de las �rdendes v�lidas, la funci�n volver� a pedirla hasta que 
	se proporcione un car�cter correcto.
	
	RECIBE: T�tulo
	DEVUELVE: Car�cter 'D' o 'I'
******************************************************************************/
char LeeOrden (string titulo){
	string cadena;
	char caracter;
	
	do{
		cout << titulo;	
		getline (cin, cadena);
		
		cadena = EliminaPrimerosSeparadores(cadena);
		cadena = EliminaUltimosSeparadores(cadena);
		
		if (cadena.length() == 1){
			caracter = cadena.at(0);
			caracter = toupper(caracter);
		}
	} while (caracter != 'D' && caracter != 'I');
	
	return caracter;
}

/*****************************************************************************/
int main () {
	//Constantes
	const int CASILLAS = 99;
	const int CASILLA_MIN = 1;
	const int CASILLA_MAX = 100;
	
	//Este vector representar� la l�nea por donde se mover� el robot. La
	//casilla por la que pasa adem�s registr� cuantas veces pasa por esa 
	//casilla
	int frecuencia_visitas[CASILLAS] = {0};
	
	//Vector de �rdenes
	const int MAX_ORDENES = 200;
	char ordenes[MAX_ORDENES];
	
	int num_ordenes;	//Numero m�ximo de �rdenes
	
	/*****************************************************************/
	//		ENTRADA
	/*****************************************************************/
	
	//Leemos la posici�n inicial. (1 <= posicion inicial <= 100)
	int posicion_robot;

	do {
		posicion_robot = LeeEntero("Posici�n inicial: ");
	} while (posicion_robot < CASILLA_MIN || posicion_robot > CASILLA_MAX);
	
	//El array empieza desde la casilla 0, pero nuestra "l�nea" empieza desde
	//la casilla 1, por lo que hay una diferencia de 1 casilla entre la
	//posici�n del robot real y la posici�n en el array
	int posicion_robot_array = posicion_robot - 1;
	frecuencia_visitas[posicion_robot_array]++;
	
	//Leemos el n�mero de �rdenes y filtramos (debe ser mayor que 0)
	do {
		num_ordenes = LeeEntero("N�mero de �rdenes: ");
	} while (num_ordenes <= 0);
	
	//Leemos las �rdenes
	cout << "�rdenes:" << endl;
	for (int i = 0; i < num_ordenes; i++){
		string titulo = "\tOrden " + to_string(i+1) + " (I/D): ";
		ordenes[i] = LeeOrden(titulo);
	}	
	
	/*****************************************************************/
	//		C�LCULOS
	/*****************************************************************/
	
	string movimiento = to_string(posicion_robot);
	
	bool orden_ok = true;
	int num_ord_ejecutadas = 0;
	
	while (num_ord_ejecutadas < num_ordenes && orden_ok){
		//Comprobamos que orden se va a ejecutar
		if (ordenes[num_ord_ejecutadas] == 'D'){
			//Movemos al robot en el array una posici�n a la derecha
			posicion_robot_array++;
		} else{
			//Movemos al robot en el array una posici�n a la derecha
			posicion_robot_array--;
		}
		
		//Sumamos +1 a la casilla a donde haya ido el robot en frecuencia
		frecuencia_visitas[posicion_robot_array]++;
		
		//Actualizamos la posici�n del robot real
		posicion_robot = posicion_robot_array + 1;
		
		//Para que la orden sea correcta la posici�n del robot debe estar entre
		//1 y 100
		orden_ok = posicion_robot >= CASILLA_MIN 
				   && posicion_robot <= CASILLA_MAX;
		
		//Si la orden era correcta, guardamos el movimiento en un string y 
		//sumamos 1 al n�mero de ordenes ejecutadas
		if (orden_ok){
			movimiento += " --> " + to_string(posicion_robot);
			
			num_ord_ejecutadas++;
		}
		
	}	//Fin del movimiento del robot
	
	//Formamos la cadena que representar� las frecuencias
	string frecuencias;
	
	for (int n = 0; n < CASILLAS; n++){
		//Si se ha visitado la casilla (>0)
		if (frecuencia_visitas[n] != 0){
			frecuencias += "(" + to_string(n+1) + ", " + 
						   to_string(frecuencia_visitas[n]) + "), ";
		}
	}
	
	//Eliminamos los �ltimos 2 caracteres de la cadena ', '
	frecuencias.pop_back();
	frecuencias.pop_back();
		
	/*****************************************************************/
	//		SALIDA
	/*****************************************************************/
	cout << endl;
	cout << "Posiciones (v�lidas) visitadas:" << endl;
	cout << "\t" << movimiento << endl << endl;
	
	if (orden_ok){
		cout << "Serie de �rdenes: Correcta" << endl;
		cout << "Frecuencia de visitas por posici�n:" << endl;
		cout << "\t" << frecuencias << "." << endl;
		
	} else {
		cout << "Serie de �rdenes: Incorrecta" << endl;
		cout << "Se ejecutaron " << num_ord_ejecutadas << " �rdenes" << endl;
	}
	
	return 0;
}
