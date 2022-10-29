/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 4 - IV: Este programa leer� las coordenadas que definen un 
	rect�ngulo y calcular� la circunferencia centrada en el punto de corte de 
	las diagonales del rect�ngulo tal que su superficie sea la menor entre 
	todas las circunferencias de �rea mayor que la del rect�ngulo.
	
	Para el c�lculo, considere comenzar con radio=0.5 e ir incrementando su
	valor 0.25 en cada iteraci�n.
	
	Para modelar un rect�ngulo se usar� la clase Rectangulo. Un rect�ngulo
	se caracterizar� por la coordenada superior izquierda y la coordenada 
	inferior derecha (ambos son datos struct de tipo Punto2D).
	
	Para modelar una circunferencia se usar� la clase Circunferencia.
	Una circunferencia se caracterizar� por la coordenada del centro (un dato
	struct de tipo Punto2D) y el radio.

*****************************************************************************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std; 

struct Punto2D {
	double x;
	double y;
};

/***************************************************************************
//	CLASE Rectangulo
	
	Esta clase representara a un rectangulo.
***************************************************************************/
class Rectangulo {
	private:
		Punto2D sup_izqda;
		Punto2D inf_dcha;
		
		Punto2D corte_diagonal;
		
		double area;
	
	public:
		Rectangulo (Punto2D superior_izquierda, Punto2D inferior_derecha)
			: 	sup_izqda(superior_izquierda),
				inf_dcha(inferior_derecha),
				corte_diagonal ({0, 0}),
				area (0)
		{	}
		
		double GetArea(void){
			AreaRectangulo();
			return area;
		}
		
		Punto2D GetCorteDiagonales(void){
			PuntoCorteDiagonales();
			return corte_diagonal;
		}
		
	private:
		/*********************************************************************
		//	PuntoCorteDiagonales
		|
		|	Se calcular� el punto donde se cortan las diagonales del 
		|	rect�ngulo
		|
		|	PRE: El rect�ngulo debe estar bien definido
		********************************************************************/
		void PuntoCorteDiagonales(void){
			corte_diagonal.x = (inf_dcha.x - sup_izqda.x) / 2 + sup_izqda.x;
			
			corte_diagonal.y = (inf_dcha.y - sup_izqda.y) / 2 + sup_izqda.y;
		}
		
		/*********************************************************************
		//	AreaRectangulo
		|
		|	Se calcular� el valor del �rea del rect�ngulo
		|
		|	PRE: El rect�ngulo debe estar bien definido
		********************************************************************/
		void AreaRectangulo(void){
			area = fabs(sup_izqda.x - inf_dcha.x) * 
				   fabs(sup_izqda.y - inf_dcha.y);
			
		}

};

class Circunferencia { 
	private:
		Punto2D centro; 
		double radio;
		
		double area;
		
	public:
		Circunferencia(Punto2D punto_centro, double dist_radio)
			:	centro(punto_centro),
				radio(dist_radio)
		{	}
		
		
		/*********************************************************************
		//	AreaCircunferencia
		|
		|	Se calcular� el valor del �rea de la circunferencia
		|
		|	PRE: La circunferencia debe estar bien definida (radio > 0)
		********************************************************************/
		void AreaCircunferencia(void){
			const double PI = 3.1416;
			area = PI * radio * radio;
			
		}
};


/***************************************************************************/
int main () {
	//Constantes
	const double RADIO_INICIO = 0.5;
	const double SALTO_DE_RADIO = 0.25;
	
	//Variables
	
	//Con estos puntos crearemos despues el rectangulo
	Punto2D sup_izquierda;
	Punto2D inf_derecha;
	
	//ENTRADA
	cout << "Coordenadas de la esquina superior izquierda:" << endl;
	cout << "\t" << "x = ";
	cin >> sup_izquierda.x;
	
	cout << "\t" << "y = ";
	cin >> sup_izquierda.y;
	
	//El punto que define la esquina inferior derecha del rect�ngulo no puede
	//estar ni por encima ni a la izquierda del punto que define la esquina
	//superior izquierda. Con esto nos aseguramos de que el rect�ngulo est�
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
	
	//C�LCULOS
	Punto2D pto_corte_diagonales = rectangulo.GetCorteDiagonales();
	
	double area_rectangulo = rectangulo.GetArea();
	Circunferencia circunferencia(RADIO_INICIO, pto_corte_diagonales)
	
	cout << area_rectangulo << endl;
	
	while(area_circunferencia <= area_rectangulo){
		circunferencia.radio = radio;
		area_circunferencia = AreaCircunferencia(circunferencia);
		
		radio += SALTO_DE_RADIO;
	}
	
	//SALIDA DE DATOS
	cout << endl;
	cout << "Rect�ngulo: " << endl;
	//Coordenadas de los puntos que definen al rect�ngulo
	cout << "\t" << "Esquina superior izquierda = (" 
		 << rectangulo.superior_izquierda.x << ", " 
		 << rectangulo.superior_izquierda.y << ")" << endl;
	
	cout << "\t" << "Esquina inferior derecha = (" 
		 << rectangulo.inferior_derecha.x << ", " 
		 << rectangulo.inferior_derecha.y << ")" << endl;
		 
	//�rea del rectangulo
	cout << "\t" << "Area del rectangulo: " << area_rectangulo << endl;
	
	cout << endl;
	cout << "Circunferencia:" << endl;
	
	//Centro de la circunferencia
	cout << "\t" << "Centro = (" << circunferencia.centro.x << ", " 
		 << circunferencia.centro.y << ")" << endl;
	
	//Radio y �rea de la circunferencia
	cout << "\t" << "Radio = " << circunferencia.radio << endl;
	cout << "\t" << "�rea = " << area_circunferencia << endl;

	return 0;
}
