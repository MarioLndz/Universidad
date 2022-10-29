/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 7
//
//	TABLA DENTADA -	......
/*
	Se quiere elaborar el ránking anual nacional de varias pruebas de 
	atletismo.... (ver enunciado)
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/***************************************************************************/
/***************************************************************************/

// Número máximo de pruebas a leer
const int MAX_PRUEBAS = 20;

// Número máximo de marcas de cada prueba.
const int MAX_MARCAS_EN_PRUEBA = 100;

/***************************************************************************/
/***************************************************************************/

// Funciones varias
/*
	string EliminaUltimos(string cadena, char a_borrar);
	string EliminaPrimeros (string cadena, char a_borrar);
	double Redondea (double real, int num_decimales);
	
	string ToStringDouble (double real, int num_casillas, int decimales, 
	 					   char relleno= ' ');
	string ToStringInt (int entero, int num_casillas, char relleno=' ');

	enum class TipoAjuste {izquierda, centro, derecha};
	string FormateaString (string cad, int num_casillas, TipoAjuste ajuste, 
						   char relleno=' ');
*/

/////////////////////////////////////////////////////////////////////////////
// Clase Fecha (versión muy simple) 

class Fecha 
{
private: 

	int dia;	// 1 <= dia <= 31 
	int mes; 	// 1 <= mes <= 12
	int anio; 	// 1900 <= anio	
	
	static const string MESES[];
	
public:

	/***********************************************************************/
	// Constructores
	
	// Constructor sin argumentos 
	Fecha (void) : dia(1), mes(1), anio(1990) { }

	// Constructor con argumentos int (dia, mes, anio)
	Fecha (int el_dia, int el_mes, int el_anio) 
		: dia(el_dia), mes(el_mes), anio(el_anio) 
	{ }

	// Constructor con argumento string (dd/mm/aaaa)
	// PRE: cad tiene el formato dd/mm/aaaa
	Fecha (string cad)
	{
		dia  = stoi(cad.substr(0,2));	 
		mes  = stoi(cad.substr(3,2));	  	
		anio = stoi(cad.substr(6,4));	 
	}

	/***********************************************************************/
	// Serialización de un dato Fecha
	
	string ToString (void) 
	{
		return ToStringInt(dia, 2) + " " + MESES[mes-1] + " " + 
		       ToStringInt(anio, 4);
	}

	/***********************************************************************/
}; 

const string Fecha::MESES[] = {"Enero     ", "Febrero   ", 
        "Marzo     ", "Abril     ", "Mayo      ", "Junio     ", "Julio     ", 
        "Agosto    ", "Septiembre", "Octubre   ", "Noviembre ", "Diciembre "};	

/////////////////////////////////////////////////////////////////////////////

// Tipo para seleccionar el tipo de presentación de los datos "Tiempo" 
// Si "segundos": nos interesa segundos:milesimas
// Si "minutos": nos interesa minutos:segundos:milesimas
// Si "horas": nos interesa horas:minutos:segundos:milesimas
enum class CategoriaTiempo {segundos, minutos, horas};

/////////////////////////////////////////////////////////////////////////////
// Clase Tiempo (versión muy simple) 

class Tiempo 
{
private: 

	int horas;		// 0 <= horas <= 24 
	int minutos; 	// 0 <= minutos < 60
	int segundos; 	// 0 <= segundos < 60	
	int milesimas; 	// 0 <= milesimas < 1000
	
	static const int SEGS_MIN = 60; 
	static const int MINS_HORA = 60; 
	static const int MILISEGS_SEG = 1000; 
	static const int MILISEGS_MIN = MILISEGS_SEG*SEGS_MIN;
	static const int MILISEGS_HORA = MILISEGS_MIN*MINS_HORA;

public:

	/***********************************************************************/
	// Constructores
	
	// Constructor sin argumentos 
	Tiempo (void) : horas(0), minutos(0), segundos(0), milesimas(0)  { }

	// Constructor con argumentos int (horas, minutos, segundos, milesimas)
	Tiempo (int las_horas, int los_minutos, int los_segundos, int las_milesimas) 
		: horas(las_horas), minutos(los_minutos), segundos(los_segundos), 
		  milesimas(las_milesimas) 
	{ }

	// Constructor con argumento string (hh:mm:ss:mmm)
	// PRE: cad tiene el formato hh:mm:ss:mmm
	Tiempo (string cad)
	{
		horas     = stoi(cad.substr(0,2));	 
		minutos   = stoi(cad.substr(3,2));	 
		segundos  = stoi(cad.substr(6,2));	 	
		milesimas = stoi(cad.substr(9,3));	 
	}

	/***********************************************************************/
	// Devuelve el tiempo registrado en milisegundos
	long TiempoMilisegundos (void)
	{
		return (horas*MILISEGS_HORA + minutos*MILISEGS_MIN + 
				segundos*MILISEGS_SEG + milesimas);	
	}

