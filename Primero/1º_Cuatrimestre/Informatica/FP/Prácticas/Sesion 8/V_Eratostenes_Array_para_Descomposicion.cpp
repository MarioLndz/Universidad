/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 15 - V: Se ler� un n�mero indeterminado de enteros positivos 
	(finalizar� cuando se introduzca un cero) y se expresar�n cada uno de ellos
	en base al producto de sus factores primos. Se expresar� el resultado como 
	el producto de potencias.
	
	Ejemplo:
		360 = 2^3 * 3^2 * 5
		121 = 11^2
		11 = 11
	
	Para la soluci�n deber� considerar �nicamente los factores primos. Para 
	ello deber� calcular (y guardar en un array) los n�meros primos antes de 
	leer ning�n n�mero. Usaremos la Criba de Erat�stenes
*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>

using namespace std;

/*****************************************************************************
//	DATOS STRUCT
******************************************************************************/
struct Pareja{
	int primo;
	int potencia;
};

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
//	LeeEnteroPositivo

	Se leer� y devolver� un dato entero positivo. Si el valor leido no 
	fuera un entero positivo, la funci�n volver� a pedirlo hasta que se 
	proporcione un valor correcto.
	
	RECIBE: T�tulo
	DEVUELVE: N�mero entero (int)
******************************************************************************/
int LeeEnteroPositivo (string titulo){
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
		
	} while (!no_caracter || (numero - (int)numero != 0) || (numero < 0));

	return numero;
}

