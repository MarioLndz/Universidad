/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 82 - II: Este programa implementará dos formas de aproximar
	la raíz cuadrada de un número, compararemos los resultados junto al valor
	real de dicha raíz. Los métodos a comparar son:
		- Aproximación simple de raíces cuadradas con decimales
		- Aproximación a partir de la proporcionalidad entre triángulos

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
	cout.setf(ios::fixed);
	
	double x;
	
	do{
		cout << "Inserte un numero (debe ser mayor o igual a 0): ";
		cin >> x;
		
	} while (x < 0);
	
	bool primer_numero = true;
	
	do {
		/* ************************************************************
			Aproximación simple de ráices con decimales - Forma 1
		************************************************************** */
		//Variables
		double resultado_forma_1;
		int aprox_abajo, aprox_arriba; 
		double aprox = 0;
		double diferencia;
		double aprox_cuadrado = -1;

		//Cálculos
		while (aprox_cuadrado < x){
			aprox_cuadrado = pow (aprox, 2);
			
			aprox_arriba = aprox;
			aprox++;
			
		}
		
		aprox_abajo = aprox_arriba - 1;
		
		double aprox_abajo_cuadrado = pow (aprox_abajo, 2);
		double aprox_arriba_cuadrado = pow (aprox_arriba, 2);
		
		double diferencia_abajo = x - aprox_abajo_cuadrado;
		double diferencia_arriba = x - aprox_arriba_cuadrado;
		
		if (abs(diferencia_abajo) <= abs(diferencia_arriba)){
			aprox = aprox_abajo;
			diferencia = diferencia_abajo;
			aprox_cuadrado = aprox_abajo_cuadrado;
			
		} else {
			aprox = aprox_arriba;
			diferencia = diferencia_arriba;
			aprox_cuadrado = aprox_arriba_cuadrado;
			
		}
		bool error_forma_1 = false;
		
		if (aprox != 0){
		resultado_forma_1 = aprox + (diferencia/(aprox*2.0));
			
		} else {
			error_forma_1 = true;
		}
		
		/* ***************************************************************
			Aproximación a partir de la proporcionalidad entre triángulos
		****************************************************************** */	
		//Usaremos el teorema de tales para realizar la aproximación
		
		//Variables
		double base_triangulo;
		base_triangulo = aprox_arriba_cuadrado - aprox_abajo_cuadrado;
		double altura_triangulo = aprox_arriba - aprox_abajo;
		
		double base_triangulo_menor = x - aprox_abajo_cuadrado;
		double altura_triangulo_menor;
		
		double resultado_forma_2;
		
		//Cálculos
		altura_triangulo_menor = (altura_triangulo/base_triangulo) * 
								 base_triangulo_menor;
		
		resultado_forma_2 = altura_triangulo_menor + aprox_abajo;
		
			
		/* ***************************************************************
			Aproximación con sqrt
		****************************************************************** */
		double resultado_forma_3 = sqrt (x);
		
		//Salida de datos
		if (primer_numero){
			x = -0.5;
			primer_numero = false;
			
			cout << "El resultado con el método 1 es " << resultado_forma_1;
			cout << endl;
			cout << "El resultado con el método 2 es " << resultado_forma_2;
			cout << endl;
			cout << "El resultado real es " << resultado_forma_3 << endl;

			cout << endl;
			cout << "============\t============\t============\t============"; 
			cout << endl;
			cout << "|  Número  |\t| Método 1 |\t| Método 2 |\t|Valor real|";
			cout << endl;
			cout << "============\t============\t============\t============";
			cout << endl;
			
		} else {
			int valor_setw = 8;
			
			cout << setprecision(3) << setw(valor_setw);
			cout << x;
			
			if (!error_forma_1){
				cout << "\t";
				cout << setprecision(3) << setw(valor_setw);
				cout << resultado_forma_1;
			} else {
				cout << "\t";
				cout << setprecision(3) << setw(valor_setw);
				cout << "ERROR";
			}
			
			cout << "\t";
			cout << setprecision(3) << setw(valor_setw);
			cout << resultado_forma_2;
			
			cout << "\t";
			cout << setprecision(3) << setw(valor_setw);
			cout << resultado_forma_3 << endl;
			
			cout << "------------\t------------\t------------\t------------";
			cout << endl;
			
		}
		
		x += 0.5;
		
	} while (x <= 16);
	
	return 0;
}

