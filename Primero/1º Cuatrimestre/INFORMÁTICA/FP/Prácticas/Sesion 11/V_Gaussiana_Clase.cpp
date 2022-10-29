/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 4 - VI: Programa que calcula e imprime:
		a) 	El valor de una gaussiana, dados sus parámetros (desviación típica 
			-s- y esperanza -m-).
		b) 	El valor aproximado de la CDF(x) para distintos valores de x 
			comprendidos entre m-3s y m+3s.

	Entradas: parámetros de la gaussiana (desviacion -s-, y esperanza -m-) 
	Salidas:  Para valores de x entre m-3s y m+3s: 	

		a) El valor de la gaussiana g(x)

                                                {        (x-esperanza)^2 }
                                                { -0.5 * (-----------)   }
                            1                   {        (desviacion )   }
                g(x) = ----------------------  * e^
                                     ______
                       desviacion * V 2*PI     
	
		
		b) La aproximación de la CDF(x) por: 
			  
	                       / x
				          |
				CDF(x) =  |  g(x) d(x)
				          |
	                     / -oo
                 
			donde g(x) es el valor de la función gaussiana en x.

			Puede obtenerse un valor aproximado de CDF(x) como la suma de 
			valores de g(x), empezando por valores alejados de la media 
			(y menores que ella). Para el cálculo práctico de CDF(x) 
			la integral se convierte en una suma, y se requiere concretar 
			cuántas sumas se van a realizar. Basta con indicar:
				a) un valor inicial para x (tomaremos m-3s).
				b) un “salto” entre dos valores consecutivos de x 
				   (en una constante).		  
		
		c) La aproximación de la CDF(x) por una aproximación numérica. 
		
			Previamente tenemos que transformar la variable x que sigue una 
			distribución N(m, s) en otra variable z que siga una distribución 
			estandarizada N(0,1) con la operación:
            
            	z = (x-m)/s  
            
            Entonces: 
		            
			w = 1 - Gauss(|z|, 0, 1)(b1*t + b2*t^2 + b3*t^3 + b4*t^4 + b5*t^5)
			
			dónde:
                      1 
               t = ----------
                   1 + b0*|z|
                
            b0 = 0.231641900	b1 = 0.319381530	b2 = -0.356563782
            b3 = 1.781477937	b4 = -1.821255978	b5 = 1.330274429
            
            Finalmente, si x>=0, CDF(x)=w. Si no, CDF(x)=1-w 

******************************************************************************/

#include <iostream> // Inclusión de los recursos de E/S
#include <iomanip>
#include <cmath> // Inclusión de los recursos matemáticos

using namespace std;

/******************************************************************************/
//-------------------------------------------
class Gaussiana {
	private:
		double esperanza;
		double desviacion;
		static const double PI;
	
	public:
		//-------------------------------------------
		// Creamos el constructor con el que inicializaremos un objeto
		
		Gaussiana (double esperanza, double desviacion)
			:	esperanza (esperanza), 
				desviacion (desviacion)
		{}
		
		//-------------------------------------------
		// Creación de los métodos Get para poder operar en el main con los
		// valores de los datos miembro, pues estos son privados
		
		double GetEsperanza (void) {
			return(esperanza);
		}
		
		double GetDesviacion (void) {
			return(desviacion);
		}
		
		//-------------------------------------------
		// Muestra en el main la distribución normal que sigue la función 
		// gaussiana del usuario
		
		string ToString (void) {
			string cad;
			
			cad = "N(" + to_string(esperanza) + ", " + to_string(desviacion) 
			+ ")";
			
			return(cad);
		}
		
		//-------------------------------------------
		// Cálculo de g(x) - APARTADO A
		
		double Gauss (double x) {			
			return (exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / 
		    (desviacion * sqrt(2*PI)));
		}
		
		//-------------------------------------------
		// Cálculo de CDF_1(x) (Mediante suma) - APARTADO B
		
