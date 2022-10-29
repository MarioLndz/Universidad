/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 18 - II: Este programa realizará la conversión entre dos 
	unidades de distancia del SI. Las unidades contempladas serán: 
	mm (milímetros), cm (centímetros), m (metros) y km (kilómetros).
	
	El programa mostrará el prompt ">" y el usuario escribirá cuatro tokens:
			"valor unidad_inicial a unidad_final"
	y el programa mostrará el resultado de la transformación

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>	  // Inclusión de los recursos matemáticos
#include <string>
#include <iomanip>

using namespace std;

int main () {	
	//Variables
		double valor;
		string unidad_inicial;
		char a;
		string unidad_final;
		
		double valor_final;
	
	//Constantes
		const double mm_a_m = 1./1000;		// 1 m = 1000 mm
		const double cm_a_m = 1./100;		// 1 m = 100 cm
		const double km_a_m = 1000/1;		// 1000 m = 1 km
		
		const double m_a_mm = 1000/1;		// 1000 mm = 1 m
		const double m_a_cm = 100/1;		// 100 cm = 1 m
		const double m_a_km = 1./1000;		// 1 km = 1000 m
		
	//Explicación de uso
		cout << "Introduzca los datos segun el siguiente formato:" << endl;
		cout << "\t valor unidad_inicial a unidad_final" << endl;
		cout << "Las unidades contempladas serán: mm (milímetros), "
			 << "cm (centímetros), m (metros) y km (kilómetros)" << endl;
		
	//Recogida de datos
		cout << endl << "> ";
		cin >> valor >> unidad_inicial >> a >> unidad_final;
		
	//Comprobamos si los tokens están correctamente escritos
		bool datos_ok = false;
		bool valor_ok = valor > 0;
		
		bool unidad_inicial_ok 	= unidad_inicial == "mm" ||
								  unidad_inicial == "cm" ||
								  unidad_inicial == "m"  ||
								  unidad_inicial == "km";
								 
		bool a_ok = (a == 'a');
								 
		bool unidad_final_ok 	= unidad_final == "mm" ||
								  unidad_final == "cm" ||
								  unidad_final == "m"  ||
								  unidad_final == "km";
		datos_ok = valor_ok && unidad_inicial_ok && a_ok && unidad_final_ok;
		
	//Programa
		double conversion_inicial = 1;
		double conversion_final = 1;
		
		if (datos_ok){
			/* ****************************************************************
			Para realizar la conversión, primero pasaré el valor a metros
			usando el factor de conversión correspondiente, y después paso
			esos metros a la unidad final introducida, siguiendo de nuevo los
			factores de conversión establecidos. Es por ello que solo deberé
			comprobar los casos en los que la unidad inicial o final no sean
			metros, pues en ese caso no habrá que hacer conversion alguna.
			**************************************************************** */
			
			//Paso de la unidad_inicial a metros
			if (unidad_inicial == "mm"){
				conversion_inicial = mm_a_m;
				
			} else if (unidad_inicial == "cm") {
				conversion_inicial = cm_a_m;
				
			} else if (unidad_inicial == "km") {
				conversion_inicial = km_a_m;
				
			}
			
			//Paso de los metros a la unidad_final
			if (unidad_final == "mm"){
				conversion_final = m_a_mm;
				
			} else if (unidad_final == "cm") {
				conversion_final = m_a_cm;
				
			} else if (unidad_final == "km") {
				conversion_final = m_a_km;
				
			}
			
			//Cálculos
			valor_final = valor * conversion_inicial * conversion_final;
			
			//Mostramos el valor por pantalla
			cout << fixed << setprecision(3) << setw(10);
			cout << valor << " " << unidad_inicial << " = " << valor_final 
				 << " " << unidad_final;
			
		} else {	//ERROR
			if (!valor_ok){
				cout << "ERROR: Se ha introducido un valor incorrecto" << endl;
			}	
			if (!unidad_inicial_ok){
				cout << "ERROR: No se ha introducido correctamente la unidad "
					 << "inicial" << endl;
			}
			if (!a_ok){
				cout << "ERROR: No se ha introducido correctamente el carácter"
					 << " 'a'" << endl;
			}
			if (!unidad_final_ok){
				cout << "ERROR: No se ha introducido correctamente la unidad "
					 << "final" << endl;
			}
		}
		
	return 0;
}
