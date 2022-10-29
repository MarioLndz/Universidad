/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 13 - V: Este programa leer� un n�mero indeterminado de n�meros 
	positivos (la lectura terminar� cuando se introduce un negativo) aunque 
	nunca leer� m�s de 50. Conforme los va leyendo, los ir� almacenando en un 
	vector, datos.
	
	A continuaci�n elimina del vector los valores repetidos, dejando una sola 
	copia. No se dejar�n huecos en el vector y todos los n�meros quedan 
	agrupados en las posiciones m�s bajas del vector.
	
	Se implementar�n 3 versiones del borrado:
		a) Usar un vector auxiliar sin_repetidos en el que almacenamos una 
		   �nica aparici�n de cada componente:
		   
		   - Copiar la primera componente de "datos" en "sin_repetidos"
		   - Desde la segunda casilla de "datos", hasta la �ltima:
		   		Si el valor de la casilla NO est� en "sin_repetidos",
				a�adirla al vector "sin_repetidos"
			- Sustituir todas las componentes de "datos" por las de 
			  "sin_repetidos"
	b) El problema del algoritmo anterior es que usa otro vector, lo que 
	   podr�a suponer una carga importante de memoria si trabaj�semos con 
	   vectores grandes. Por lo tanto, vamos a resolver el problema sin usar 
	   vectores auxiliares. 
	   
	   Si una componente est� repetida, se borrar� del vector. Para borrar la 
	   componente de la casilla p:
	   - Desde la casilla "p" hasta la pen�ltima: Copiar en la casilla "p" 
	   	 el contenido de la "p"+1.
	
	c) El anterior algoritmo nos obliga a desplazar muchas componentes. 
	   Implementar el algoritmo que usa dos apuntadores, posicion_lectura y 
	   posicion_escritura, que nos van indicando, en cada momento, la 
	   componente que se est� leyendo y el sitio d�nde tiene que escribirse.
	   
	   Por ejemplo, supongamos que en un determinado momento la variable
	   posicion_lectura vale 6 y posicion_escritura 3. Si la componente en
	   la posici�n 6 est� repetida, simplemente avanzaremos posicion_lectura. 
	   Por el contrario, no estuviese repetida, la colocaremos en la 
	   posici�n 3 y avanzaremos una posici�n ambas variables.

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

