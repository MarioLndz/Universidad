/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 27 - VII: Considerar la clase ColeccionPuntos2D que se usará para 
	almacenar y gestionar una colección de datos de tipo Punto2D.
	
	Realizar un programa que lea del teclado un número indeterminado de datos 
	de tipo Punto2D de manera que termine la lectura si el usuario escribe FIN 
	cuando el programa le pide la abscisa de un nuevo punto. Los puntos leídos 
	los almacena en un objeto ColeccionPuntos2D.
	
	A continuación pide los datos necesarios, y crea un objeto Circunferencia,
	y finalmente muestra cuáles de los puntos almacenados en la colección

******************************************************************************/

#include <iostream>	// Inclusión de los recursos de E/S
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
/***************************************************************************/
const double PI = 3.1415926;

/****************************************************************************/
//	FUNCIONES GLOBALES
/****************************************************************************/

/***************************************************************************/
// Función global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

const double PRECISION_SON_IGUALES = 1e-6; // 0.000001

bool SonIguales(double uno, double otro) 
{
	return (fabs(uno-otro) <= PRECISION_SON_IGUALES);
}

/***************************************************************************/
// Elimina los últimos caracteres de "cadena" iguales a "a_borrar"

string EliminaUltimos(string cadena, char a_borrar)
{
   	while (cadena.length()>0 && cadena.back() == a_borrar)
		cadena.pop_back();
        
	return (cadena);
}

/***************************************************************************/
// Elimina los primeros caracteres de "cadena" iguales a "a_borrar"

string EliminaPrimeros (string cadena, char a_borrar)
{	
	// Buscar el primer xarÃ¡cter no espacio
	unsigned int pos = 0;
	while (pos < cadena.length() && cadena.back() == a_borrar) pos++;

	string local; 
	
	// Copiar todos los que quedan
	while (pos < cadena.length()) {
		local.push_back(cadena.at(pos));
		pos++;
	}
		
	return (local);
}

/***************************************************************************/
// Redondea el número "real" a "num_decimales" decimales.
// Recibe: 
//		real, el valor que se va a redondear.
//		num_decimales, el número de decimales que se desea.
// Devuelve: 
//		El número "real" redondeado a la "num_decimales" cifra.
/***************************************************************************/

double Redondea (double real, int num_decimales)
{
   long long potencia_10 = pow(10, num_decimales);
   double nuevo_num = ((int) (round (real * potencia_10)));
   double real_redondeado = nuevo_num / potencia_10;

   return (real_redondeado);
}

/***************************************************************************/
// Convierte el dato double "real" a un string que contiene el valor 
// textual de "real" de acuerdo con el formato indicado según los 
// valores de "num_casillas" y "decimales". 
// 
// Recibe: 
//      "real", el número a transformar.
//		"num_casillas", número total de casillas que tendrá el resultado.
//		"decimales", número de casillas para la parte decimal del resultado.
//		"relleno", el carácter usado para rellenar los huecos. 
//
// Devuelve: el string compuesto.  
// 
// NOTAS: 
// 1) Si el número de casillas solicitado es mayor que el que se necesita, 
//	  se completa el inicio de la parte entera con "relleno".
// 2) Si el número de decimales requerido es cero, NO se muestra el punto. 
//	  Si es mayor que el que se necesita se completa con ceros. 

string ToStringDouble (double real, int num_casillas, 
                       int decimales, char relleno= ' ') {
	string cadena;
	
	double real_redondeado = Redondea (real, decimales);
	
	cadena = to_string(real_redondeado);
	cadena = EliminaUltimos(cadena, '0');
   
	// Si no queremos decimales
	
	if (decimales==0) {
		
		cadena.pop_back();	// Borrar el punto
		
		int long_cadena = (int) cadena.length(); 
	   	
		// Rellenar parte entera
		int digitos_enteros_faltan = num_casillas-long_cadena;
		for (int i=0; i<digitos_enteros_faltan; i++) 
			cadena = relleno + cadena; 	 	
	}
	else { // Queremos decimales 

		int long_cadena = (int) cadena.length(); 
			
		if (long_cadena < num_casillas) {
			
			// Se calcula la longitud de las partes entera y decimal
			// La referencia es el punto (¡¡SIEMPRE ESTÁ!!)
			
			int pos_punto = cadena.find ('.');  
			int long_parte_entera = pos_punto; 
			int long_parte_decimal = long_cadena-pos_punto-1;
			
			// Rellenar parte decimal con ceros
			int digitos_decimales_faltan = decimales - long_parte_decimal;
			for (int i=0; i<digitos_decimales_faltan; i++) 
				cadena += '0';
	
			// Rellenar parte entera con relleno
			int digitos_enteros = num_casillas-decimales-1;
			int digitos_enteros_faltan = digitos_enteros-long_parte_entera;
			
			for (int i=0; i<digitos_enteros_faltan; i++) 
				cadena = relleno + cadena; 	 
		}		
	}
	
	return (cadena);
}

