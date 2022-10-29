/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 3 - IV: Funcionamiento de este programa:
		1.- Se leerán los parámetros que definen una distribución gaussiana 
			(filtrados como sea conveniente) y se almacenarán en una dato de 
			tipo Gaussiana.
			
		2.- Se mostrarán los valores de x, g(x) y CDF(x) para valores de x en 
			el intervalo [esperanza - 3desviacion; esperanza + 3desviacion]
			
		3.- Se preguntará si se desea continuar, y de ser así, volver al 
			paso 1.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
#include <cmath>

using namespace std;

struct ValoresGaussiana {
	double x;
	double esperanza;
	double desviacion;
	
};

/*****************************************************************************
//	ValoresGaussiana
	
	Se leerán 3 datos: x, esperanza y desviacion; valores representativos
	de una función Gaussiana y nos devolverá un struct con dichos valores
	
	RECIBE: Datos de una función gaussiana (x, esperanza, desviacion)
	DEVUELVE: Struct de la función gaussiana
******************************************************************************/
ValoresGaussiana DevuelveGaussiana (double x, double esperanza, 
double desviacion){
	ValoresGaussiana datos_gaussiana;
	
	datos_gaussiana.x = x;
	datos_gaussiana.esperanza = esperanza;
	datos_gaussiana.desviacion = desviacion;
	
	return datos_gaussiana;
}

/*****************************************************************************
//	Gaussiana
	
	Leerá un dato tipo struct que contendrá los valores de una función gaussiana
	y calculará su imagen
	
	RECIBE: Struct de una función gaussiana (x, esperanza, desviacion)
	DEVUELVE: imagen de la función
	PRE: Los valores deben ser dados a través de un dato struct que los contenga
******************************************************************************/
double Gaussiana (ValoresGaussiana datos){ 
	const double PI = 3.1415927;
	double imagen;
	
	double parte_final = (datos.desviacion * sqrt (2 * PI));
	double potencia = pow (((datos.x - datos.esperanza) / datos.desviacion), 2);
	
	imagen = exp ((-0.5) * potencia) / parte_final;
	
	return imagen;
}

/*****************************************************************************
//	CDF_Integral
	
	Leerá un dato tipo struct que contendrá los valores de una función gaussiana
	y calculará su CDF a partir de una aproximación de la integral
		
		 / x
		|
		| g(x) dx
		|
	   / -oo
	   
	RECIBE: Datos de una función gaussiana (x, esperanza, desviacion)
	DEVUELVE: CDF de la función
	PRE: Los valores deben ser dados a través de un dato struct que los contenga
******************************************************************************/
double CDF_Integral (ValoresGaussiana datos){
	const double SALTO = 0.00001;
	
	double x_inicial = datos.esperanza - (3 * datos.desviacion);	
	ValoresGaussiana valores_gaussiana;
	double imagen;
	double cdf = 0;
	
	while (x_inicial <= datos.x){
		valores_gaussiana = DevuelveGaussiana(x_inicial, datos.esperanza, 
		datos.desviacion);
		
		imagen = Gaussiana (valores_gaussiana);
		
		cdf += imagen;
		
		x_inicial += SALTO;
	}
	cdf *= SALTO;
	
	return cdf;
}

/*****************************************************************************
//	CDF_Aprox
	
	Se calculará la CDF(x) de una función gaussiana a partir de la siguiente
	aproximacion:
		
		w = 1 - g(|x|) * [b1t + b2(t^2) + b3(t^3) + b4(t^4) + b5(t^5)]
	
					    1	
		donde t = ------------- 
					1 + b0|x|
		
		siendo constantes bi, donde i = [0, 5]
		
		finalmente si x>= 0 entonces CDF(x) = w. Si no, CDF(x) = 1 - w
	
	RECIBE: Datos de una función gaussiana (x, esperanza, desviacion)
	DEVUELVE: CDF aproximado
	PRE: Los valores deben ser dados a través de un dato struct que los contenga
******************************************************************************/
double CDF_Aprox (ValoresGaussiana datos){
	const double b0 = 0.2316419;
	const double b1 = 0.319381530;
	const double b2 = - 0.356563782;
	const double b3 = 1.781477937;
	const double b4 = - 1.821255978;
	const double b5 = 1.330274429;

	double t = 1 / (1 + (b0 * datos.x));
	double t2 = t * t;
	double t3 = t2 * t;
	double t4 = t3 * t;
	double t5 = t4 * t;
	
	double w;
	
	double g_x;
	double cdf;
	
	//Calculamos la imagen normalizada (esperanza = 0 && desviacion = 1)
	ValoresGaussiana valores_gaussiana = DevuelveGaussiana(datos.x, 0, 1);
	
	g_x = Gaussiana(valores_gaussiana);
	
	w = 1 - g_x * ((b1*t) + (b2*t2) + (b3*t3) + (b4*t4) + (b5*t5));
	
	if (datos.x >= 0){
		cdf = w;
	} else {
		cdf = 1 - w;
	}
	
	return cdf;
}

/*****************************************************************************/
int main () {
	//Variables
	ValoresGaussiana datos_gaussiana;
	
	double x_final;
	
	double g_x;
	double cdf_integral;
	double cdf_aprox;
	
	const double SALTO = 0.25;
	
	bool salir = false;
	
	do {
		
		//Recogida de datos
			//Esperanza
			cout << "Introduzca el valor de la esperanza o media: ";
			cin >> datos_gaussiana.esperanza;
			
			//Desviación típica
			do {
				cout << "Introduzca el valor de la desviación típica (>= 0): ";
				cin >> datos_gaussiana.desviacion;
			} while (datos_gaussiana.desviacion <= 0);
			
			cout << endl;
		
		datos_gaussiana.x = datos_gaussiana.esperanza - 
		(3 * datos_gaussiana.desviacion);
		x_final = datos_gaussiana.esperanza + (3 * datos_gaussiana.desviacion);
		
		while (datos_gaussiana.x <= x_final){
			//Cálculos
			g_x = Gaussiana(datos_gaussiana);
			cdf_integral = CDF_Integral(datos_gaussiana);
			cdf_aprox = CDF_Aprox(datos_gaussiana);
			
			//Salida de datos
			cout << "x = " << datos_gaussiana.x << endl;
			cout << "\t" << "g(x) = " << g_x << endl;
			cout << "\t" << "CDF = " << cdf_integral << endl;
			cout << "\t" << "CDF aproximado = " << cdf_aprox << endl;
			cout << endl;
			
			datos_gaussiana.x += SALTO;
		}
		
		//¿Salida del programa?
		char opcion;
		
		do {
			cout << "¿Desea salir? (S/N): ";
			cin >> opcion;
			opcion = toupper (opcion);
			
			if (opcion == 'S'){
				salir = true;
			}
		} while (opcion != 'S' && opcion != 'N');
		
	} while (!salir); //Fin bucle programa
	
	return 0;
}
