/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 4 - IV: Se trata del mismo programa realizado para la 
	Relación de Problemas III pero usando datos tipo struct.

*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Instante {
	int hora; 
	int minuto; 
	int segundo;
};


/***************************************************************************/
const int SEGS_MIN   = 60;  // Segundos en un minuto
const int MINS_HORA  = 60;	// Minutos en una hora
const int HORAS_DIA = 24;	// Horas en un dÃ­a

const int SEGS_HORA = MINS_HORA * SEGS_MIN; 	// Segundos en una hora
const int SEGS_DIA  = HORAS_DIA*SEGS_HORA;		// Segundos en un dÃ­a
	
/***************************************************************************/
/***************************************************************************/
// Lee (y filtra) la hora.
//
// Recibe: msg, el mensaje que etiqueta la lectura
// Devuelve: el valor leido 
//
// POST: 0 <= hora < HORAS_DIA

int LeeHora (string msg)
{
	int hora; 
	
	do {
		cout << msg;
		cin >> hora;
	} while ((hora<0) || (hora>=HORAS_DIA)); 
	
	return (hora);
}	

/***************************************************************************/
// Lee (y filtra) el minuto.
//
// Recibe: msg, el mensaje que etiqueta la lectura
// Devuelve: el valor leido 
//
// POST: 0 <= minuto < MINS_HORA

int LeeMinuto (string msg)
{
	int minuto; 
		
	do {
		cout << msg;
		cin >> minuto;
	} while ((minuto<0) || (minuto>=MINS_HORA)); 
	
	return (minuto);
}		

/***************************************************************************/
// Lee (y filtra) el segundo.
//
// Recibe: msg, el mensaje que etiqueta la lectura
// Devuelve: el valor leido 
//
// POST: 0 <= segundo < SEGS_MIN

int LeeSegundo (string msg)
{
	int segundo; 
		
	do {
		cout << msg;
		cin >> segundo;
	} while ((segundo<0) || (segundo>=SEGS_MIN)); 

	return (segundo);
}		

/***************************************************************************/
// Lee (y filtra) la distancia
//
// Recibe: msg, el mensaje que etiqueta la lectura
// Devuelve: el valor leido 
//
// POST: 0 < distancia

double LeeDistancia (string msg)
{
	double distancia; 
	
	do {
		cout << msg;
		cin >> distancia;
	} while (distancia<=0); 

	return (distancia);
}		

/***************************************************************************/
// Calcula y devuelve el número de segundos entre las (0:0:0) y un instante 
// de ese día especificado por la hora completa (h:m:s)
//
// Recibe: datos del instante (struct Instante: hora, minuto y segundo)
// Devuelve: segs, número de segundos entre (0:0:0) y (hora:minuto:segundo)
//
// PRE: 0 <= h < HORAS_DIA, 0 <= m < MINS_HORA y 0 <= s < SEGS_MIN
// POST: 0 <= segs < SEGS_DIA

int SegundosDesdeInicioDia (Instante tiempo)
{
	int segs = (tiempo.hora * SEGS_HORA) + (tiempo.minuto * SEGS_MIN) + 
			   tiempo.segundo;
			   
	return (segs);
}

/***************************************************************************/
// Calcular número de segundos que han transcurrido desde dos instantes dados 
// por las tripletas que indican el instante inicial (tiempo_inicial) y 
// el final (tiempo_final)
//
// Recibe: tiempo_inicial (struct Instante: hora, minuto y segundo inicial)
//         tiempo_final (struct Instante: hora, minuto y segundo final)
//
// PRE: Los dos instantes pertenecen al mismo día 
// PRE: El instante inicial es anterior al final
// PRE: 0 <= h_inic < HORAS_DIA, 0<=m_inic<MINS_HORA y 0<=m_inic<SEGS_MIN
// PRE: 0 <= h_fin < HORAS_DIA, 0<=m_fin<MINS_HORA y 0<=s_fin<SEGS_MIN

int NumSegundosEntreInstantes (Instante tiempo_inicial, Instante tiempo_final)
{
	// Calcular los segundos que transcuren desde las 0:0:0
	int segs_instante_1 = SegundosDesdeInicioDia (tiempo_inicial);
	int segs_instante_2 = SegundosDesdeInicioDia (tiempo_final);
	
	int segs_entre_instantes = segs_instante_2 - segs_instante_1;
	// Si se cumplen las precondiciones, segs_entre_instantes > 0
				
	return segs_entre_instantes;
}
	
/***************************************************************************/
/***************************************************************************/
// Calcular la velocidad en Km/h 
//
// Recibe:  tiempo_segs, tiempo (segundos)
//			distancia_km, espacio (en km)
//
// PRE: tiempo_segs  > 0
// PRE: distancia_km > 0

