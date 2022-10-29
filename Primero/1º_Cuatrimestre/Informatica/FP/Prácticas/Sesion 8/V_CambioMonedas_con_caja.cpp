/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 6 - V: Este programa leer� el total a pagar y la cantidad pagada 
	(se supone que cantidad pagada >= total a pagar) e indicar� el 
	n�mero de monedas de 2 euros, 1 euro, 50 c�ntimos, 20 c�ntimos, 
	10 c�ntimos, 5 c�ntimos, 2 c�ntimos y 1 c�ntimo que se deben dar de cambio. 
	Se indicar� el menor n�mero de monedas de cada clase
	
	Adem�s se considerar�n las monedas disponibles en la caja, de manera que si 
	no hay monedas de un determinado valor, se debr� suplir usando unidades de 
	valor inferior.
	Se tendr� incluso en cuenta la contingencia de no disponer de 
	suficiente cambio
	
	NOTA: Por comodidad, se inciar� expl�citamente el contenido de la caja.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

/*****************************************************************************
//	STRUCTS
******************************************************************************/
struct Cambio {
	double cambio;			//Dinero que falta por pagar
	int monedas_restantes;	//Monedas que nos han sobrado
	int monedas_gastadas;	//Monedas usadas para pagar
};

/*****************************************************************************
//	FUNCIONES
******************************************************************************/
/*****************************************************************************
// 	EliminaPrimerosSeparadores
	
	Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
	separadores de "cadena". Los caracteres separadores son el espacio en 
	blanco, el tabulador y el salto de línea. 
	Usaremos la funci�n isspace() para simplificar el c�lculo. 
 
	RECIBE:  cadena, string sobre la que se va a trabajar.
	DEVUELVE: el resultado de eliminar los primeros separadores de "cadena".
*****************************************************************************/
string EliminaPrimerosSeparadores (string cadena)
{	
	// Buscar el primer car�cter no espacio
	int pos = 0;
	while (pos < (int)cadena.length() && isspace(cadena.at(pos))) pos++;

	string local; 
	
	// Copiar todos los que quedan
	while (pos < (int)cadena.length()) {
		local.push_back(cadena.at(pos));
		pos++;
	}
		
	return (local);
}

/*****************************************************************************
//	EliminaUltimosSeparadores
	
	Devuelve una NUEVA cadena, resultante de eliminar los últimos caracteres 
	separadores de "cadena". Los caracteres separadores son el espacio en 
	blanco, el tabulador y el salto de l�nea. 
	Usaremos la funci�n isspace() para simplificar el c�lculo. 
	 
	Recibe: cadena, string sobre la que se va a trabajar.
	Devuelve: el resultado de eliminar los �ltimos separadores de "cadena".
*****************************************************************************/
string EliminaUltimosSeparadores (string cadena)
{
   	while (cadena.length()>0 && isspace(cadena.back()))
		cadena.pop_back();
        
	return (cadena);
}

/*****************************************************************************
//	EsNumero

	Se comprobar� si el string introducido est� formado por un n�mero real
	
	RECIBE: String a comprobar
	DEVUELVE: Verdadero o Falso
*****************************************************************************/
bool EsNumero (string cadena){
	bool es_numero = true;
	
	cadena = EliminaPrimerosSeparadores (cadena);
	cadena = EliminaUltimosSeparadores  (cadena);
	
	int longitud = cadena.length();
	
	//Primero comprobaremos que la cadena no est� vac�a o que solo est� formada
	//por la coma decimal
	if (cadena == "." || cadena == "" || cadena == "-" || cadena == "+"){
		es_numero = false;
	} else {
		int n = 0;
		int coma_decimal = 0;
		
		//Comprueba que toda la cadena est� formada por d�gitos (con decimales)
		//si la cadena empieza con un signo, pasar� al siguiente caracter
		if (cadena.at(0) == '-' || cadena.at(0) == '+'){
			n++;
		}
		
		while (n < longitud && es_numero) {
			//Comprobamos c�mo est� formada la cadena. Si encontramos una coma
			//decimal, la registramos en un contador. Si no, comprobamos que
			//el car�cter es un d�gito. Si no fuera un d�gito o si hubiera
			//m�s de una coma decimal devolveremos FALSE
			if (cadena.at(n) == '.'){
				coma_decimal++;
			} else if (cadena.at(n) < '0' || cadena.at(n) > '9'){
				es_numero = false;
			}
			
			if (coma_decimal > 1){
				es_numero = false;
			}
			
			n++;
		}
	}
	return es_numero;
}

