/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 21 - II: Tomando como referencia la soluci�n al ejercicio 13 de 
	la segunda relaci�n de problemas, ahora usaremos un tipo enumerado que 
	nos permita guardar el tipo de car�cter de letra_original. Consideraremos
	que ahora podr�a ser: 
		a) Una letra may�scula, 
		b) Una letra min�scula, 
		c) Un d�gito 
		d) Otro car�cter.		
	
	las vocales con tilde (may�sculas y min�sculas) y las letras �, �, � y � 
	se englobar�n en la categor�a de otros por simplificar la soluci�n

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S

using namespace std;

enum class TipoCaracter 
		{mayuscula, minuscula, digito, otros};

int main () {	
	//Variables
		TipoCaracter tipo_caracter;
		
		char caracter_original;
		char letra_convertida;
		
		const int MAYUS_MINUS = 'a' - 'A';
		
	//Recogida de datos
		cout << "Introduzca un car�cter: ";
		cin >> caracter_original;
		
		cout << endl;
		
	//Comprobaciones
		if (caracter_original >= 'A' && caracter_original <= 'Z') {
			tipo_caracter = TipoCaracter::mayuscula;
			
		} else if (caracter_original >= 'a' && caracter_original <= 'z') {
			tipo_caracter = TipoCaracter::minuscula;

		} else if (caracter_original >= '0' && caracter_original <= '9') {
			tipo_caracter = TipoCaracter::digito;

		} else {
			tipo_caracter = TipoCaracter::otros;
			
		}
		
	//Salida por pantalla
		switch (tipo_caracter){
			case TipoCaracter::mayuscula:
				letra_convertida = caracter_original + MAYUS_MINUS;
				
				cout << "La letra era una may�scula. Una vez convertida es: "
					 << letra_convertida;
				break;
					 
			case TipoCaracter::minuscula:
				letra_convertida = caracter_original - MAYUS_MINUS;
				
				cout << "La letra era una min�scula. Una vez convertida es: "
					 << letra_convertida;
				break;

			case TipoCaracter::digito:
				cout << "El car�cter introducido es un d�gito";
				break;
					 
			case TipoCaracter::otros:
				cout << "El car�cter introducido no es ni una letra ni un "
					 << "d�gito";
				break;

		}

	return 0;
}