	/***********************************************************************/
	// Determina si el tiempo del objeto implícito es menor que el de "otro"
	bool EsMenor (Tiempo otro)
	{
		long int milisegs_este, milisegs_otro;
		
		milisegs_este = TiempoMilisegundos(); 
		milisegs_otro = otro.TiempoMilisegundos(); 
					 
		return (milisegs_este < milisegs_otro);
	}

	/***********************************************************************/
	// Serialización de un dato Fecha
	
	string ToString (CategoriaTiempo tipo_tiempo) 
	{
		string cad; 
		
		switch (tipo_tiempo) {
			
			case (CategoriaTiempo::horas) : {
				cad = cad + ToStringInt(horas, 2, '0') + ":"; 
			}
			case (CategoriaTiempo::minutos) : {
				cad = cad + ToStringInt(minutos, 2, '0') + ":"; 
			}		
			default: {
				cad = cad + ToStringInt(segundos, 2, '0') + ":" + 
			  		        ToStringInt(milesimas, 3, '0');
				break;
			} 
		}
	
		return cad; 
	}
	/***********************************************************************/
}; 

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Clase RegistroDeMarca.
// Incluye la información asociada a un registro de marca. 

class RegistroDeMarca 
{
private: 

	Fecha fecha_marca;		// Fecha de la marca 
	string licencia;		// Licencia del atleta
	Tiempo tiempo_marca;	// Tiempo registrado

public: 

	/***********************************************************************/
	// Constructores
	
	// Constructor sin argumentos 
	RegistroDeMarca (void) : fecha_marca (Fecha()), 
			licencia ("sin valor"), tiempo_marca (Tiempo()) { }

	// Constructor con argumentos int (horas, minutos, segundos, milesimas)
	RegistroDeMarca (Fecha la_fecha_marca, string la_licencia, 
					 Tiempo el_tiempo_marca) 
		: fecha_marca(la_fecha_marca), licencia(la_licencia), 
		  tiempo_marca(el_tiempo_marca) 
	{ }
	 
	/***********************************************************************/
	// Métodos Get
	
	Fecha  GetFecha (void)    { return fecha_marca; } 	
	string GetLicencia (void) { return licencia; } 
	Tiempo GetTiempo (void)   { return tiempo_marca; }
	
	/***********************************************************************/
	// Serialización de un dato RegistroDeMarca
	
	string ToString (void) 
	{
		string cad; 
		
		cad = FormateaString (licencia , 9, TipoAjuste::derecha) + "  " + 
			  	fecha_marca.ToString() + "  " + 
			 	tiempo_marca.ToString(CategoriaTiempo::minutos); 
			 	
		return cad; 
	}
	/***********************************************************************/
}; 

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Secuencia_RegistroDeMarca  
{

private:

    static const int TAMANIO = MAX_MARCAS_EN_PRUEBA; // Casillas disponibles
	RegistroDeMarca vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:
	......
	
    /***********************************************************************/
    // Compone un string con todos los valores que están
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena = "{";

		if (total_utilizados > 0) {

	        for (int i=0; i<total_utilizados-1; i++)
	        	cadena = cadena + vector_privado[i].ToString() + ", ";

			// Añadie el último seguido de '}'
	        cadena = cadena + vector_privado[total_utilizados-1].ToString();
		}

        cadena = cadena + "}";

        return (cadena);
    }
    
   	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Tabla dentada de datos RegistroDeMarca

class TablaDentada_RegistroDeMarca 
{
	
private:

	......
	
public:
	
	......
	
	/***********************************************************************/
	// Compone y devuelve un string con el contenido de la matriz
	
	string ToString ()
	{
		string cad; 
		
		for (int fila=0; fila<total_utilizados; fila++) {
			Secuencia_RegistroDeMarca la_secuencia = Fila(fila);
			cad = cad + "\t" + la_secuencia.ToString() + "\n";
		}
		
		return (cad);
	}
	
	/***********************************************************************/		
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
			

/***************************************************************************/
/***************************************************************************/

int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	// Terminador para los datos leidos/escritos 
	const string TERMINADOR = "FIN";
	

	// Array que contendrá los nombres de las pruebas y su posición (fila) 
	// en la matriz "marcas"   
	string pruebas[MAX_PRUEBAS];
	
	// Número de casillas ocupadas de "pruebas" (y filas de "marcas")
	int num_pruebas = 0;  
	// PRE: 0 <= num_pruebas <= MAX_PRUEBAS

	
	// ENTRADA 
	
	// 1. Lectura de las pruebas que se van a procesar
	
	// Leer número de pruebas 
	cin >> num_pruebas; // Recuerde: PRE: 0 <= num_pruebas <= MAX_PRUEBAS
		
