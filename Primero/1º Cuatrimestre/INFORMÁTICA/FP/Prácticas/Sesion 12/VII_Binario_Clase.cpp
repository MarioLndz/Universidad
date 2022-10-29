/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 6 - VII: Implementar una clase que nos permita trabajar con datos 
	binarios (la clase Bin) y realizar las operaciones básicas típicas sobre 
	éstos.

******************************************************************************/

#include <iostream>	// Inclusión de los recursos de E/S
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Bin {
private:
	unsigned int valor_bin;		//PRE: 0 <= valor_bin < (2^32) - 1
public:
	/*****************************************************************/
	//	Constructores
	
	//-------------------------
	//	Constructor vacio
	
	Bin ()
		:	valor_bin (0)
	{}
	
	//-------------------------
	//	Constructor a partir de un valor decimal
	
	Bin (unsigned int el_valor)
		:	valor_bin (el_valor)
	{}
	
	//-------------------------
	//	Constructor a partir de un string
	//	PRE: La cadena debe contener un dato en binario (debe estar formada por
	//		 0 y 1)
	Bin (string el_valor_inicial)
	{
		valor_bin = BinToDec(el_valor_inicial);
	}
	
	/*****************************************************************/
	//	Metodos SET
	
	//-------------------------	
	//	Metodo SET a partir de un valor decimal
	void SetValor (unsigned int el_valor){
		valor_bin = el_valor;
	}
	//-------------------------	
	//	Metodo SET a partir de un numero binario
	void SetValor (string el_valor){
		valor_bin = BinToDec(el_valor);
	}
	
	/*****************************************************************/
	//	Metodos GET
	
	//-------------------------	
	//	Metodo GET, devuelve el valor decimal
	unsigned int GetValorDecimal (){
		return valor_bin;
	}
	
	/*****************************************************************/
	//	Metodos para representar el numero
	
	//-------------------------	
	//	Forma una cadena con el dato en binario
	string ToString (int num_bits){
		string binario = DecToBin(valor_bin, num_bits);
		
		return binario;
	}
	
	/*****************************************************************/
	//	Calculos
	
	//-------------------------	
	//	Devuelve el minimo numero de bits necesarios para representar el numero
	int MinNumBits () {
		int num_bits = 0;
		unsigned int num_decimal = valor_bin;
		
		if (num_decimal == 0){
			num_bits = 1;
			
		} else {
			while (num_decimal > 0){
				num_decimal = num_decimal/2;
				
				num_bits++;
			}
		}
		
		return num_bits;
	}
	
	//-------------------------	
	//	Se sumara el valor del objeto con el valor de otro objeto tipo Bin
	//	PRE: La suma debe ser 0 <= suma < (2^32) - 1
	Bin Suma (Bin otro){		
		return Bin(valor_bin + otro.valor_bin);
		
	}
	//-------------------------	
	//	Se resta el objeto explícito y el objeto implícito
	// POST: No se daran resultados negativos, por lo que siempre se realizara
	//		 la resta del menor al mayor
	Bin Resta (Bin otro){
		unsigned int mayor, menor;
		
		if (valor_bin > otro.valor_bin){
			mayor = valor_bin;
			menor = otro.valor_bin;
		} else {
			mayor = otro.valor_bin;
			menor = valor_bin;
		}
		
		return Bin(mayor - menor);
	}
	//-------------------------	
	//	Realiza la operación AND:
	//		1 and 1 = 0
	//		1 and 0 = 0
	//		0 and 0 = 0
	//	Devuelve un nuevo objeto tipo Bin
	Bin AND (Bin otro){
		return Bin(valor_bin & otro.valor_bin);
		
	}
	//-------------------------	
	//	Realiza la operación OR:
	//		1 or 1 = 1
	//		1 or 0 = 1
	//		0 or 0 = 0
	// Devuelve un nuevo objeto tipo Bin
	Bin OR (Bin otro){
		return Bin(valor_bin | otro.valor_bin);
	}
	
	//-------------------------	
	//	Desplaza el número n bits a la derecha
	//	Devuelve un nuevo objeto tipo Bin
	// 	PRE: el resultado no puede ser mayor a (2^32) - 1
	Bin DespDcha (int veces){
		return Bin(valor_bin >> veces);
	}
	
	//-------------------------	
	//	Desplaza el número n bits a la izquierda
	//	Devuelve un nuevo objeto tipo Bin
	// 	PRE: el resultado no puede ser mayor a (2^32) - 1
	Bin DespIzda (int veces){
		return Bin(valor_bin << veces);
	}
	
private:
	//-------------------------	
	//	Transforma una cadena de binario a decimal
	//	PRE: La cadena tiene que estar formada únicamente de 0 y 1
	unsigned int BinToDec (string cad){
		unsigned int decimal = 0;
		double pot_2;
		double longitud = cad.length();
		double exponente = longitud - 1;
		
		for (int i = 0; i < longitud; i++){
			pot_2 = pow(2, exponente);
		 	
			if (cad.at(i) == '1'){
				decimal += pot_2;
			}
			exponente--;
		}
	
		return decimal;
	}
	
	//-------------------------
	//	Transforma el valor a binario (en forma de string), ocupando como 
	//	mínimo x numero de bits
	string DecToBin (unsigned int num_decimal, int num_bits){
		string binario;
		int resto;
		
		if(num_decimal == 0){
			binario = "0";
		}
		
		while (num_decimal>0) {
			resto = num_decimal%2;
			num_decimal = num_decimal/2;
			
			if (resto == 0){
				binario = "0" + binario;
			} else {
				binario = "1" + binario;
			}
		}
		
		//Añadimos ceros hasta ocupar los bits indicados
		for (int longitud = binario.length(); longitud < num_bits; longitud++){
			binario = "0" + binario;
		}
	
		return binario;
	}		
	
};
/*****************************************************************************
// 	EliminaPrimerosSeparadores
	
	Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
	separadores de "cadena". Los caracteres separadores son el espacio en 
	blanco, el tabulador y el salto de lÃ­nea. 
	Usaremos la función isspace() para simplificar el cálculo. 
 
	RECIBE:  cadena, string sobre la que se va a trabajar.
	DEVUELVE: el resultado de eliminar los primeros separadores de "cadena".
*****************************************************************************/
string EliminaPrimerosSeparadores (string cadena)
{	
	// Buscar el primer carácter no espacio
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
	
	Devuelve una NUEVA cadena, resultante de eliminar los Ãºltimos caracteres 
	separadores de "cadena". Los caracteres separadores son el espacio en 
	blanco, el tabulador y el salto de línea. 
	Usaremos la función isspace() para simplificar el cálculo. 
	 
	Recibe: cadena, string sobre la que se va a trabajar.
	Devuelve: el resultado de eliminar los últimos separadores de "cadena".
*****************************************************************************/
string EliminaUltimosSeparadores (string cadena)
{
   	while (cadena.length()>0 && isspace(cadena.back()))
		cadena.pop_back();
        
	return (cadena);
}

/****************************************************************************
//	EsBinario

	Comprobará si una cadena representa un dato en binario
	
	RECIBE: cadena con dato binario
	DEVUELVE: true o false
****************************************************************************/
bool EsBinario (string cadena){
	bool es_binario = true;
	
	int pos = 0;
	int longitud = cadena.length();
	
	while(es_binario && pos < longitud){
		if(cadena.at(pos) != '0' && cadena.at(pos) != '1'){
			es_binario=false;
		}
		
		pos++;
	}
		
	return es_binario;
}

/****************************************************************************
//	LeeBinario

	Leerá un dato hasta que se introduzca un string que represente un dato
	en binario (cadena formada por 0 y 1)
	
	DEVUELVE: cadena con dato binario
****************************************************************************/
string LeeBinario (string titulo){
	string cadena;
	
	do {
		cout << titulo;
		getline(cin, cadena);
		
		cadena = EliminaUltimosSeparadores(cadena);
		cadena = EliminaPrimerosSeparadores(cadena);
	
	} while (!EsBinario(cadena));
	
	return cadena;
}

/****************************************************************************/
/****************************************************************************/
int main(){
	
	string binario_cad = LeeBinario("Introduzca un numero binario: ");
	
	Bin bin1 (binario_cad);
	
	int valor_bin2;
	
	do{
		cout << "Introduzca un numero decimal (>0): ";
		cin >> valor_bin2;
	} while (valor_bin2 < 0);
	
	Bin bin2 (valor_bin2);
	
	
	int dcha;
	do{
		cout << "Bits hacia la derecha a desplazar el numero 1: ";
		cin >> dcha;
	} while (dcha < 0);
	
	int izda;
	do{
		cout << "Bits hacia la izquierda a desplazar el dato 1: ";
		cin >> izda;
	} while(izda < 0);
	
	//-----------------------------------
	//	CALCULOS
	
	int min_num_bits;
	
	if (bin1.MinNumBits() > bin2.MinNumBits()){
		min_num_bits = bin1.MinNumBits();
		
	} else {
		min_num_bits = bin2.MinNumBits();
		
	}
	
	Bin suma (bin1.Suma(bin2));			//SUMA
	Bin resta (bin1.Resta(bin2));		//RESTA
	Bin operacion_or (bin1.OR(bin2));	//OR
	Bin operacion_and (bin1.AND(bin2));	//AND
	
	Bin despl_dcha (bin1.DespDcha(dcha));
	
	Bin despl_izda (bin1.DespIzda(izda));
	
	//-----------------------------------
	//	SALIDA
	
	cout << endl;
	cout << "*****************************************************" << endl;
	cout << "Se han introducido los valores:" << endl;
	
	//Numero 1
	cout << "\t" << "Numero 1: " << setw(5) << bin1.GetValorDecimal() << " --> " 
		 << bin1.ToString(min_num_bits) << endl;
	
	//Numero 2
	cout << "\t" << "Numero 2: " << setw(5) << bin2.GetValorDecimal() << " --> " 
		 << bin2.ToString(min_num_bits) << endl;
	
	cout << endl;
	cout << "*****************************************************" << endl;
	cout << "OPERACIONES" << endl;
	
	//Suma
	cout << "\t" << bin1.GetValorDecimal() << " + " << bin2.GetValorDecimal() 
		 << " = " << suma.GetValorDecimal() << " --> " 
		 << suma.ToString(min_num_bits) << endl;
		 
	//Resta
	cout << "\t" << "|" << bin1.GetValorDecimal() << " - " 
		 << bin2.GetValorDecimal() << "|" << " = " << resta.GetValorDecimal() 
		 << " --> " << resta.ToString(min_num_bits) << endl;
	
	//Or
	cout << "\t" << bin1.GetValorDecimal() << " OR " << bin2.GetValorDecimal() 
		 << " = " << operacion_or.GetValorDecimal() << " --> " 
		 << operacion_or.ToString(min_num_bits) << endl;
	
	//And
	cout << "\t" << bin1.GetValorDecimal() << " AND " << bin2.GetValorDecimal() 
		 << " = " << operacion_and.GetValorDecimal() << " --> " 
		 << operacion_and.ToString(min_num_bits) << endl;
		 
	cout << endl;
	cout << "*****************************************************" << endl;
	cout << "DESPLAZAMIENTOS" << endl;
	
	//Desplazamiento a la derecha
	cout << "\t" << bin1.ToString(min_num_bits) << " >> " 
		 << despl_dcha.ToString(min_num_bits) << " --> " 
		 << despl_dcha.GetValorDecimal() << endl;
	
	//Desplazamiento a la izquierda
	cout << "\t" << bin1.ToString(min_num_bits) << " << " 
		 << despl_izda.ToString(min_num_bits) << " --> " 
		 << despl_izda.GetValorDecimal() << endl;
	
	return 0;
}