		double CDF_1 (double x) {
	        const double SALTO_CDF = 0.001;	

	        // Cálculos de la CDF (fuerza bruta, no está optimizado)
			double abscisa_inic = esperanza-(3*desviacion); 
	        double abscisa_fin  = x; 
	
	        // Valor común que puede precalcularse   
	        double d = desviacion*sqrt(2*PI);

	        // Acumular g(x)
	        double suma_g_abs = 0.0; 
			
	        for (double abs=abscisa_inic; abs<abscisa_fin; abs+=SALTO_CDF) {
		       double g_abs = exp (-0.5*pow((abs-esperanza)/desviacion, 2)) / d;
		       suma_g_abs += g_abs;
		       
		    }

	        return (suma_g_abs * SALTO_CDF);
	    }
	    
	    //-------------------------------------------
	    // Cálculo de CDF_2(x) (Aproximación) - APARTADO C
	    
	    double CDF_2 (double x) {
	    	const double B0 =  0.231641900;
	        const double B1 =  0.319381530;
	        const double B2 = -0.356563782;
	        const double B3 =  1.781477937;
	        const double B4 = -1.821255978;
	        const double B5 =  1.330274429;

	        // Estandarizar la distribución gaussiana  
	        // Si x -> N(m,s) y z = (x-m)/s entonces z -> N(0,1)    
	
	        double z = (x-esperanza)/desviacion; // variable aleatoria N(0,1)  
	
	        double t = 1.0 / (1 + B0*fabs(z));
	        double t2 = t*t;
	        double t3 = t2*t; // t*t*t
	        double t4 = t3*t; // t*t*t*t
	        double t5 = t4*t; // t*t*t*t*t

	        Gaussiana g_estandarizada (0,1);
	
	        double g_std_x = g_estandarizada.Gauss(fabs(z));
	        double w = 1.0 - g_std_x * (B1*t + B2*t2 + B3*t3 + B4*t4 + B5*t5);

	        return (x>=0.0 ? w : 1.0-w);
	    }
};
const double Gaussiana::PI = 3.14159265358979323846;

/****************************************************************************/
/****************************************************************************/
int main() { 
	// Programa principal
	const double NUM_STDV = 3.0;
	const double SALTO_X  = 0.25;

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	double esperanza;
	double desviacion;
	
	// Entrada de datos
	cout << "Introduzca los parámetros de la gaussiana: ";
	cout << endl;
	
	cout << "Esperanza = ";
	cin >> esperanza;
	
	do {
		cout << "Desviación típica = ";
		cin >> desviacion;
	} while (desviacion <= 0);
	
	cout << endl;
	
	// Creación del objeto g
	Gaussiana g (esperanza, desviacion);
	
	// Mostramos en pantalla la distribución normal de la gaussiana introducida
	cout << endl;
	cout << "Esta gaussiana sigue una distribución normal de " << g.ToString();
	cout << endl;
	cout << endl;
	
	// Cálculos y salida de datos
	
	double min_x = g.GetEsperanza() - NUM_STDV*g.GetDesviacion();
	double max_x = g.GetEsperanza() + NUM_STDV*g.GetDesviacion();
	
	for (double x = min_x; x <= max_x; x += SALTO_X) {
	
			double g_x;	    // g(x)
			double cdf_1_x; // CDF_1(x) // "integral"
			double cdf_2_x; // CDF_2(x) // aprox. numérica
		
			// Cálculo de g(x) y CDFs(x)
			g_x     = g.Gauss(x);
			cdf_1_x = g.CDF_1(x);
			cdf_2_x = g.CDF_2(x);
	
			// Presentación de resultados
			cout << "G(" << setw(11) << setprecision(7) << x << ") = " 
				 << setw(10) << setprecision(7) << g_x << "       ";
			cout << "CDF_1 (" << setw(11) << setprecision(7) << x << ") = " 
				 << setw(10) << setprecision(7) << cdf_1_x << "       ";
			cout << "CDF_2 (" << setw(11) << setprecision(7) << x << ") = " 
				 << setw(10) << setprecision(7) << cdf_2_x;			
			cout << endl;
		
	}
	
	return 0;
}
