/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 44 - V: Este programa es una ampliacion del ejercicio 29 de esta
	relacion de problemas. Ahora, se deberan organizar el ranking de varias
	pruebas previamente indicadas

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
#include <iomanip>

using namespace std;
/*****************************************************************************
//	Declaracion de tipos y constantes
******************************************************************************/
//Tiempo
struct Tiempo {
	int hora;	// hora < 24
	int min;	// min < 60
	int seg;	// seg < 60
	int mseg;	// mseg < 1000
	
};

enum class CategoriaTiempo {segundos, minutos, horas};

//Fecha
struct Fecha{
	int dia;	// 1 <= dia <= 31
	int mes;	// 1 <= mes <= 12
	int year;
	
};

struct RegistroDeMarca {
	Fecha fecha;
	string licencia;
	Tiempo tiempo;
};

/*****************************************************************************
//	FUNCIONES
******************************************************************************/

/****************************************************************************
//	ComponeFecha
	
	Recibe un string con un formato de fecha dd/mm/aaaa y a partir de el
	compone un struct de tipo Fecha
	
	RECIBE: string
	DEVUELVE: struct de tipo Fecha
	PRE: La fecha debe estar en formato "dd/mm/aaaa"
*****************************************************************************/
Fecha ComponeFecha (string fecha_leida){
	Fecha fecha;
	
	fecha.dia = stoi(fecha_leida.substr(0,2));
	fecha.mes = stoi(fecha_leida.substr(3,2));
	fecha.year = stoi(fecha_leida.substr(6,4));
	
	return fecha;
	
}

/****************************************************************************
//	ComponeTiempo
	
	Recibe un string con un formato de tiempo "hh:mm:ss:msegmseg" y a partir
	de el compone un struct de tipo Tiempo
	
	RECIBE: string
	DEVUELVE: struct de tipo Tiempo
	PRE: el tiempo debe estar en el formato "hh:mm:ss:msegmseg"
*****************************************************************************/
Tiempo ComponeTiempo (string tiempo_leido){
	Tiempo tiempo;
	
	tiempo.hora = stoi(tiempo_leido.substr(0,2));
	tiempo.min = stoi(tiempo_leido.substr(3,2));
	tiempo.seg = stoi(tiempo_leido.substr(6,2));
	tiempo.mseg = stoi(tiempo_leido.substr(9,3));
	
	return tiempo;
	
}

/****************************************************************************
//	ToString
	
	Añade a un string un numero entero, el cual debera ocupar n casillas.
	Si no se ocupan las casillas indicadas, se rellenaran los espacios con
	el caracter indicado
	
	RECIBE: Numero entero, numero de casillas, caracter para rellenar
	DEVUELVE: string
*****************************************************************************/
string ToString (int entero, int num_casillas, char relleno){
	string resultado;
	
	resultado = to_string(entero);
	int longitud = resultado.length();
	while (longitud < num_casillas){
		resultado = relleno + resultado;
		longitud++;
	}

	return resultado;
}

/****************************************************************************
//	ToStringFecha
	
	Añade en un string la fecha indicada a través de un struct de tipo Fecha
	Se escribira el mes correspondiente en letra
	
	RECIBE: struct de tipo Fecha
	DEVUELVE: string
*****************************************************************************/
string ToStringFecha (Fecha fecha){
	const int NUM_MESES=12;
	string Meses[NUM_MESES] =  {"Enero", "Febrero", "Marzo", "Abril", "Mayo", 
								"Junio", "Julio", "Agosto", "Septiembre", 
								"Octubre", "Noviembre", "Diciembre"};
	
	string fecha_str;
	
	string mes = Meses[fecha.mes - 1];
	for (int n = mes.length(); n <= 10; n++){
		mes += " ";
	}
	
	fecha_str = ToString(fecha.dia, 2, ' ') + " ";
	fecha_str += mes + " ";
	fecha_str += ToString(fecha.year, 2, ' ');
	
	return fecha_str;
}

/****************************************************************************
//	ToStringTiempo
	
	Añade a un string el tiempo indicado a traves de un struct de tipo Tiempo.
	Se tendra en cuenta la magnitud maxima que se desee representar. Los
	milisegundos siempre se mostrarán
	
	RECIBE: struct de tipo tiempo, clase enumerada de la magnitud maxima
	DEVUELVE: string
*****************************************************************************/
string ToStringTiempo (Tiempo tiempo, CategoriaTiempo magnitud){
	string tiempo_str;
	
	switch (magnitud){
		case (CategoriaTiempo::horas):
			tiempo_str = ToString(tiempo.hora, 2, '0') + ":";
			tiempo_str += ToString(tiempo.min, 2, '0') + ":";
			tiempo_str += ToString(tiempo.seg, 2, '0') + ":";
			break;
			
		case (CategoriaTiempo::minutos):
			tiempo_str += ToString(tiempo.min, 2, '0') + ":";
			tiempo_str += ToString(tiempo.seg, 2, '0') + ":";
			break;
			
		case (CategoriaTiempo::segundos):
			tiempo_str += ToString(tiempo.seg, 2, '0') + ":";
			break;
		
	}
	
	tiempo_str += ToString(tiempo.mseg, 2, '0');
	
	return tiempo_str;
}

