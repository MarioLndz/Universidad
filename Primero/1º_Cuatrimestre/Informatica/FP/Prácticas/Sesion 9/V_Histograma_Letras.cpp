/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 36 - V: Este programa leer� una serie indefinida de caracteres
	de la entrada est�ndar (terminados por *) y mostrar� el histograma que
	representa la frecuencia de las letras introducidas.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>
#include <iomanip>

using namespace std;

/*****************************************************************************
//	EsCaracterEspecialEspaniol
		
	RECIBE: Caracter "c"
	DEVUELVE: "true" si "c" es un caracter especial del alfabeto espa�ol
*****************************************************************************/
bool EsCaracterEspecialEspaniol (unsigned char c){
	
	//		 � -> 160	   � -> 130		 � -> 161	   � -> 162
	return ((c == 160) || (c == 130) || (c == 161) || (c == 162) ||
	
	//	     � -> 163	   � -> 129		 � -> 164
			(c == 163) || (c == 129) ||	(c == 164) ||
	
	//		 � -> 181	   � -> 144		 � -> 214	   � -> 224
			(c == 181) || (c == 144) || (c == 214) || (c == 224) ||
			
	//		 � -> 233	   � -> 154		 � -> 165
			(c == 233) || (c == 154) || (c == 165));
			
}

/****************************************************************************
//	TransformaCaracterEspecialEspaniol
	
	Transforma un car�cter especial "c" a sus correspondientes est�ndar.
	Si el car�cter no es un caracter especial no se hara ninguna transformacion
	
	caracteres especiales y su transformacion:
	� --> a  	� --> e  	� --> i  	� --> o  	� --> u  	� --> u 
	� --> n
*****************************************************************************/
char TransformaCaracterEspecialEspaniol (unsigned char c) 
{
	char nuevo; 
	
	switch (c) {
		case (160):
		case (181): 	// � / � --> a
			nuevo = 'a'; 
			break;
			  
		case (130):
		case (144): 	// � / � --> e
			nuevo = 'e'; 	
			break; 
			
		case (161):
		case (214): 	// � / � --> i
			nuevo = 'i'; 
			break;
			 
		case (162):
		case (224): 	// � / � --> o
			nuevo = 'o'; 
			break;
			 
		case (163): 	
		case (129):
		case (233):
		case (154): 	// � / � / � / � --> u
			nuevo = 'u'; 
			break; 
			
		case (164):
		case (165): 	// � / � --> n
			nuevo = 'n'; 
			break; 
			
		default: 	
			nuevo = c; 
			break; 	
				 	
	}
	
	return (nuevo);
}