double Velocidad (double distancia_km, int tiempo_segs)
{
	double minutos;  
	
	minutos  = tiempo_segs / static_cast<double>(SEGS_MIN);
			
	cout << endl; 
	cout << "\tSegundos: " << setw(6) << tiempo_segs << endl;
	cout << "\tMinutos:  " << setw(6) << setprecision(3) << minutos << endl;

	// La solucion es una sencilla regla de tres:
	// 		minutos ---------> distancia Km |
	// 		60.0 minutos ---->         x Km | x = (60.0*distancia)/minutos 

	double velocidad = (MINS_HORA*distancia_km) / minutos;
	
	return (velocidad);
}
		
		
/***************************************************************************/
/***************************************************************************/

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	
	// Datos de la carrera
	Instante tiempo_salida;

	double distancia; 	
	
	
	// Entrada de datos de la carrera
	
	cout << "Introduzca hora de inicio de la carrera:" << endl;

	tiempo_salida.hora = LeeHora ("\tHora:    ");
	tiempo_salida.minuto = LeeMinuto ("\tMinuto:    ");
	tiempo_salida.segundo = LeeSegundo ("\tSegundo:    ");

	cout << endl; 	
	cout << "Introduzca distancia de la carrera:" << endl;
	
	distancia = LeeDistancia ("\tDistancia: ");

	
	// Datos de cada corredor
	
    int dorsal;
    Instante tiempo_llegada;
	 

	// Número de segundos en carrera ... 	
	int segs_en_carrera;     // ... del corredor actual
	int segs_en_carrera_ant; // ... del corredor anterior
	
	
	// Tiempo del corredor (ficticio) previa al primero. 
	// Debemos asegurar que el tiempo del primero sea superior o igual 
	// a su valor y 0 (o menos) es un valor apropiado. 
	segs_en_carrera_ant = 0;
	
	cout << endl; 
	cout << "----------------------------------" << endl; 
	cout << endl; 
	
	cout << "Dorsal: " ;
	cin >> dorsal; 
	
	while (dorsal >= 0) {
			
		// Banderas para la corrección de la hora de llegada del corredor.
		// Tendrán el valor "true" si la hora de llegada del corredor es: 
		
		bool es_hora_llegada_ok; 		// posterior a la salida
		bool es_hora_llegada_ordenada; 	// posterior (o igual) a la del 
										// corredor anterior
		
		// Pedir hora de llegada y filtrarla adecuadamente
		
		do {  
		
			cout << endl;
				
			tiempo_llegada.hora = LeeHora ("\tHora llegada:    ");
			tiempo_llegada.minuto = LeeMinuto ("\tMinuto llegada:    ");
			tiempo_llegada.segundo = LeeSegundo ("\tSegundo llegada:    ");
			
			segs_en_carrera = NumSegundosEntreInstantes (tiempo_salida, 
							  tiempo_llegada);
				 
				 
			// Comprobar si la hora de llegada es posterior a la de salida	
			// Â¡Â¡Recuerde que deben pertenecer al mismo día!!	
				
			es_hora_llegada_ok =  (segs_en_carrera >= 0);
			
			if (!es_hora_llegada_ok) { // hora de llegada incorrecta
				cout << endl;
				cout << "\t--> Llegada previa a salida." << endl;				
			}
			
			// Comprobar si la hora de llegada es posterior o igual a 
			// la hora de llegada del corredor anterior.
				
			es_hora_llegada_ordenada = 
			     (segs_en_carrera >= segs_en_carrera_ant);

			if (!es_hora_llegada_ordenada) { // hora de llegada desordenada
				cout << endl;
				cout << "\t--> Llegada previa al anterior." << endl;
			}
		
		} while (!es_hora_llegada_ok || !es_hora_llegada_ordenada);
		
		// En este punnto aseguramos que la hora de llegada del corredor 
		// actual es correcta (0<=h<24, 0<=m<60, 0<=s<60) y que es posterior 
		// a la hora de salida y a la hora de llegada del corrredor anterior. 
		
		//...................................................................
		// Velocidad en Km/h
		
		double velocidad = Velocidad (distancia, segs_en_carrera); 
		
		cout << endl;
		cout << "\tVelocidad = " << velocidad << " Km/h" << endl;
			
		
		//...................................................................
		// Velocidad en min/Km (mins:segs / Km)
			
		/*
		x km/h = x km/60 min = x/60 km/min --> 1/(x/60)) min/km = 60/x min/km
		*/
	
		double minutos_reales_por_km = static_cast<double>(MINS_HORA)/velocidad;
		
		int mins_ritmo = (int) floor (minutos_reales_por_km);
		int segs_ritmo = (int) ((minutos_reales_por_km-mins_ritmo)*SEGS_MIN);
	
		cout << "\tRitmo = " << setw(2) << mins_ritmo  << ":" 
		     << setw(2) << segs_ritmo << " / km";
		cout << " (" << setw(5) << setprecision(2) << minutos_reales_por_km 
		     << " Minutos/km)" << endl;
		cout << endl;		

		
		//...................................................................
		// Para la siguiente iteración, el corredor actual será el anterior 
			
		segs_en_carrera_ant = segs_en_carrera; 
			
		// Lectura del siguiente corredor
		
		cout << endl; 
		cout << "Dorsal: " ;
		cin >> dorsal; 
	}	
	
	return 0;
}