/*****************************************************************************/
int main () {
	/***************************************************************/
	//		CRIBA DE ERAT�STENES	
	/***************************************************************/
	
	//	MAL HECHA - MIRAR CORRECI�N EN DRIVE
	
	/* Establecemos maximo de componentes de un vector */
    const int LONGITUD_MAXIMA = 5000;
    bool es_primo[LONGITUD_MAXIMA];
    
    //Inicializamos el 0 y el 1 como No Primos
    es_primo[0] = es_primo[1] = false;
    
    //De primeras consideramos todos los valores como primos
	for (int i = 2; i < LONGITUD_MAXIMA; i++){
        es_primo[i] = true;
	}
    
    //Comprobamos los n�mero que No sean primos y los marcamos como False
	for (int i = 2; i*i < LONGITUD_MAXIMA; i++){
        for (int j = i+1; j < LONGITUD_MAXIMA; j++){
            //Tachamos todos los m�ltiplos del n�mero que estamos comprobando
            //Ejemplo: 2 es primo --> Consideramos como No Primo todos los 2n
            //Para comprobar si un n�mero es un m�ltiplo, comprobamos que su 
            //resto sea 0
			if (j % i == 0){
                es_primo[j] = false;
			}
		}
	}
    //Al final de esto nos quedar�n sin "tachar" todos los n�meros que no sean
    //m�ltiplos de otro, es decir, los n�meros primos
    
    int primos[LONGITUD_MAXIMA];
    int num_primos = 0;
    
    //Pasamos todos los primos a un vector espec�fico para ellos
	for (int i = 0; i < LONGITUD_MAXIMA; i++){
        if (es_primo[i]){
            primos[num_primos] = i;
            num_primos++;
		}
	}
	
	/***************************************************************/
	//		ENTRADA
	/***************************************************************/
	//Variables
	int datos[LONGITUD_MAXIMA];	//Vector donde se guardar�n los datos
	int num_datos = 0;
	
	//Explicamos como usar el programa
	cout << "Introduzca los n�meros enteros positivos a descomponer. "
		 << "Para parar introduce el 0" << endl;
	
	//Pedimos los datos
	int dato;
	string titulo;
	
	titulo = "\tDato " + to_string(num_datos + 1) + ": ";
	dato = LeeEnteroPositivo(titulo);
	while (num_datos < LONGITUD_MAXIMA && dato != 0){
		cout << endl;
		datos[num_datos] = dato;
		
		num_datos++;
		
		titulo = "\tDato " + to_string(num_datos + 1) + ": ";
		dato = LeeEnteroPositivo(titulo);
	}
	
	//Quitamos del vector de datos los valores repetidos (usaremos para ello el
	//algoritmo C del ejercicio 13 - V)
	int posicion_lectura = 0;
	int posicion_escritura = 0;
	bool repetido;
	
	while (posicion_lectura < num_datos){
		repetido = false;
		
		//Recorremos el vector inicial y comprobamos si un valor se repite
		int i = 0;
		while (i < posicion_lectura && !repetido){
			if (datos[posicion_lectura] == datos[i]){
				repetido = true;
			}
			i++;
		}
		
		//Si no es un valor repetido guardamos el dato que hemos leido
		//en la posicion de escritura y subimos una posicion
		if (!repetido){
			datos[posicion_escritura] = datos[posicion_lectura];
			posicion_escritura++;
		}
		posicion_lectura++;
	}
	
	num_datos = posicion_escritura;	//Actualizamos el n�mero de datos
	cout << endl;
	
	
	/***************************************************************
	//		C�LCULOS
	***************************************************************/

	const int CASILLAS_DESCOMPOSICION = 50;
	
	//Vector donde se guardan los resultados en forma de string
	string resultados[LONGITUD_MAXIMA];
	
	for (int i = 0; i < num_datos; i++){
		//Inicializamos el vector descomposiciones
		Pareja descomposiciones[CASILLAS_DESCOMPOSICION] = {{0, 0}};	
		int num_descomposiciones = 0;
		num_descomposiciones = 0;
		
		//Copiamos el valor del dato con el que vamos a trabajar
		int valor = datos[i];
		
		//Inicializamos posiciones
		int pos_primos = 0;
		int pos_descomposicion = 0;
		
		//Consideramos el 1 como excepci�n
		if (valor == 1){
			descomposiciones[pos_descomposicion].primo = 1;
			descomposiciones[pos_descomposicion].potencia++;
		}
		
		//C�lculo descomposiciones
		while (primos[pos_primos] <= valor && valor != 1){
			//Comprobamos si el valor es un m�ltiplo del primo actual
			if (valor % primos[pos_primos] == 0){
				//Guardamos la base
				descomposiciones[pos_descomposicion].primo = primos[pos_primos];
				//Sumamos +1 al exponente
				descomposiciones[pos_descomposicion].potencia++;
				
				//Calculamos el nuevo valor a comprobar
				valor /= primos[pos_primos];
			} else{
				//Si no fuera un m�ltiplo, pasamos al siguiente primo
				pos_primos++;
				
				//Si no se ha llegado a cambiar la base, no cambiaremos de
				//componente en el vector descomposiciones
				if (descomposiciones[pos_descomposicion].primo != 0){
					pos_descomposicion++;	
				}
			}
		}	//Fin c�lculo de descomposiciones
		
		//Actualizamos el n�mero de descomposiciones hechas
		num_descomposiciones = pos_descomposicion + 1;
		
		//Formamos el string del resultado
		resultados[i] = to_string(datos[i]) + " = ";
		
		for (int n = 0; n < num_descomposiciones; n++){
			//A�adimos el signo del producto solo si no es la primera
			//descomposici�n
			if (n != 0){
				resultados[i] += " * ";
			}
			//A�adimos la base
			resultados[i] += to_string(descomposiciones[n].primo);
			
			//A�adimos la potencia solo si no es potencia de 1
			if (descomposiciones[n].potencia != 1){
				resultados[i] += "^" + to_string(descomposiciones[n].potencia);
			}
		}
	}
	
	/***************************************************************/
	//		SALIDA
	/***************************************************************/
	cout << "RESULTADOS" << endl;
	
	//Mostramos los resultados calculados, que ser�n tantos como datos hayamos
	//introducido
	for (int n = 0; n < num_datos; n++){
		cout << "\t" << resultados[n] << endl;
	}
	
	return 0;
}