/****************************************************************************
//	LeeNumero

	Esta funci�n leer� un dato hasta que se introduzca un n�mero
	
	RECIBE: T�tulo
	DEVUELVE: Dato double le�do
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

/*****************************************************************************/
int main () {
	double numero;
	string titulo;
	
	const int TOPE = 50;
	double datos[TOPE];
	
	int num_componentes = 0;
	
	//ENTRADA
	titulo = "Casilla " + to_string(num_componentes) + ": ";
	numero = LeeNumero(titulo);
	while (num_componentes < TOPE && numero >= 0) {
		datos[num_componentes] = numero;
		
		num_componentes++;	

		titulo = "Casilla " + to_string(num_componentes) + ": ";
		numero = LeeNumero(titulo);
	}
	
	
	//C�LCULOS
	
	/**************************/
	//	Algoritmo A
	/**************************/
	
	int num_componentes_a = num_componentes;
	double sin_repetidos[TOPE];
	
	//El primer dato no puede estar repetido
	sin_repetidos[0] = datos [0];
	
	bool repetido;
	int num_comp_sin_repetidos = 1;
	
	for (int n = 1; n < num_componentes_a; n++){
		repetido = false;
		
		//Recorremos el vector inicial y lo comparamos con el vector sin
		//repetidos y comprobamos si un valor se repite
		for (int i = 0; i < num_comp_sin_repetidos && !repetido; i++){
			if (datos[n] == sin_repetidos[i]){
				repetido = true;
			}
		}
		
		//Si no se ha encontrado ning�n valor repetido, se a�ade al vector
		//sin_repetidos. Adem�s actualizamos el n�mero de componentes que
		//forman dicho vector.
		if (!repetido){
			sin_repetidos[num_comp_sin_repetidos] = datos[n];
			num_comp_sin_repetidos++;
		}
	}
	
	/**************************/
	//	Algoritmo B
	/**************************/
	
	int num_componentes_b = num_componentes;
	
	double datos_b[TOPE];
	
	//Como en este ejercicio estamos comparando tres formas de trabajar,
	//no queremos modificar el vector original por lo que trabajaremos en otro
	//vector equivalente pero no ser�a necesario para usar este m�todo
	for (int n = 0; n < num_componentes; n++){
		datos_b[n] = datos[n];
	}
	
	int posicion = 0;
	while (posicion < num_componentes_b){
		repetido = false;
		
		//Recorremos el vector inicial y comprobamos si un valor se repite
		int i = 0;
		while (i < posicion && !repetido){
			//Si se encuentra un valor repetido
			if (datos_b[posicion] == datos_b[i]){
				repetido = true;
				
				//"Borramos" el car�cter que est� repetido. Para ello, haremos
				//un borrado f�sico, es decir, todas las componentes que hay a 
				//la derecha se desplazan una posici�n a la izquierda
				for (int t = posicion; t < num_componentes_b; t++){
					datos_b[t] = datos_b[t+1];
				}
				num_componentes_b--;	//Actualizamos el numero de componentes
			}
			i++;
		}
		
		//Si no se ha encontrado un valor repetido, pasamos a la siguiente
		//componente
		if (!repetido){
			posicion++;
		}
	}
	
	
	/**************************/
	//	Algoritmo C
	/**************************/
	
	double datos_c[TOPE];
	
	//Como en este ejercicio estamos comparando tres formas de trabajar,
	//no queremos modificar el vector original por lo que trabajaremos en otro
	//vector equivalente pero no ser�a necesario para usar este m�todo
	for (int n = 0; n < num_componentes; n++){
		datos_c[n] = datos[n];
	}
	
	int posicion_lectura = 0;
	int posicion_escritura = 0;
	int num_componentes_c = num_componentes;
	
	while (posicion_lectura < num_componentes_c){
		repetido = false;
		
		//Recorremos el vector inicial y comprobamos si un valor se repite
		int i = 0;
		while (i < posicion_escritura && !repetido){
			if (datos_c[posicion_lectura] == datos_c[i]){
				repetido = true;
			}
			i++;
		}
		
		//Si no es un valor repetido guardamos el dato que hemos leido
		//en la posicion de escritura y subimos una posicion
		if (!repetido){
			datos_c[posicion_escritura] = datos_c[posicion_lectura];
			posicion_escritura++;
		}
		posicion_lectura++;
	}
	
	num_componentes_c = posicion_escritura;
	
	//SALIDA DE DATOS
	
	//Vector inicial
	cout << endl << endl;
	cout << "VECTOR INICIAL" << endl;
	for (int i = 0; i < num_componentes; i++){
		cout  << "\t" << datos[i];
	}
	
	//Algoritmo A
	cout << endl << endl;
	cout << "-------------------- ALGORITMO A ------------------------" << endl;
	cout << endl;
	
	//Mostramos los vectores
	cout << "VECTOR REDUCIDO: " << endl;
	for (int n = 0; n < num_comp_sin_repetidos; n++){
		cout  << "\t" << sin_repetidos[n];
	}
	
	//Algoritmo B
	cout << endl << endl;
	cout << "-------------------- ALGORITMO B ------------------------" << endl;
	cout << endl;
	
	//Mostramos el nuevo vector
	cout << "VECTOR REDUCIDO: " << endl;
	for (int i = 0; i < num_componentes_b; i++){
		cout  << "\t" << datos_b[i];
	}
	
	//Algoritmo C
	cout << endl << endl;
	cout << "-------------------- ALGORITMO C ------------------------" << endl;
	cout << endl;
	
	//Mostramos el nuevo vector
	cout << "VECTOR REDUCIDO: " << endl;
	for (int i = 0; i < num_componentes_c; i++){
		cout  << "\t" << datos_c[i];
	}
	
	return 0;
}
