/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 4 - VI: Este programa leerá las coordenadas que definen un 
	rectángulo y calculará la circunferencia centrada en el punto de corte de 
	las diagonales del rectángulo tal que su superficie sea la menor entre 
	todas las circunferencias de área mayor que la del rectángulo.
	
	Para el cálculo, considere comenzar con radio=0.5 e ir incrementando su
	valor 0.25 en cada iteración.
	
	Para modelar un rectángulo se usará la clase Rectangulo. Un rectángulo
	se caracterizará por la coordenada superior izquierda y la coordenada 
	inferior derecha (ambos son datos struct de tipo Punto2D).
	
	Para modelar una circunferencia se usará la clase Circunferencia.
	Una circunferencia se caracterizará por la coordenada del centro (un dato
	struct de tipo Punto2D) y el radio.

*****************************************************************************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std; 

//	STRUCTS
struct Punto2D {
	double x;
	double y;
};

//	CONSTANTES
const double PI = 3.1416;


/***************************************************************************
//	CLASE Rectangulo
	
	Esta clase representara a un rectangulo.
***************************************************************************/
class Rectangulo {
	private:
		Punto2D sup_izqda;
		Punto2D inf_dcha;
			
	public:
		Rectangulo (Punto2D superior_izquierda, Punto2D inferior_derecha)
			: 	sup_izqda(superior_izquierda),
				inf_dcha(inferior_derecha)
		{}
		
		Punto2D GetSupIzqda (){
			return sup_izqda;
		}
		
		Punto2D GetInfDcha(){
			return inf_dcha;
		}
		
		//------------------------------------------------------------------
		//	Se calculará el punto donde se cortan las diagonales del 
		//	rectángulo
		//
		//	PRE: El rectángulo debe estar bien definido
		
		Punto2D PuntoCorteDiagonales(){
			Punto2D corte_diagonal;
			
			corte_diagonal.x = (inf_dcha.x + sup_izqda.x) / 2;
			corte_diagonal.y = (inf_dcha.y + sup_izqda.y) / 2;
			
			return corte_diagonal;
		}
		
		//------------------------------------------------------------------
		//	Se calculará el valor del área del rectángulo
		//
		//	PRE: El rectángulo debe estar bien definido

		double Area(){
			double area = fabs(sup_izqda.x - inf_dcha.x) * 
				   fabs(sup_izqda.y - inf_dcha.y);
			
			return area;
		}
};

class Circunferencia { 
	private:
		Punto2D centro; 
		double radio;
				
	public:
		Circunferencia(Punto2D punto_centro, double dist_radio)
			:	centro(punto_centro),
				radio(dist_radio)
		{	}
		
		//Metodos Get
		Punto2D GetCentro(){
			return centro;
		}
		
		double GetRadio(){
			return radio;
		}
		
		//------------------------------------------------------------------
		//	Se calculará el valor del área de la circunferencia
		
		double Area(){
			double area = PI * radio * radio;
			
			return area;
		}
		
		//------------------------------------------------------------------
		//	Se aumentará el valor del radio
		//	
		//	RECIBE: Valor con el que aumentar el radio
		
		void AumentaRadio (double valor){
			radio += valor;
		}
		
};
/***************************************************************************/

/****************************************************************************
// 	Devuelve un string con la expresión textual de un punto.

	Recibe: Punto a expresar
	Devuelve: la representación textual de "p".
****************************************************************************/
string ToString (Punto2D punto) {	
	string cadena;
	
	cadena = "(" + to_string(punto.x) + ", " + to_string(punto.y) 
		   	 + ")";
		
	return (cadena);
}

/***************************************************************************/
/***************************************************************************/
int main () {
	//Constantes
	const double RADIO_INICIO = 0.5;
	const double SALTO_DE_RADIO = 0.25;
	
	//Variables
	
	//Con estos puntos crearemos despues el rectangulo
	Punto2D sup_izquierda;
	Punto2D inf_derecha;
	
	
	//---------------------------------	
	//ENTRADA
	
	cout << "Coordenadas de la esquina superior izquierda:" << endl;
	cout << "\t" << "x = ";
	cin >> sup_izquierda.x;
	
	cout << "\t" << "y = ";
	cin >> sup_izquierda.y;
	
	//El punto que define la esquina inferior derecha del rectángulo no puede
	//estar ni por encima ni a la izquierda del punto que define la esquina
	//superior izquierda. Con esto nos aseguramos de que el rectángulo está
	//bien definido
	cout << "Coordenadas de la esquina inferior derecha:" << endl;
	do {
		cout << "\t" << "x = ";	
		cin >> inf_derecha.x;
		
	} while (inf_derecha.x <= sup_izquierda.x);
	
	do {
		cout << "\t" << "y = ";
		cin >> inf_derecha.y;
		
	} while (inf_derecha.y >= sup_izquierda.y);
	
	Rectangulo rectangulo(sup_izquierda, inf_derecha);
	
	//---------------------------------
	//CÁLCULOS
	
	Punto2D pto_corte_diagonales = rectangulo.PuntoCorteDiagonales();
	
	double area_rectangulo = rectangulo.Area();
	Circunferencia circunferencia(pto_corte_diagonales, RADIO_INICIO);
		
	while(circunferencia.Area() <= area_rectangulo){		
		circunferencia.AumentaRadio(SALTO_DE_RADIO);
		
	}
	
	//------------------------------------------
	//SALIDA
	cout << endl;
	cout << "Rectángulo: " << endl;
	//Coordenadas de los puntos que definen al rectángulo
	cout << "\t" << "Esquina superior izquierda = " 
		 << ToString(rectangulo.GetSupIzqda()) << endl;
	
	cout << "\t" << "Esquina inferior derecha = " 
		 << ToString(rectangulo.GetInfDcha()) << endl;
		 
	//Área del rectangulo
	cout << "\t" << "Area del rectangulo: " << rectangulo.Area() << endl;
	
	cout << endl;
	cout << "Circunferencia:" << endl;
	
	//Centro de la circunferencia
	cout << "\t" << "Centro = " << ToString(circunferencia.GetCentro()) << endl;
	
	//Radio y área de la circunferencia
	cout << "\t" << "Radio = " << circunferencia.GetRadio() << endl;
	cout << "\t" << "Área = " << circunferencia.Area() << endl;

	return 0;
}
