/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 21 - II: Tomando como referencia la solución al ejercicio 13 de 
	la segunda relación de problemas, ahora usaremos un tipo enumerado que 
	nos permita guardar el tipo de carácter de letra_original. Consideraremos
	que ahora podría ser: 
		a) Una letra mayúscula, 
		b) Una letra minúscula, 
		c) Un dígito 
		d) Otro carácter.		
	
	las vocales con tilde (mayúsculas y minúsculas) y las letras ú, Ü, ñ y Ñ 
	se englobarán en la categoría de otros por simplificar la solución

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S

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
		cout << "Introduzca un carácter: ";
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
				
				cout << "La letra era una mayúscula. Una vez convertida es: "
					 << letra_convertida;
				break;
					 
			case TipoCaracter::minuscula:
				letra_convertida = caracter_original - MAYUS_MINUS;
				
				cout << "La letra era una minúscula. Una vez convertida es: "
					 << letra_convertida;
				break;

			case TipoCaracter::digito:
				cout << "El carácter introducido es un dígito";
				break;
					 
			case TipoCaracter::otros:
				cout << "El carácter introducido no es ni una letra ni un "
					 << "dígito";
				break;

		}

	return 0;
}
