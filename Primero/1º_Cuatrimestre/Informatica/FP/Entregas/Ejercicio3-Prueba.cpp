/*

Mario L�ndez Mart�nez
Ejercicio 1 - Ley de Ohm

*/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos
using namespace std;

int main () { // Programa Principal
	int salario_base; 
	int salario_final; 
	int incremento; 
	
	salario_base = 1000; 
	salario_final = salario_base; 
	incremento = 200; 
	
	salario_final = salario_final + incremento; 
	salario_base = 3500; 
	
	cout << endl; 
	cout << "Salario base: " << salario_base << endl; 
	cout << "Salario final: " << salario_final << endl;
 	
   return 0;
}