/****************************************************************************/
//	CLASES
/****************************************************************************/
/****************************************************************************/
//	Punto2D
//	Representa un punto en el plano R^2

class Punto2D {
private:
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x;
	double y;

public:
	
	//------------------------------------------------------------------
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está creando.
	
	Punto2D (double abscisaPunto, double ordenadaPunto) {
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}
	
	Punto2D ()
		:	x (0),
			y (0)
	{}
	//------------------------------------------------------------------
	// Método Set para fijar simultaneamente las coordenadas. 
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está modificando.
	
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto) {
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	//------------------------------------------------------------------
	// Métodos Get para leer las coordenadas

	double GetX (void) {
		return (x);
	}
	
	double GetY (void) {
		return (y);
	}

	//------------------------------------------------------------------
	// Calcula si dos puntos son iguales 
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto implícito. 
	// Devuelve: true, si se consideran iguales los dos objetos. 

	bool EsIgual (Punto2D otro) {
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	//------------------------------------------------------------------
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que 
	// se recibe como argumento. 
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la 
	// distancia euclídea.
	// Devuelve: la distancia entre los dos puntos. 

	double DistanciaEuclidea (Punto2D otro) {
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}

	//------------------------------------------------------------------
	// Serializa un dato "Punto2D"
	
	string ToString () {
		return ("[" + ToStringDouble (x, 7, 3, ' ') + ", " + 
		              ToStringDouble (y, 7, 3, ' ') + "]");
	}
	
};

/***********************************************************************/
//	ColecciónPuntos2D
//	Almacenara y gestionara una colección de datos de tipo Punto2D.
class ColeccionPuntos2D{
private:
	static const int TAMANIO=100;
	Punto2D vector_privado[TAMANIO];
	
	// PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados; // Núm.casillas ocupadas

public:
	/***********************************************************************/
	//	Constructores
	
	//------------------------------------------------------------------
	// Constructor sin argumentos
	ColeccionPuntos2D (void)
		:	total_utilizados (0)
	{}
	
	/***********************************************************************/
	//	Metodos de consulta
	
	//------------------------------------------------------------------
	//	Devuelve el punto que se encuentra en la posicion indicada
	//	PRE: 0 <= pos <= total_utilizados
	Punto2D Elemento(int pos){
		return vector_privado[pos];
	}
	
	//------------------------------------------------------------------
	//	Devuelve el total de puntos utilizados
	int TotalUtilizados(){
		return total_utilizados;
	}
	
	/***********************************************************************/
	//	Gestion de la clase
	
	//------------------------------------------------------------------
	// Aniade un nuevo Punto2D al vector
	void Aniade(Punto2D nuevo){
		if(total_utilizados<TAMANIO){
			vector_privado[total_utilizados]=nuevo;
			total_utilizados++;
		}
	}
};

/****************************************************************************/
//	Circunferencia
//	Representa una Circunferencia en el plano utilizando su centro y su radio
class Circunferencia {
private:
	static const double PI;
	Punto2D centro;
	double radio;
	
public:
	/*********************************************************************/
	//	Constructores
	
	//--------------------------------------
	//	Constructor con argumentos
	Circunferencia (Punto2D el_centro, double el_radio)
		:	centro (el_centro),
			radio (el_radio)
	{}
	
	/*********************************************************************/
	//	Metodos SET
	void SetRadio (double nuevo_radio){
		radio = nuevo_radio;
	}
	
	
	/*********************************************************************/
	//	Metodos de consulta
	
	//--------------------------------------
	//	Centro
	Punto2D GetCentro (){
		return centro;
	}
	
	//--------------------------------------
	//	Radio
	double GetRadio (){
		return radio;
	}
	
	/*********************************************************************/
	//	Calculos
	
	//--------------------------------------
	//	Devuelve el valor de la longitud
	double Longitud (){
		return (2*PI*radio);
	}
	
	//--------------------------------------
	//	Devuelve el valor del Area
	double Area (){
		return (PI * radio * radio);
	}
	
	//--------------------------------------
	//	Devuelve el valor del diametro
	double Diametro (){
		return (2 * radio);
	}
	
	//--------------------------------------
	//	Comprobara si un punto se encuentra contenido dentro de la 
	//	circunferencia. Esto ocurrira cuando:
	//		(x + a)^2 + (y - b)^2 = radio;
	//	Siendo (a, b) el centro de la circunferencia y (x, y) el punto a 
	//	comprobar
	bool ContieneA (Punto2D p){		
		double x_0 = (p.GetX() + centro.GetX());
		double y_0 = (p.GetY() - centro.GetY());
		
		return ((x_0 * x_0) + (y_0 * y_0) <= (radio*radio));
		
	}
	
};
const double Circunferencia::PI = 6 * asin(0.5);


/****************************************************************************/
/****************************************************************************/

/*****************************************************************************
//	EsNumero

	Se comprobará si el string introducido está formado por un número real
	
	RECIBE: String a comprobar
	DEVUELVE: Verdadero o Falso
*****************************************************************************/
bool EsNumero (string cadena){
	bool es_numero = true;
	
	cadena = EliminaPrimeros (cadena, ' ');
	cadena = EliminaUltimos (cadena, ' ');
	
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

/****************************************************************************/
/****************************************************************************/
int main () {
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	//------------------------------------------
	//	ENTRADA
	const string TERMINADOR = "FIN";
	
	cout << "Introduzca todos los puntos que desee. Para dejar de añadir "
		 << "puntos inserte " << TERMINADOR << endl;
	
	ColeccionPuntos2D coleccion;
	
	int i = 1;
	string cadena;
	cout << "- Punto " << i << ": " << endl;
	
	do {
		cout << "\t" << "x = ";
		cin >> cadena;
		
		cadena = StrToUpper(cadena);
	} while (cadena != TERMINADOR && !EsNumero(cadena));
	
	while (cadena != TERMINADOR){
		
		//Leemos el valor de la y
		double y;
		
		cout << "\t" << "y = ";
		cin >> y;
		
		coleccion.Aniade(Punto2D(stod(cadena), y));
		
		cout << "Punto " << coleccion.Elemento(i-1).ToString() << " añadido" 
			 << endl << endl;
		
		//Leemos un nuevo punto
		i++;
		cout << "- Punto " << i << ": " << endl;
		
		do {
			cout << "\t" << "x = ";
			cin >> cadena;
			cadena = StrToUpper(cadena);
		} while (cadena != TERMINADOR && !EsNumero(cadena));
		
	}
	
	//Circunferencia
	double x;
	double y;
	cout << endl;
	cout << "Defina la circunferencia:" << endl;
	
	//Centro
	cout << "- Centro:" << endl;
	
	cout << "\t" << "x = ";
	cin >> x; 

	cout << "\t" << "y = ";
	cin >> y; 
	cout << endl;
	
	//Radio
	double radio;
	do{
		cout << "Radio de la circunferencia: ";
		cin >> radio;
		
	} while (radio <= 0);
	
	Circunferencia cir(Punto2D (x, y), radio);
	
	//Se comprobara si los puntos añadidos a la coleccion inicial se encuentran
	//dentro de la circunferencia. Los que así sean, se añadiran a una nueva
	//coleccion
	ColeccionPuntos2D contenidos_cir;
	
	for (int n = 0; n < coleccion.TotalUtilizados(); n++){
		if (cir.ContieneA (coleccion.Elemento(n))){
			contenidos_cir.Aniade(coleccion.Elemento(n));
		}
	}
	
	//Salida
	cout << "Dentro de la circunferencia centrada en " 
		 << cir.GetCentro().ToString(); 
	cout << " de radio = " << setw(4) << setprecision(2) << cir.GetRadio();				
	cout << endl;
	cout << "se encuentran los siguientes puntos:" << endl;
	cout << endl;
	for (int n = 0; n < contenidos_cir.TotalUtilizados(); n++){
		cout << contenidos_cir.Elemento(n).ToString() << endl;
	}
	
	
	return 0;
}
