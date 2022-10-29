/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 30 - III: Este programa leerá los parámetros de una 
	distribución gaussiana y a continuación mostrará los valores de:
	
		a) g(x) con la función escrita en el ejercicio 8:
	                               			{	   	 (x-esperanza)^2 }
						                    { -0.5 * (-----------)   }
	                    1                   {        (desviacion )   }
			y = ----------------------  * e^                  
	                           ______
			     desviacion * V 2*PI  
			     
		b) CDF(x) con la función escrita en el ejercicio 28:
		
			 /x
			|
		    |	g(x) dx
			|
		   /-oo
			
		c) CDF(x) con la función escrita en el ejercicio 29:
		
			w = 1 - g(|x|) * [b1t + b2(t^2) + b3(t^3) + b4(t^4) + b5(t^5)]
		
						    1	
			donde t = ------------- 
						1 + b0|x|
			
			siendo constantes bi, donde i = [0, 5]
			
			finalmente si x>= 0 entonces CDF(x) = w. Si no, CDF(x) = 1 - w

	Para valores de x comprendidos entre (esperanza - 3*desviacion) y 
	(esperanza + 3*desviacion). Usaremos 0.25 como la diferencia entre dos 
	valores consecutivos de x.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>

using namespace std;

//Función A
double Gaussiana (double x, double esperanza, double desviacion){ 
	const double PI = 3.1415927;
	double imagen;
	
	double parte_final = (desviacion * sqrt (2 * PI));
	double potencia = pow (((fabs(x) - esperanza) / desviacion), 2);
	
	imagen = exp ((-0.5) * potencia) / parte_final;
	
	return imagen;
}

//Función B
double CDF_Integral (double x, double esperanza, double desviacion){
	const double PI = 3.1415927;
	const double SALTO = 0.00001;
	
	double x_inicial = esperanza - (3 * desviacion);	
	double imagen;
	double cdf = 0;
	
	//CORRECCIÓN
	double parte1 = (desviacion * sqrt (2 * PI));
	
	while (x_inicial <= x){
		imagen = 
			exp ((-0.5) * pow (((fabs(x_inicial)-esperanza) / desviacion), 2));
		
		cdf += imagen;
		
		x_inicial += SALTO;
	}
	cdf /= parte1;
	cdf *= SALTO;
	
	return cdf;
}

double CDF_Aprox (double x, double esperanza, double desviacion){
	const double b0 = 0.2316419;
	const double b1 = 0.319381530;
	const double b2 = - 0.356563782;
	const double b3 = 1.781477937;
	const double b4 = - 1.821255978;
	const double b5 = 1.330274429;
	const double PI = 3.1415927;

	double t = 1 / (1 + (b0 * fabs(x)));
	double t2 = t * t;
	double t3 = t2 * t;
	double t4 = t3 * t;
	double t5 = t4 * t;
	
	double w;
	
	double g_x;
	double parte1 = sqrt (2 * PI);
	double cdf;
	
	//Calculamos la imagen
	g_x = exp ((-0.5) * pow (x, 2)) / parte1;
	
	w = 1 - g_x * ((b1*t) + (b2*t2) + (b3*t3) + (b4*t4) + (b5*t5));
	
	if (x >= 0){
		cdf = w;
	} else {
		cdf = 1 - w;
	}
	
	return cdf;
}

int main () {
	//Variables
	double x;
	double x_final;
	
	double esperanza;
	double desviacion;
	
	double g_x;
	double cdf_integral;
	double cdf_aprox;
	
	const double SALTO = 0.25;
	
	
	//Recogida de datos
		//Esperanza
		cout << "Introduzca el valor de la esperanza o media: ";
		cin >> esperanza;
		
		//Desviación típica
		cout << "Introduzca el valor de la desviación típica: ";
		cin >> desviacion;
		
		while (desviacion < 0){
			cout << "ERROR: La desviación típica debe ser mayor o igual que 0. "
				 << "Vuelva a introducirla" << endl;
			
			cout << endl;
			cout << "Introduzca el valor de la desviación típica: ";
			cin >> desviacion;
		}
		cout << endl;
	
	x = esperanza - (3 * desviacion);
	x_final = esperanza + (3 * desviacion);
	
	while (x < x_final){
		g_x = Gaussiana(x, esperanza, desviacion);
		cdf_integral = CDF_Integral(x, esperanza, desviacion);
		cdf_aprox = CDF_Aprox(x, esperanza, desviacion);
		
		cout << "x = " << x << endl;
		cout << "\t" << "g(x) = " << g_x << endl;
		cout << "\t" << "CDF = " << cdf_integral << endl;
		cout << "\t" << "CDF aproximado = " << cdf_aprox << endl;
		cout << endl;
		
		x += SALTO;
	}
	
	return 0;
}