/****************************************************************************
//	CalculaSeg
	
	Pasará un dato de tipo Tiempo a segundos totales
	
	RECIBE: Struct de tipo Tiempo
	DEVUELVE: Segundos totales de ese struct
*****************************************************************************/
double CalculaSeg (Tiempo tiempo){
	const double HORA_A_MINS = 60;
	const double MIN_A_SEG = 60;
	const double SEG_A_MSEG = 1000;
	
	double seg_totales = 0;
	
	seg_totales = ((tiempo.hora*HORA_A_MINS*MIN_A_SEG) + 
				  (tiempo.min*MIN_A_SEG) + tiempo.seg + 
				  (tiempo.mseg/SEG_A_MSEG));
	
	return seg_totales;
}

/*****************************************************************************/
/*****************************************************************************/
int main () {
	const string TERMINADOR = "FIN";
	
	const int MAX_PRUEBAS = 20;
	const int MAX_MARCAS_EN_PRUEBA = 100;
	RegistroDeMarca marcas[MAX_PRUEBAS][MAX_MARCAS_EN_PRUEBA];
	
	// Número de filas ocupadas de "marcas"
	int num_pruebas; // PRE: 0 <= num_pruebas <= MAX_PRUEBAS
	
	// PRE: 0<=num_marcas_en_prueba[i]<=MAX_MARCAS_EN_PRUEBA
	int num_marcas_en_prueba[MAX_PRUEBAS];
	
	//----------------------------------
	//	ENTRADA
	
	CategoriaTiempo magnitud_max[MAX_PRUEBAS];
	CategoriaTiempo magnitud[MAX_PRUEBAS];
	
	
	//Leo el numero de pruebas
	cin >> num_pruebas;
	
	//Leo el nombre de cada prueba
	string nombre_pruebas[MAX_PRUEBAS];
	
	for(int i=0; i<num_pruebas; i++){
		cin >> nombre_pruebas[i];
	}
	
	//Leemos e introducimos la prueba
	string prueba;
	cin >> prueba;
	
	while (prueba != TERMINADOR){
		//Compruebo de que prueba se trata
		int p = -1;
		bool parar = false;
		
		while (p < num_pruebas && !parar){
			p++;
			
			if (nombre_pruebas[p] == prueba){
				parar = true;
			}
		}
		
		//Leemos e introducimos la fecha
		string fecha;
		cin >> fecha;
		
		marcas[p][num_marcas_en_prueba[p]].fecha = ComponeFecha(fecha);
		
		//Leemos e introducimos la licencia
		string licencia;
		cin >> licencia;
		
		marcas[p][num_marcas_en_prueba[p]].licencia = licencia;
		
		//Leemos e introducimos el tiempo
		string tiempo;
		cin >> tiempo;
		
		marcas[p][num_marcas_en_prueba[p]].tiempo = ComponeTiempo(tiempo);
		
		//Calculamos cual es la maxima magnitud usada para el tiempo
		if (marcas[p][num_marcas_en_prueba[p]].tiempo.hora != 0){
			magnitud[p] = CategoriaTiempo::horas;
		} else if (marcas[p][num_marcas_en_prueba[p]].tiempo.min != 0){
			magnitud[p] = CategoriaTiempo::minutos;
		} else {
			magnitud[p] = CategoriaTiempo::segundos;
		}
		
		if (magnitud[p] > magnitud_max[p]){
			magnitud_max[p] = magnitud[p];
		}
		
		//Actualizamos el numero de marcas registradas
		num_marcas_en_prueba[p]++;
		
		//Leemos la siguiente linea
		cin >> prueba;
		
	}
	
	//----------------------------------
	//	CALCULOS
	
	for (int n = 0; n < num_pruebas; n++){
		// Ordenaremos el array utilizando el algoritmo de ordenacon
		// por seleccion
		for (int izda = 0 ; izda < num_marcas_en_prueba[n] ; izda++){
			// Calcular el mínimo entre "izda" y "marcas_registradas"-1
			double minimo = CalculaSeg(marcas[n][izda].tiempo); // Segundos del 
																// minimo
			int pos_min = izda; // Posición del mínimo
			
			for (int i = izda + 1; i < num_marcas_en_prueba[n] ; i++){
				if (CalculaSeg(marcas[n][i].tiempo) < minimo){ // Nuevo mínimo
					minimo = CalculaSeg(marcas[n][i].tiempo);
					pos_min = i;
				}
			}
			
			// Intercambiar los valores guardados en "izda" y "pos_min"
			RegistroDeMarca intercambia = marcas[n][izda];
			marcas[n][izda] = marcas[n][pos_min];
			marcas[n][pos_min] = intercambia;
		}
	}
	
	
	//----------------------------------
	//	SALIDA
	
	cout << "Ranking general:" << endl << endl;
	
	for (int p = 0; p < num_pruebas; p++){
		cout << nombre_pruebas[p] << endl;
		for (int n = 0; n < num_marcas_en_prueba[p]; n++){
			cout << ToString(n+1, 3, ' ') << " " << setw(10) 
				 << marcas[p][n].licencia << " " 
				 << ToStringFecha(marcas[p][n].fecha) << " "
				 << ToStringTiempo(marcas[p][n].tiempo, magnitud_max[p]) 
				 << endl;
		}
		
		cout << endl;
	}
	
		
	return 0;
}
