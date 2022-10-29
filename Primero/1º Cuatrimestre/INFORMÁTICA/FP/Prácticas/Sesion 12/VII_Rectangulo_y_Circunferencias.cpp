/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 24 - VII: Reescribir la solución del ejercicio 6 de la Relación 
	de Problemas VI con las nuevas definiciones de las clases Punto2D, 
	Rectangulo y Circunferencia desarrolladas en los ejercicios 22 y 23 de esta 
	misma Relación de Problemas

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

/****************************************************************************/
//	Rectangulo
//	Representa un Rectangulo en el plano utilizando Punto2D

class Rectangulo {
private:
	Punto2D esq_sup_izda;
	double base;
	double altura;
	
public:
	/*********************************************************************/
	//	Constructores
	
	//--------------------------------------
	//	Constructor a partir de la esquina sup. izda., la base y la altura
	Rectangulo (Punto2D la_esq_sup_izda, double la_base, double la_altura)
		:	esq_sup_izda (la_esq_sup_izda),
			base (la_base),
			altura (la_altura)
	{}
	
	/*********************************************************************/
	//	Metodos de consulta
	
	//--------------------------------------
	//	Esquina Superior Izquierda
	Punto2D GetEsqSI (){
		return esq_sup_izda;
	}
	
	//--------------------------------------
	//	Esquina Inferior Izquierda
	Punto2D GetEsqII (){
		return Punto2D (esq_sup_izda.GetX(), esq_sup_izda.GetY() - altura);
		
	}
	
	//--------------------------------------
	//	Esquina Superior Derecha
	Punto2D GetEsqSD (){
		return Punto2D (esq_sup_izda.GetX() + base, esq_sup_izda.GetY());
	}
	
	//--------------------------------------
	//	Esquina Inferior Derecha
	Punto2D GetEsqID (){
		return Punto2D (esq_sup_izda.GetX()+base, esq_sup_izda.GetY() - altura);
	}
	
	//--------------------------------------
	//	Base
	double GetBase (){
		return base;
	}
	
	//--------------------------------------
	//	Altura
	double GetAltura (){
		return altura;
	}
	
	/*********************************************************************/
	//	Calculos
	
	//--------------------------------------
	//	Devuelve el perimetro del rectangulo
	double Perimetro (){		
		return (2 * (base + altura));
	}
	
	//--------------------------------------
	//	Devuelve el Area del rectangulo
	double Area (){
		return (base * altura);
	}
	
	//--------------------------------------
	//	Devuelve el Punto central del rectangulo
	Punto2D Centro(){
		double x = esq_sup_izda.GetX() + (base/2);
		double y = esq_sup_izda.GetY() - (altura/2);
		
		return Punto2D(x, y);
	}
	
	//--------------------------------------
	//	Comprueba si un punto esta contenido en el rectangulo
	bool ContieneA (Punto2D p){
		bool x_ok = (p.GetX() >= esq_sup_izda.GetX()) && 
					(p.GetX() <= GetEsqID().GetX());
					
		bool y_ok = (p.GetY() <= esq_sup_izda.GetY()) && 
					(p.GetY() >= GetEsqID().GetY());
		
		return (x_ok && y_ok);
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
		
		return ((x_0 * x_0) + (y_0 * y_0) == radio);
		
	}
	
};
const double Circunferencia::PI = 6 * asin(0.5);

/****************************************************************************/
/****************************************************************************/
int main () {
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	//------------------------------------------
	//	ENTRADA
	
	double x;
	double y;
	
	//Definimos el rectangulo
	cout << "Defina el rectangulo: " << endl;
	
	//Esquina Superior Izquierda
	cout << "- Esquina superior izquierda:" << endl;
	cout << "\t" << "x = ";
	cin >> x; 

	cout << "\t" << "y = ";
	cin >> y; 
	
	//Base
	double base;
	do {
		cout << "- Base = ";
		cin >> base;
		
	} while (base <= 0);
	
	//Altura
	double altura;
	do {
		cout << "- Altura = ";
		cin >> altura;
	} while (altura <= 0);
	
	Rectangulo rec(Punto2D(x,y), base, altura);
	
	//Ya definido el rectangulo, definiremos la circunferencia a partir de su 
	//centro y del radio inicial
	const double RADIO_INICIO = 0.5;
	const double INCREMENTO_RADIO = 0.25;
	
	Circunferencia cir (rec.Centro(), RADIO_INICIO);
	
	//------------------------------------------
	//	CALCULOS
	
	double area_rec = rec.Area();
	
	while (cir.Area() < area_rec){
		cir.SetRadio((cir.GetRadio() + INCREMENTO_RADIO));
	}
	
	//------------------------------------------
	//	SALIDA
	
	cout << endl;
	cout << "Rectángulo: " << endl;
	//Coordenadas de los puntos que definen al rectángulo
	cout << "\t" << "Esquina superior izquierda = " 
		 << rec.GetEsqSI().ToString() << endl;
	
	cout << "\t" << "Esquina inferior derecha = " 
		 << rec.GetEsqID().ToString() << endl;
		 
	//Área del rectangulo
	cout << "\t" << "Area del rectangulo: " << rec.Area() << endl;
	
	cout << endl;
	cout << "Circunferencia:" << endl;
	
	//Centro de la circunferencia
	cout << "\t" << "Centro = " << cir.GetCentro().ToString() << endl;
	
	//Radio y área de la circunferencia
	cout << "\t" << "Radio = " << cir.GetRadio() << endl;
	cout << "\t" << "Área = " << cir.Area() << endl;
	
	return 0;
}
