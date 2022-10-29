/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 7
// 
// (Examen de Febrero 2016)
/* 
	Este programa aproxima mediante polígonos regulares una circunferencia. 
	Se van generando polígonos regulares, de doble número de lados respecto 
	al anterior, hasta que el área del poligono sea similar a la del círculo 
    cuya circunferencia se pretende aproximar.
	Para más detalles, ver enunciado.  
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/***************************************************************************/
const double PI = 3.1415926;

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
	int pos = 0;
	while (pos <cadena.length() && cadena.back() == a_borrar) pos++;

	string local; 
	
	// Copiar todos los que quedan
	while (pos <cadena.length()) {
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
                       int decimales, char relleno= ' ')
{
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

/***************************************************************************/
// Convierte el dato int "entero" a un string con "num_casillas" casillas 
// que contiene el valor textual de "entero".
// 
// Recibe: 	entero, el valor a transformar.
//			num_casillas, nÃºmero total de casillas que tendrÃ¡ el resultado.
//			relleno, el carÃ¡cter que se emplea para rellenar los huecos. 
// Devuelve: el string compuesto.  
//
// NOTAS: Si el nÃºmero de casillas solicitado es mayor que el que se necesita, 
//	  	se completa al principio con "relleno" hasta alcanzar un tamaÃ±o de 
//	  	"num_casillas". Si el valor tuviera "per se" mÃ¡s de "num_casillas" 
//		se devuelve tal cual.  

string ToStringInt (int entero, int num_casillas, char relleno=' ')
{
	// Inicialmente nos quedamos con el resultado de to_string
	string cadena = to_string(entero);

	int long_cadena = (int) cadena.length(); 
	
	// Si es preciso se completa (por la izquierda) con RELLENO_INT
	
	if (long_cadena < num_casillas) {
		
		int num_casillas_faltan = num_casillas-long_cadena; 
		
		for (int i=0; i<num_casillas_faltan; i++) 
			cadena = relleno + cadena; 
	}

	return (cadena);
}

/***************************************************************************/

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Punto2D
{
private:
	
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x;
	double y;

public:
	
	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está creando.
	
	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/***********************************************************************/
	// Método Set para fijar simultaneamente las coordenadas. 
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está modificando.
	
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/***********************************************************************/
	// Métodos Get para leer las coordenadas

	double GetX (void)
	{
		return (x);
	}
	double GetY (void)
	{
		return (y);
	}

	/***********************************************************************/
	// Calcula si dos puntos son iguales 
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto implícito. 
	// Devuelve: true, si se consideran iguales los dos objetos. 

	bool EsIgual (Punto2D otro)
	{
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	/***********************************************************************/
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que 
	// se recibe como argumento. 
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la 
	// distancia euclídea.
	// Devuelve: la distancia entre los dos puntos. 

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}

	/***********************************************************************/
	// Serializa un dato "Punto2D"
	
	string ToString ()
	{
		return ("[" + ToStringDouble (x, 7, 3, ' ') + ", " + 
		              ToStringDouble (y, 7, 3, ' ') + "]");
	}
	
	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class PoligonoRegular
{

private:
		
	Punto2D centro;     // Centro de la circunferencia circunscrita
 						// que encierra al polígono.

	int 	num_lados; 	// Num. de lados del polígono
	double 	longitud;   // Longitud de cada lado

public:
	
	/***********************************************************************/
	// Constructores
	/***********************************************************************/
	
	PoligonoRegular() : centro (Punto2D(0.0,0.0)),
						num_lados(3), longitud(1)
	{ }

	/***********************************************************************/

	PoligonoRegular(int el_numero_lados, double la_longitud_lado)
				: centro (Punto2D(0.0,0.0)), 
				  num_lados(el_numero_lados), longitud(la_longitud_lado)
	{ }


	/***********************************************************************/

	PoligonoRegular(int el_numero_lados, 
	                double la_longitud_lado, 
	                Punto2D el_centro) 
				  : centro (el_centro), 
				    num_lados(el_numero_lados), 
					longitud(la_longitud_lado)
	{ }

	/***********************************************************************/
	// Métodos de consulta 
	/***********************************************************************/
	
	Punto2D GetCentro ()
	{
		return (centro);	
	}
	/***********************************************************************/

	double GetLongitud ()
	{
		return (longitud);	
	}
	
	/***********************************************************************/

	int GetNumLados ()
	{
		return (num_lados);	
	}
	
	/***********************************************************************/

	double GetRadio ()
	{
		return (longitud/(2.0*sin(PI/num_lados)));	
	}

	/***********************************************************************/

	double GetApotema ()
	{
		return (longitud/(2.0*tan(PI/num_lados)));	
	}

	/***********************************************************************/
	// Métodos de cálculo
	/***********************************************************************/

	double Perimetro ()
	{
		return (longitud*num_lados);	
	}
	
	/***********************************************************************/

	double Area ()
	{
		return (0.25*num_lados*longitud*longitud / tan(PI/num_lados));	
		
		// También puede calcularse (ver enunciado) como: 
		// Area = 0.5*num_lados*radio*radio*sin((2*PI)/num_lados)
	}
		
	/***********************************************************************/

	/***********************************************************************/
	// Otros métodos
	/***********************************************************************/

	PoligonoRegular Poligono_Duplicado()
	{
		PoligonoRegular nuevo (num_lados*2, 
		                       NuevaLongitudDuplicandoLados(), 
							   centro);
		return (nuevo);
	}

	PoligonoRegular Poligono_kMultiplicado (int k)
	{
		PoligonoRegular nuevo (num_lados*k, NuevaLongitud(k), centro);
		return (nuevo);
	}
	
	/***********************************************************************/

	bool MayorQue (PoligonoRegular otro)
	{
		return (Area() > otro.Area());
	}

	/***********************************************************************/
	// Serializa un dato PoligonoRegular
	
	string ToString (string msg)
	{
		string cad;
		
		cad = "----------------------------------------------\n";	
		cad = cad + msg + "\n";		
		cad = cad + "----------------------------------------------\n";	
		cad = cad + "Centro     = " + GetCentro().ToString() + "\n";
		cad = cad + "Num. lados = " + ToStringInt(GetNumLados(),3) + "\n";
		cad = cad + "Longitud   = " + ToStringDouble(GetLongitud(),8,4) +"\n";
		cad = cad + "Radio      = " + ToStringDouble(GetRadio(),8,4) + "\n";
		cad = cad + "Apotema    = " + ToStringDouble(GetApotema(),8,4) + "\n";
		cad = cad + "\n";	
		cad = cad + "Area       = " + ToStringDouble(Area(),8,4) + "\n";
		cad = cad + "Perimetro  = " + ToStringDouble(Perimetro(),8,4) + "\n";		
		cad = cad + "----------------------------------------------\n";	
		cad = cad + "\n";
		
		return cad; 
	}	
	
	/***********************************************************************/
	
private:
		
	/***********************************************************************/
	// Devuelve el ángulo interno (en radianes) 
	float AnguloInterno ()
	{
		return (2*PI/ num_lados);	
	}

	/***********************************************************************/
	// Devuelve la longitud del lado del nuevo poligono resultado de duplicar
	// el núnero de lados. El radio sigue siendo el mismo.

	double NuevaLongitud (int k)
	{
		double r = GetRadio();

		double nueva_longitud = r * sqrt(2*(1-cos((2*PI)/(k*num_lados))));

		return (nueva_longitud);
	}
	
	/***********************************************************************/
	// Devuelve la longitud del lado del nuevo poligono resultado de duplicar
	// el núnero de lados. El radio sigue siendo el mismo. 
	
	double NuevaLongitudDuplicandoLados()
	{
		double r = GetRadio();
		double a = GetApotema();

		double cat1 = longitud/2;
		double cat2 = r-a; 

		double nueva_longitud = sqrt(cat1*cat1 + cat2*cat2);
				
		return (nueva_longitud);
	}

	/***********************************************************************/
	
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

void Pinta (PoligonoRegular poligono, string msg)
{
	cout << "----------------------------------------------" << endl;
	cout << msg << endl;		
	cout << "----------------------------------------------" << endl;
	cout << "Centro     = " << poligono.GetCentro().ToString() << endl;
	cout << "Num. lados = " << poligono.GetNumLados() << endl;
	cout << "Longitud   = " << poligono.GetLongitud() << endl;
	cout << "Radio      = " << poligono.GetRadio() << endl;
	cout << "Apotema    = " << poligono.GetApotema() << endl;
	cout << endl;
	cout << "Area       = " << poligono.Area()<< endl;
	cout << "Perimetro  = " << poligono.Perimetro()<< endl;			
	cout << "----------------------------------------------" << endl;
	cout << endl;
}

/***************************************************************************/
/***************************************************************************/

int main ()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	// Primera parte: Crear dos polígonos, "polígono1" con los valores por 
	// defecto y "polígono2" con 6 lados de longitud 4 y centrado en (0,0). 
	// El programa comprueba si "polígono1" es mayor que "polígono2"
	
	// Constructor sin argumentos

	PoligonoRegular poligono1;
	
	cout << poligono1.ToString("poligono1 - Poligono_por_defecto");
	
	
	// Constructor con dos argumentos

	PoligonoRegular poligono2 (6, 4);
	
	cout << poligono2.ToString("poligono2 - Hexagono l=4");
	
	// Comparar áreas
	
	cout << endl;	
	if (poligono1.MayorQue(poligono2)) {
		cout << "poligono1 es mayor que poligono2"	<< endl;
	} 
	else {
		cout << "poligono2 es mayor que poligono1"	<< endl;		
	}
	cout << endl  << endl;		
	
	
	// Segunda parte: Crear "polígono3" a partir de "polígono1" con 
	// la misma circunferencia ciorcunscrita y el doble número de lados. 
	
	PoligonoRegular poligono3 = poligono1.Poligono_kMultiplicado(2);
	
	cout << poligono3.ToString("poligono3 - Duplicando poligono1");
	
	
	/***********************************************************************/
	// Tercera parte: Calcular el poligono que aproxima a una circunferencia. 
	// En este caso se emplea como punto de partida un triangulo equilátero 
	// de longitud 2 y en cada paso se DUPLICA el número de lados del 
	// polígono. Se termina cuando el área del polígono regular sea similar 
	// a la de la circunferencia circunscrita. 
	
	PoligonoRegular p (3, 2); // Polígono regular inicial

	// Calcular el área de la circunferencia circunscrita  

	double radio = p.GetRadio();
	double area_objetivo = PI * radio * radio; 
		
	cout << endl; 
	cout << "Calculando el poligono que aproxima a una circunferencia " 
	     << "de radio " << radio << endl;
	cout << "Area de la circunferencia objetivo = " 
		 << setw(10) << setprecision(8) << area_objetivo << endl;
	cout << endl;
		 
	cout << "Se construye desde el poligono regular siguiente: ";
	cout << endl;
		
	cout << p.ToString("Poligono base para la aproximacion");
		 
	
	while (!SonIguales(p.Area(), area_objetivo)) {
	
	    double dif = area_objetivo-p.Area(); 
	    
		cout << "Lados = " << setw(5) << p.GetNumLados() 
		     << " Area = " << setw(10) << setprecision(8) << p.Area();
		cout << " Dif  = " << setw(10) << setprecision(8) << dif << " <-> " 
			 << setw(10) << setprecision(8) << PRECISION_SON_IGUALES << endl;
			 		 	
		// Calcular nuevo polígono duplicando el número de lados
		p = p.Poligono_Duplicado(); 
	}
	
	double dif = area_objetivo-p.Area(); 
	
	cout << endl;
	cout << "POLIGONO RESULTADO: " << endl;
	cout << "Lados = " << setw(5) << p.GetNumLados() 
		 << " Area = " << setw(10) << setprecision(8) << p.Area();
	cout << " Dif  = " << setw(10) << setprecision(8) << dif << " <-> " 
			 << setw(10) << setprecision(8) << PRECISION_SON_IGUALES << endl;
	cout << endl << endl;
		     


	/***********************************************************************/
	// Tercera parte (versión más general). Se resuelve el mismo problema: 
	// calcular el poligono que aproxima a una circunferencia empleando como 
	// punto de partida un triangulo equilátero de longitud 2. 
	// Ahora, en cada paso se MULTIPLICA el número de lados del polígono por 
	// un valor que establece el usuario. 
	// Se termina cuando el área del polígono regular sea similar 
	// a la de la circunferencia circunscrita. 
	

	cout << "**************************************************" << endl;
	cout << "NUEVA VERSION" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
	
	
	int k;
	
	cout << "Factor multiplicador del numero de lados: ";
	cin >> k;
	
	
	PoligonoRegular p_NUEVO (3, 2);
	
	// Calcular el área de la circunferencia circunscrita
	
	double radio_NUEVO = p_NUEVO.GetRadio();
	double area_objetivo_NUEVO = PI * radio_NUEVO * radio_NUEVO;

	cout << endl;
	cout << "Calculando el poligono que aproxima a una circunferencia "
	     << "de radio " << radio_NUEVO << endl;
	cout << "Area de la circunferencia objetivo = "
		 << setw(10) << setprecision(8) << area_objetivo_NUEVO << endl;
	cout << endl;

	cout << "Se construye desde el poligono regular siguiente: ";
	cout << endl;

	cout << p_NUEVO.ToString("Poligono base para la aproximacion");


	while (!SonIguales(p_NUEVO.Area(), area_objetivo_NUEVO)) {

	    double dif_NUEVO = area_objetivo_NUEVO-p_NUEVO.Area(); 

		cout << "Lados = " << setw(5) << p_NUEVO.GetNumLados()
		     << " Area = " << setw(10) << setprecision(8) << p_NUEVO.Area();
		cout << " Dif  = " << setw(10) <<setprecision(8)<< dif_NUEVO << " <-> " 
			 << setw(10) << setprecision(8) << PRECISION_SON_IGUALES << endl;

		// Calcular nuevo polígono multiplicando por "k" el número de lados
		p_NUEVO = p_NUEVO.Poligono_kMultiplicado(k);
	}

	double dif_NUEVO = area_objetivo_NUEVO-p_NUEVO.Area(); 

	cout << endl;
	cout << "POLIGONO RESULTADO: " << endl;
	cout << "Lados = " << setw(5) << p_NUEVO.GetNumLados()
		 << " Area = " << setw(10) << setprecision(8) << p_NUEVO.Area();
	cout << " Dif  = " << setw(10) << setprecision(8) << dif_NUEVO << " <-> " 
			 << setw(10) << setprecision(8) << PRECISION_SON_IGUALES << endl;
	cout << endl << endl;
	     
	return 0;
}

/***************************************************************************/
/***************************************************************************/