/*****************************************************************************
//	DevuelveCambio

	Esta funci�n recibir� una cantidad de dinero a pagar en centimos, el tipo
	de moneda con el que se quiere pagar y la cantidad de monedas de las que
	se dispone y devolver�n la cantidad de monedas que se han usado, las que
	han sobrado y el cambio.
	
	RECIBE: Precio, Precio de la moneda, N�mero de monedas disponibles
	DEVUELVE: Cambio (falta por pagar), N� monedas restantes, N� monedas usadas
	PRE: El precio deber� estar expresado en centimos
*****************************************************************************/
Cambio DevuelveCambio (double total, int valor_moneda, int num_monedas){
	Cambio cambio;
	cambio.cambio = total;
	
	int monedas_min = total/valor_moneda;	//Monedas m�nimas que necesito
	
	if (monedas_min == 0){
		cambio.monedas_restantes = num_monedas;
		cambio.monedas_gastadas = 0;
	} else {
		//Diferencia entre las que tengo y las que necesito
		int diferencia = monedas_min - num_monedas;
		
		if (diferencia >= 0){	//Si necesito m�s de lo que tengo
			cambio.cambio -= (num_monedas * valor_moneda);
			cambio.monedas_restantes = 0;
			cambio.monedas_gastadas = num_monedas;
			
		} else {	//Si tengo m�s de lo que necesito
			cambio.cambio -= (monedas_min * valor_moneda);
			cambio.monedas_restantes = abs(diferencia);
			cambio.monedas_gastadas = monedas_min;
		}
	}
	
	return cambio;
}


/*****************************************************************************/
int main () {
	//Variables
	string total_str, pagado_str;
	double total, pagado;
	
	Cambio cambio;
	
	//Arrays
	const int TIPOS_MONEDAS = 8;
	
	int caja[TIPOS_MONEDAS];
	int valor[TIPOS_MONEDAS];
	caja[0] = 5; 	// Monedas de 
	valor[0] = 1;	// 1 cent
	
	caja[1] = 0; 	// Monedas de
	valor[1] = 2;	// 2 cent
	
	caja[2] = 0; 	// Monedas de
	valor[2] = 5;	// 5 cent
	
	caja[3] = 2; 	// Monedas de
	valor[3] = 10;	// 10 cent
	
	caja[4] = 4; 	// Monedas de
	valor[4] = 20;	// 20 cent
	
	caja[5] = 0; 	// Monedas de
	valor[5] = 50;	// 50 cent
	
	caja[6] = 2; 	// Monedas de
	valor[6] = 100;	// 1 euro = 100 cent
	
	caja[7] = 2; 	// Monedas de 
	valor[7] = 200;	// 2 euros = 200 cent
	
	int monedas_gastadas[TIPOS_MONEDAS];
		
	//ENTRADA
	do {
		cout << "Introduzca el precio a pagar en euros: ";
		cin >> total_str;
	} while (!EsNumero(total_str));
	
	total = stod(total_str) * 100;
	
	do {
		cout << "Introduzca el dinero usado para pagar: ";
		cin >> pagado_str;
	} while (!EsNumero(pagado_str));
	
	pagado = stod(pagado_str) * 100;
		
	//C�LCULOS
	double cambio_inicial = pagado - total;
	double falta_por_pagar = cambio_inicial;
	
	cambio_inicial /= valor[6];
	
	for (int i = (TIPOS_MONEDAS - 1); i >= 0; i--){
		int valor_moneda = valor[i];
		int tipo_moneda = caja[i];
		cambio = DevuelveCambio(falta_por_pagar, valor_moneda, tipo_moneda);
		
		//Pasamos cada dato "temporal" del struct a sus respectivas variables
		monedas_gastadas[i] = cambio.monedas_gastadas; 
		caja[i] = cambio.monedas_restantes; //Actualizamos la caja con las 
											//monedas restantes
		falta_por_pagar = cambio.cambio;
	}
	
	bool cambio_completo = false;
	if (falta_por_pagar == 0){
		cambio_completo = true;
	}
	
	//SALIDA
	cout << endl;
	cout << "Se tienen que devolver " << cambio_inicial << " euros" 
		 << endl;
	
	if (cambio_completo){
		cout << endl;
		cout << "Se dar� de cambio:" << endl;
		cout << "\t" << setw(2) << monedas_gastadas[7] << " monedas de " 
			 << setw(2) << "2" << setw(5) << " euros" << endl;
			 
		cout << "\t" << setw(2) << monedas_gastadas[6] << " monedas de " 
			 << setw(2) << "1" << setw(5) << " euro" << endl;
			 
		cout << "\t" << setw(2) << monedas_gastadas[5] 
			 << " monedas de " << setw(2) << "50" << setw(5) << " cents" 
			 << endl;
			 
		cout << "\t" << setw(2) << monedas_gastadas[4] 
			 << " monedas de " << setw(2) << "20" << setw(5) << " cents" 
			 << endl;
			 
		cout << "\t" << setw(2) << monedas_gastadas[3] 
			 << " monedas de " << setw(2) << "10" << setw(5) << " cents" 
			 << endl;
			 
		cout << "\t" << setw(2) << monedas_gastadas[2] 
			 << " monedas de " << setw(2) << "5" << setw(5) << " cents" 
			 << endl;
			 
		cout << "\t" << setw(2) << monedas_gastadas[1] 
			 << " monedas de " << setw(2) << "2" << setw(5) << " cents" 
			 << endl;
			 
		cout << "\t" << setw(2) << monedas_gastadas[0] 
			 << " monedas de " << setw(2) << "1" << setw(5) << " cents" 
			 << endl;
	} else {
		cout << endl;
		cout << "No se dispone del suficiente cambio" << endl;
	}
	
	return 0;
}