/*****************************************************************************/
/*****************************************************************************/
int main () {	
	// Numero de caracteres a considerar
	const int NUM_CARACTERES = 'z' - 'a' + 1;
	char las_letras [NUM_CARACTERES]; // Letras a procesar
	
	//Inicializo las letras del abecedario
	for (int n = 0; n < NUM_CARACTERES; n++){
		las_letras[n] = 'a' + n;
	}
	
	int veces_letras[NUM_CARACTERES] = {0}; // Contadores
	
	// Dimensiones del tablero de dibujo
	const int NUM_FILAS = 10; // N�m. de filas
	const int NUM_COLS = NUM_CARACTERES; // N�m. de columnas
	char histograma [NUM_FILAS][NUM_COLS];
	
	char c;
	const char TERMINADOR = '*';
	
	//-------------------------------------
	//	ENTRADA
	
	//Leeremos y contaremos los datos hasta que se introduzca el terminador
	cin >> c;
	
	while (c != TERMINADOR){
		c = tolower(c);
		
		if ((c >= 'a' && c <= 'z') || EsCaracterEspecialEspaniol(c)){
			c = TransformaCaracterEspecialEspaniol(c);
		
			veces_letras[(c - 'a')]++;
		}
		
		cin >> c;
		
	}
	
	//-------------------------------------
	//	CALCULOS
	
	//Comprobamos cual es la mayor frecuencia de una letra
	int frecuencia_mayor = 0;
	
	for (int n = 0; n < NUM_CARACTERES; n++){
		if (veces_letras[n] > frecuencia_mayor){
			frecuencia_mayor = veces_letras[n];
		}
	}
	
	int base = 0;
	int casillas_entre_unidad = 0;
	
	while (casillas_entre_unidad < 1) {
		base++;
		casillas_entre_unidad = base * (NUM_FILAS/(double)frecuencia_mayor);
	}
	
	
	int asteriscos_sobrantes = NUM_FILAS - 
		  					   (frecuencia_mayor * casillas_entre_unidad);
	//Inicializacion del histograma
	for (int n = 0; n < NUM_FILAS; n++){
		for (int i = 0; i < NUM_COLS ; i++){
			histograma[n][i] = '.';
		}
	}
	
	//Calculo y formacion del histograma
	int i = 0;
	for (int col = 0; col < NUM_COLS; col++){
		int fila = NUM_FILAS - 1;
		
		int max_fila_con_asterisco = 
			(base*NUM_FILAS) - (casillas_entre_unidad * veces_letras[i]);
		
		//Pintamos los asteriscos de abajo a arriba
		while (fila >= (max_fila_con_asterisco/base)){
			histograma[fila][col] = '*';
			fila--;
			
		}
		
		i++;	//Letra siguiente
	}
	
	//-------------------------------------
	//	SALIDA
	
	//Mostramos la mitad de letras (hasta la letra m)
	for (int n = 0; n < (NUM_CARACTERES/2); n++){
		cout << setw(3) << las_letras[n] << " ";
	}
	cout << endl;
	
	for (int n = 0; n < (NUM_CARACTERES/2); n++){
		cout << setw(3) << veces_letras[n] << " ";
	}
	cout << endl << endl;
	
	//Mostramos el resto de las letras
	for (int n = 13; n < NUM_CARACTERES; n++){
		cout << setw(3) << las_letras[n] << " ";
	}
	cout << endl;
	
	for (int n = 13; n < NUM_CARACTERES; n++){
		cout << setw(3) << veces_letras[n] << " ";
	}
	cout << endl << endl;
	
	//Mostramos el histograma. Para el borde izquierdo seguiremos el siguiente
	//razonamiento: Haremos la comprobacion considerando que la fila 0 de la
	//matriz interna sera la fila 30 de nuestra matriz. Teniendo esto en 
	//cuenta, solo mostraremos el valor de esa fila cuando sea un resultado
	//exacto teniendo en cuenta el valor que tiene cada casilla
	//
	//Ejemplo --> Si una unidad equivale a 4 casillas, la fila mostrara su valor
	// si el numero de fila es 4n = fila, o lo que es lo mismo --> 
	//fila%4 = 0 y valor de la fila = fila/4
	int borde_izqdo = NUM_FILAS;
	
	for (int i = 0; i < NUM_FILAS; i++){
		if (i >= asteriscos_sobrantes &&
			(borde_izqdo % casillas_entre_unidad == 0)){
				cout << setw(4) << base * (borde_izqdo/casillas_entre_unidad)  
					 << " ";
				
		} else {
			cout << setw(5) << " ";
		}
		cout << "| ";
		
		for (int n = 0; n < NUM_COLS; n++){
			cout << histograma[i][n] << " ";
		}
		cout << endl;
		borde_izqdo--;
	}
	
	cout << setw(5) << " "; 
	for (int n = 0; n < (NUM_CARACTERES*2) + 1; n++){
		cout << "-";
	}
	
	cout << endl;
	cout << setw(7) << " ";
	for (int n = 0; n < NUM_CARACTERES; n++){
		cout << las_letras[n] << " ";
	}
	cout << endl;
	
	return 0;
}