	for (int pos=0; pos<num_pruebas; pos++) 
		cin >> pruebas[pos]; 
		
		
	// Una vez que sabemos cuántas pruebas vamos a procesar se puede crear 
	// la tabla para guardar los datos leidos. Se trata de una tabla dentada 
	// porque cada prueba puede tener un número de marcas diferente al de 
	// las otras pruebas. 
	// 	* Filas: las marcas de una prueba concreta de agrupan en la misma fila.
	// 	* Columnas: Cada casilla es la marca de una prueba.
	
	TablaDentada_RegistroDeMarca marcas (num_pruebas);

	
	// 2. Leer marcas
	
	// Para organizar los datos leidos
	
	Fecha la_fecha; 
	Tiempo el_tiempo; 
			
	int cont_marcas = 0; /// Número de líneas leidas

	// Cada elemento de una marca (prueba, fecha, licencia y tiempo) 
	// se lee en un dato string. 
	string cad_prueba, cad_fecha, cad_licencia, cad_tiempo;	
	
	cin >> cad_prueba; 	// Lectura adelantada

	while (cad_prueba != TERMINADOR) {
		
		cont_marcas++; // Una marca más (no se leyó el TERMINADOR)	
			
		// Una vez leida la prueba, ahora hay que buscar la posición (fila) 
		// que le corresponde en "marcas". La posición está guardada en 
		// el aray "pruebas". 
		// PRE: Suponemos (por simplicidad) que no hay errores en la entrada.
		// 		Esta suposición simplifica notablemente el ciclo de búsqueda.  
		
		int pos_prueba=0; 		
		while (pruebas[pos_prueba] != cad_prueba) pos_prueba++;  
		// Aseguramos que 0 <= pos_prueba < num_pruebas
		
		// Se leen los demás datos de la marca actual 
		
		cin >> 	cad_fecha; 		
		Fecha la_fecha (cad_fecha); // Crear objeto "Fecha"
							
		cin >> cad_licencia;

		cin >> cad_tiempo;
		Tiempo el_tiempo (cad_tiempo); // Crear objeto "Tiempo"	
	
	
		// Crear un objeto "RegistroDeMarca" y guardarlo en la fila 
		// "pos_prueba" de "marcas" y actualizar el contador de datos para 
		// la prueba (num_marcas_en_prueba[pos_prueba])		
		
		RegistroDeMarca la_marca (la_fecha, cad_licencia, el_tiempo);
		marcas.AniadeMarca (la_marca, pos_prueba); 
		
		
		// Leer el siguiente registro 
		cin >> cad_prueba; 	// Lectura adelantada
		
	} // while (cad_prueba != TERMINADOR)
	

	// Mostrar los datos leidos y guardados en la matriz "marcas"

	cout << endl; 
	cout << "Se procesan "<< setw(2)<< num_pruebas << " pruebas: "; 
	for (int pos=0; pos<num_pruebas; pos++) 
		cout << setw(8) << pruebas[pos]; 
	cout << endl;
		
	cout << endl;
	cout << "Se han guardado "<< setw(4) << cont_marcas << " marcas:" << endl; 
	cout << endl; 
	
	
	for (int p=0; p<num_pruebas; p++) {
		
		cout << setw(8) << pruebas[p] << endl; 
	
		for (int m=0; m<marcas.ColumnasUtilizadas(p); m++) 
			cout << '\t' << setw(3) << m+1 
			     << marcas.Elemento(p, m).ToString() << endl; 				 
		
		cout << endl;
		 
	} // for p
	
	

	// CÁLCULOS
	 
	// Ordenación de cada fila de la matriz "marcas" por "tiempo_marca"
	// El procedimiento será 1) extraer una copia de cada fila de la  
	// matriz, 2) ordenarla y 3) sustituir la fila antigua (desordenada)  
	// por la secuencia ordenada. 
	
	for (int p=0; p<num_pruebas; p++) { // para cada prueba "p"
		
		// Extraer copia de la fila "p" 
 		Secuencia_RegistroDeMarca marcas_fila_p = marcas.Fila(p);
		
		// Ordenar la secuencia 
		marcas_fila_p.Ordena ();
		
		// Sustituir la fila "p" por la secuencia ordenada 
		marcas.SustituyeFila (p, marcas_fila_p);

		// marcas.EliminaFila (p);
		// marcas.InsertaFila (p, marcas_fila_p);
			
	} // for p
	 
	 
	 
	// RESULTADO
	
	// Mostrar datos de "marcas" (ya ordenados por "tiempo_marca") 

	cerr << endl; 
	cerr << "Ranking final: "<< endl; 
	cerr << endl; 
	
	for (int p=0; p<num_pruebas; p++) {
				
		cerr << setw(8) << pruebas[p] << endl; 
	
		for (int m=0; m<marcas.ColumnasUtilizadas(p); m++) 
			cerr << '\t' << setw(3) << m+1 
			     << marcas.Elemento(p,m).ToString() << endl; 				 
		
		cerr << endl; 

	} // for p

	cout << endl; 
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
