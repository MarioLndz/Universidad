/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 29 - V: Este programa elaborará el ránking anual nacional de una 
	prueba de atletismo,, ordenando los datos de manera creciente de acuerdo 
	al tiempo

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
	
	const int NUM_ATLETAS = 100;
	RegistroDeMarca marcas[NUM_ATLETAS];
	int marcas_registradas = 0;
	
	//----------------------------------
	//	ENTRADA
	
	CategoriaTiempo magnitud_max;
	CategoriaTiempo magnitud;
	
	string fecha;
	cin >> fecha;
	
	while (marcas_registradas < NUM_ATLETAS && fecha != TERMINADOR){
		//Introducimos la fecha
		marcas[marcas_registradas].fecha = ComponeFecha(fecha);
		
		//Leemos e introducimos la licencia
		string licencia;
		cin >> licencia;
		
		marcas[marcas_registradas].licencia = licencia;
		
		//Leemos e introducimos el tiempo
		string tiempo;
		cin >> tiempo;
		
		marcas[marcas_registradas].tiempo = ComponeTiempo(tiempo);
		
		//Calculamos cual es la maxima magnitud usada para el tiempo
		if (marcas[marcas_registradas].tiempo.hora != 0){
			magnitud = CategoriaTiempo::horas;
		} else if (marcas[marcas_registradas].tiempo.min != 0){
			magnitud = CategoriaTiempo::minutos;
		} else {
			magnitud = CategoriaTiempo::segundos;
		}
		
		if (magnitud > magnitud_max){
			magnitud_max = magnitud;
		}
		
		//Actualizamos el numero de marcas registradas
		marcas_registradas++;
		
		//Leemos la fecha
		cin >> fecha;
		
	}
	
	//----------------------------------
	//	CALCULOS
	
	//Ordenaremos el array utilizando el algoritmo de ordenacon por seleccion
	for (int izda = 0 ; izda < marcas_registradas ; izda++){
		// Calcular el mínimo entre "izda" y "marcas_registradas"-1
		double minimo = CalculaSeg(marcas[izda].tiempo); // Segundos del minimo
		int pos_min = izda; // Posición del mínimo
		
		for (int i = izda + 1; i < marcas_registradas ; i++){
			if (CalculaSeg(marcas[i].tiempo) < minimo){ // Nuevo mínimo
				minimo = CalculaSeg(marcas[i].tiempo);
				pos_min = i;
			}
		}
		
		// Intercambiar los valores guardados en "izda" y "pos_min"
		RegistroDeMarca intercambia = marcas[izda];
		marcas[izda] = marcas[pos_min];
		marcas[pos_min] = intercambia;
	}
	
	
	//----------------------------------
	//	SALIDA
	
	cout << "Ranking de la prueba: 1500ML" << endl;
	for (int n = 0; n < marcas_registradas; n++){
		cout << ToString(n+1, 3, ' ') << " " << setw(10) << marcas[n].licencia 
			 << " " << ToStringFecha(marcas[n].fecha) << " "
			 << ToStringTiempo(marcas[n].tiempo, magnitud_max) << endl;
	}
	
		
	return 0;
}
