/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 20 - II: Este programa leer� el valor de la edad (dato de tipo 
	entero) y salario (dato de tipo real) de una persona. 
		- Se subir� el salario un 4% si es mayor de 65 o menor de 35 a�os. 
		- Si adem�s de cumplir la anterior condici�n, tambi�n tiene un salario 
		  inferior a 300 euros, se le subir� otro 3 %, mientras que si su 
		  salario es mayor o igual que 300 euros pero inferior a 900 euros se 
		  le subir� un s�lo el 1.5 %.
		  
	El resultado se imprimir� por pantalla indicando qu� subidas se han 
	aplicado

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S

using namespace std;

enum class Aumento 
		{no_aumento, aum_edad, aum_edad_salario_bajo, aum_edad_salario_medio};

int main () {	
	//Variables
		Aumento aumento;
		
		double porcentaje = 100;
		double porcentaje_aumento;
		
		const double AUMENTO_EDAD = 4;
		const double AUMENTO_SALARIO_BAJO = 3;
		const double AUMENTO_SALARIO_MEDIO = 1.5;
		
		
		int edad;
		double salario_base, salario_final;
		
	//Recogida de datos
		cout << "Introduzca la edad del trabajador: ";
		cin >> edad;
		
		cout << "Introduzca el salario actual del trabajador: ";
		cin >> salario_base;
		
		cout << endl;
		
	//Comprobaciones
		if (edad > 65 || edad < 35){
			if (salario_base < 300){
				aumento = Aumento::aum_edad_salario_bajo;
				porcentaje_aumento = AUMENTO_EDAD + AUMENTO_SALARIO_BAJO;
				
			} else if (salario_base >= 300 && salario_base < 900){
				aumento = Aumento::aum_edad_salario_medio;
				porcentaje_aumento = AUMENTO_EDAD + AUMENTO_SALARIO_MEDIO;
				
			} else {
				aumento = Aumento::aum_edad;
				porcentaje_aumento = AUMENTO_EDAD;
				
			}
			
		} else {
			aumento = Aumento::no_aumento;
			porcentaje_aumento = 0;
			
		}
		//C�lculos
			porcentaje = porcentaje + porcentaje_aumento;
			
			salario_final = (salario_base * porcentaje) / 100;
			
		//Mostramos el resultado por pantalla
		switch (aumento){
			case Aumento::no_aumento:
				cout << "No se cumple ninguna condici�n para el "
					 << "aumento de salario";
				break;
			
			case Aumento::aum_edad:
				cout << "S�lo se aplicar� un aumento del " << AUMENTO_EDAD
					 << "% relacionado con la edad" << endl;
				break;
			
			case Aumento::aum_edad_salario_bajo:
				cout << "Se aplicar� un aumento del " << AUMENTO_EDAD
					 << "% relacionado con la edad y un aumento del "
					 << AUMENTO_SALARIO_BAJO << "% relacionado con un salario"
					 << " bajo; en total ser� un aumento del "
					 << porcentaje_aumento << "%" << endl;
				break;
				
			case Aumento::aum_edad_salario_medio:
				cout << "Se aplicar� un aumento del " << AUMENTO_EDAD
					 << "% relacionado con la edad y un aumento del "
					 << AUMENTO_SALARIO_MEDIO << "% relacionado con un salario"
					 << " medio; en total ser� un aumento del "
					 << porcentaje_aumento << "%" << endl;
				break;
				
		}
		
		cout << endl << "El salario final ser� de " << salario_final
			 << " euros";

	return 0;
}
