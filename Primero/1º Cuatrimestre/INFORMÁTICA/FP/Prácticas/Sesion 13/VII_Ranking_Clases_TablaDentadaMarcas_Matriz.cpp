/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 52 - VII: Reescriba la solución del ejercicio 36 de esta 
	Relación de Problemas (el del Ranking usando clases) usando las clases 
	SecuenciaMarcas y TablaDentadaMarcas

******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

/***************************************************************************/
//	CONSTANTES GLOBALES	

//------------------------------------------------
// Número máximo de pruebas a leer
const int MAX_PRUEBAS = 20;

//------------------------------------------------
// Número máximo de marcas de cada prueba.
const int MAX_MARCAS_EN_PRUEBA = 100;

/***************************************************************************/
//Tipo de ajuste para serializar un dato
enum class TipoAjuste {izquierda, centro, derecha};


/***************************************************************************/
//	FUNCIONES

//------------------------------------------------
//	FormateaString
//
//	Ajusta un string
string FormateaString (string cad, int num_casillas, TipoAjuste ajuste, 
					   char relleno=' ')
{
	string resultado=cad;
	int lon=resultado.length();
	
	if(lon<num_casillas){
		switch (ajuste){
			case (TipoAjuste::izquierda):{
				for(int i=lon; i<=num_casillas; i++)
					resultado=resultado +relleno ;
				break;
			}
			case (TipoAjuste::derecha):{
				for(int i=lon; i<=num_casillas; i++)
					resultado=relleno + resultado ;
				break;
			}
			case (TipoAjuste::centro):{
				for(int i=lon; i<=num_casillas; i++){
					i%2==0 ? resultado=relleno + resultado : 
								resultado=resultado +relleno;
				}
				break;
			}
		}
		
	}
	
	return resultado;
						   	
}

/***************************************************************************/
//	ToStringInt
//	Pasa a string un número entero, con los espacios que se deseen.
//	Si no sobran espacios, estos se rellenan
//	
//	Recibe: entero, numero de casillas y el carácter de relleno
//	Devuelve: string
//	PRE: entero es estrictamente un dato entero
//		 num_casillas>0
string ToStringInt (int entero, int num_casillas, char relleno){
	string resultado;
	
	resultado=to_string(entero);
	int lon=resultado.length();
	
	if(lon<num_casillas){
		for(int i=lon; i<num_casillas; i++){
			resultado=relleno + resultado;
		}
	}
	
	return resultado;
}

/**************************************************************************/
//	CLASES
/**************************************************************************/

/**************************************************************************/
//	Clase Fecha: caracterizada por día, mes y anio
class Fecha{
private: 
	int dia; //día de la carrera 1<=dia<=31;
	int mes; //mes en el que se realiza la carrera 1<=mes<=12;
	int anio;//año en el que se realiza
	
public:
	/**************************************************************************/
	//Constructor con argumentos
	Fecha(string fecha) {
		ComponeFecha(fecha);
	}
	
	/**************************************************************************/
	//Constructor sin argumentos para poder inicializar un array
	Fecha()
		: 	dia(0), 
			mes(0), 
			anio(0)
	{}
	
	/**************************************************************************/
	//	Métodos SET
	
	//------------------------------------------------
	//	Dia
	void SetDia(string d) {
		dia=stoi(d);
	}
	
	//------------------------------------------------
	//	Mes
	void SetMes(string m) {
		mes=stoi(m);
	}
	
	//------------------------------------------------
	//	Anio
	void SetAnio(string a) {
		anio=stoi(a);
	}
	
	//------------------------------------------------
	//	Compone una fecha completa
	void ComponeFecha(string fecha_leida){
		SetDia(fecha_leida.substr(0,2));
		SetMes(fecha_leida.substr(3,2));
		SetAnio(fecha_leida.substr(6,4));
	}
	
	//------------------------------------------------
	//	Función que pasa a string una fecha. Pasa el mes a letra
	//	Recibe: dato tipo Fecha
	//	Devuelve: fecha con el mes en letra
	//	PRE: 1<=dia<=31
	//		 1<=mes<=12
	string ToString(){
		const string meses[]={"Enero     ", "Febrero   ", "Marzo     ", 
							  "Abril     ", "Mayo      ", "Junio     ", 
							  "Julio     ", "Agosto    ", "Septiembre", 
							  "Octubre   ", "Noviembre ", "Diciembre "};
		
		string resultado;
		
		string mes_string=meses[mes-1];
		
		resultado=ToStringInt(dia, 3, ' ') + " " + mes_string + " " +
				  ToStringInt(anio, 4, ' ');
		
		return resultado;
	}
	
};


/**************************************************************************/
//	Clase Tiempo: caracterizada por horas, minutos, segundos y milisegundos
class Tiempo{
private:
	int horas; //horas que se tardan horas<HORAS_DIA
	int minutos; //minutos horas<MINUTOS_HORA
	int segundos; //segundos<SEGUNDOS_HORA
	int milisegundos; //milisegundos<MILISEGUNDOS_SEGUNDO 

public:	
	//------------------------------------------------
	//Constructor con argumentos
	Tiempo(string tiempo)
	{
		ComponeTiempo(tiempo);
	}					
	
	//------------------------------------------------
	//Constructor sin argumentos para poder inicializar un array
	Tiempo()
		:	horas(0),
			minutos(0), 
			segundos(0), 
			milisegundos(0)
	{}
	//------------------------------------------------
	//Métodos SET
	void SetHoras(string h){
		horas=stoi(h);
	}
	
	void SetMinutos(string m){
		minutos=stoi(m);
	}
	
	void SetSegundos(string s){
		segundos=stoi(s);
	}
	
	void SetMilisegundos(string mili){
		milisegundos=stoi(mili);
	}
	
	void ComponeTiempo(string tiempo_leido){
		SetHoras(tiempo_leido.substr(0,2));
		SetMinutos(tiempo_leido.substr(3,2));
		SetSegundos(tiempo_leido.substr(6,2));
		SetMilisegundos(tiempo_leido.substr(9,3));
	}
	
	//------------------------------------------------
	//	Pasa a string una marca, y devuelve solo hasta la magnitud que 
	//	se desee, hasta las horas, minutos o segundos
	//	Devuelve: marca, restringida hasta la magnitud que deseemos

	string ToString(){
		/*****************************************************************/
		//Tipo enumerado de las maneras de imprimir los tiempos
		//Si hay horas: CategoriaTiempo::horas
		//Si no hay horas : CategoriaTiempo::minutos
		//Si no hay horas ni minutos: CategoriaTiempo::segundos
		//Se da por hecho que cada carrera dura más de un segundo
		enum class CategoriaTiempo{horas, minutos,segundos};
		
		CategoriaTiempo categoria;
		string resultado;
		
		//Compruebo hasta que magnitud tengo que imprimir
		if(horas!=0) categoria=CategoriaTiempo::horas;
		else if(horas==0 && minutos!=0) 
			categoria=CategoriaTiempo::minutos;
		else if(horas==0 && minutos==0)
			categoria=CategoriaTiempo::segundos;
			
		switch (categoria){
			case CategoriaTiempo::segundos:
				resultado=ToStringInt(segundos, 2, '0') + ":" + 
						  ToStringInt(milisegundos, 3, '0');
				break;
			case CategoriaTiempo::minutos:
				resultado=ToStringInt(minutos, 2, '0') + ":" +
						  ToStringInt(segundos, 2, '0') + ":" + 
						  ToStringInt(milisegundos, 3, '0');
				break;
			case CategoriaTiempo::horas:
				resultado=ToStringInt(horas, 2, '0') + ":" +
						  ToStringInt(minutos, 2, '0') + ":" +
						  ToStringInt(segundos, 2, '0') + ":" + 
						  ToStringInt(milisegundos, 3, '0');
				break;
		}
		
		return resultado;
	}
	
	
	//------------------------------------------------
	//Función que compara dos objetos de tipo Tiempo
	//Devuelve: si el primero de los dos es o no más grande
	bool EsMayor(Tiempo tiempo2){
		const int MINS_HORA=60;
		const int SEGS_MIN=60;
		const int MILISEGS_SEGS=1000;
		
		double milisegs_tiempo1=(horas*MINS_HORA*SEGS_MIN*MILISEGS_SEGS) +
							(minutos*SEGS_MIN*MILISEGS_SEGS)
							+(segundos*MILISEGS_SEGS)+milisegundos;
		double milisegs_tiempo2=(tiempo2.horas*MINS_HORA*SEGS_MIN*MILISEGS_SEGS)
								 +(tiempo2.minutos*SEGS_MIN*MILISEGS_SEGS)+
								(tiempo2.segundos*MILISEGS_SEGS)+
								tiempo2.milisegundos;
		
		return milisegs_tiempo1>milisegs_tiempo2;
	}
};


/**************************************************************************/
//Clase RegistroDeMarca: caracterizada por prueba, tiempo, fecha y licencia
class RegistroDeMarca{
private:
	string prueba; //Prueba corrida
	Fecha fecha; //Fecha en la que se realiza la marca
	Tiempo tiempo; //Tiempo en el que se finaliza dicha carrera
	string licencia; //Licencia del corredor	
	
public:
	//------------------------------------------------
	//Constructor con argumentos
	RegistroDeMarca(string p, Fecha f, Tiempo t, string l)
		:	prueba(p), 
			fecha(f), 
			tiempo(t), 
			licencia(l)
	{}
	
	//------------------------------------------------
	//Constructor sin argumentos, para poder crear un array de objetos
	RegistroDeMarca()
		:	prueba(""), 
			fecha(), 
			tiempo(), 
			licencia("")
	{}
	
	//------------------------------------------------
	//	SetMarca completa
	void SetMarca(string p, Fecha f, Tiempo t, string l){
		prueba=p;
		fecha=f;
		tiempo=t;
		licencia=l;
	}
	
	//------------------------------------------------
	//Métodos GET
	Tiempo GetTiempo(){
		return tiempo;
	}
	
	string GetLicencia(){
		return licencia;
	}
	
	Fecha GetFecha(){
		return fecha;
	}
	
	//------------------------------------------------
	// Serialización de un dato RegistroDeMarca
	
	string ToString (void) 
	{
		string cad; 
		
		cad = FormateaString (licencia , 9, TipoAjuste::derecha) + "  " + 
			  	fecha.ToString() + "  " + 
			 	tiempo.ToString(); 
			 	
		return cad; 
	}
};

/**************************************************************************/
//Clase SecuenciaMarcas: guarda una serie de marcas de la misma prueba
class SecuenciaMarcas{
private:
	static const int TAMANIO = MAX_MARCAS_EN_PRUEBA; 
	//Número máximo de marcas por prueba
	
	RegistroDeMarca vector_privado[TAMANIO];
	
	//PRE: 0<=total_utilizados<=TAMANIO
	int total_utilizados;
	
public:
	//------------------------------------------------
	//Constructor sin argumentos
	SecuenciaMarcas()
		: 	total_utilizados(0)
	{}
	
	//------------------------------------------------
	//Métodos de consulta
	int TotalUtilizados(){
		return total_utilizados;
	}
	
	int Capacidad(){
		return TAMANIO;
	}
	
	//PRE: 0<=indice<total_utilizados
	RegistroDeMarca Elemento(int indice){
		return vector_privado[indice];
		
	}
	
	//------------------------------------------------
	//Método que elimina todos los elementos de la secuencia
	void EliminaTodos(){
		total_utilizados=0;
	}
	
	//------------------------------------------------
	//Método Aniade
	//PRE: total_utilizados < TAMANIO
	void Aniade(RegistroDeMarca r){
		if(total_utilizados < TAMANIO){
			vector_privado[total_utilizados]=r;
			total_utilizados++;
		}
	}
	
	//------------------------------------------------
	//Método que modifica el elemento de la casilla indice por el nuevo
	//PRE: 0<=indice<total_utilizados
	void Modifica(int indice, RegistroDeMarca nuevo){
		if(indice>=0 && indice<total_utilizados){
			vector_privado[indice]=nuevo;
		}
	}
	
	//------------------------------------------------
	//Método que elimina el elemento de la casilla indice 
	//PRE: 0<=indice<total_utilizados
	void Elimina(int indice){
		if(indice>=0 && indice<total_utilizados){
			for(int i=indice; i<total_utilizados; i++){
				vector_privado[i]=vector_privado[i+1];
			}
			total_utilizados--;
		}
	}
	
	//------------------------------------------------
	//Método que inserta un elemento en la casilla indice 
	//PRE: 0<=indice<total_utilizados
	//	  total_utilizados<TAMANIO
	void Inserta(int indice, RegistroDeMarca nuevo){
		if(total_utilizados < TAMANIO && indice>=0 && indice<total_utilizados){
			for(int i=total_utilizados; i>indice; i--)
				vector_privado[i]=vector_privado[i-1];
			
			vector_privado[indice]=nuevo;
			total_utilizados++;
		}
	}
	
	//------------------------------------------------
	//Método que ordena la secuencia
	void OrdenaSecuencia(){
		
		if(total_utilizados>0){
			bool cambio = true;
				
			int izda = 0 ;// Para entrar
				
			while(izda<total_utilizados && cambio){
				// En cada pasada iniciamos "cambio" a false.
				// Se pondrá true si y solo si hay algún intercambio
				cambio = false;
					
				for (int c =total_utilizados-1 ; c > izda ; c--){
					
					// Intercambiar
					bool mayor=vector_privado[c-1].GetTiempo().
										 EsMayor(vector_privado[c].GetTiempo());
					   
					if(mayor){ 
						RegistroDeMarca intercambia(vector_privado[c]);
						Modifica(c, vector_privado[c-1]);
						Modifica(c-1, intercambia);
						cambio = true; // Se ha hecho un intercambio
					}
				}
				
				izda++;
			}
		}
	}

};

/**************************************************************************/
//Clase TablaDentadaMarcas: para gestionar una tabla dentada de datos
//de tipo RegistroDeMarca
class TablaDentadaMarcas{
private:
	static const int NUM_FILAS=MAX_PRUEBAS; //Máximo número de pruebas
	static const int NUM_COLS=MAX_MARCAS_EN_PRUEBA; //Máximo número de marcas 
													//por prueba
	
	RegistroDeMarca matriz_privada[NUM_FILAS][NUM_COLS];
	
	int filas_utilizadas; //PRE: 0<=filas_utilizadas<=NUM_FILAS
	int num_cols_utilizadas[NUM_FILAS]; //0<=num_cols_utilizadas[i]<=NUM_COLS
	
public:
	//------------------------------------------------
	//Constructor sin argumentos
	TablaDentadaMarcas()
		: 	filas_utilizadas(0)
	{}
	
	//------------------------------------------------
	//Constructor con argumentos
	TablaDentadaMarcas (SecuenciaMarcas primera_fila)
		: 	filas_utilizadas(0)
	{
		Aniade(primera_fila);	
	} 
	
	//------------------------------------------------
	//Constructor que recibe el numero de pruebas
	TablaDentadaMarcas(int num_pruebas): filas_utilizadas(num_pruebas)
	{
		for(int p=0; p<num_pruebas; p++){
			num_cols_utilizadas[p]=0;
		}
	}
	//------------------------------------------------
	//Métodos de consulta
	int CapacidadFilas(){
		return NUM_FILAS;
	}
	
	//------------------------------------------------
	int CapacidadColumnas(){
		return NUM_COLS;
	}
	
	//------------------------------------------------
	int FilasUtilizadas(){
		return filas_utilizadas;
	}
	
	//------------------------------------------------
	int ColumnasUtilizadas(int fila){
		return num_cols_utilizadas[fila];
	}
	
	//------------------------------------------------
	//PRE: 0<=fila<filas_utilizadas
	//	   0<=columna<=num_cols_utilizadas[fila]
	RegistroDeMarca Elemento(int fila, int columna){
		return matriz_privada[fila][columna];
	}
	
	//------------------------------------------------
	//Devuelve una fila de la matriz
	//PRE: 0<=fila<filas_utilizadas
	SecuenciaMarcas Fila(int fila){
		SecuenciaMarcas f;
		
		for(int i=0; i<num_cols_utilizadas[fila]; i++){
			f.Aniade(matriz_privada[fila][i]);
		}
		
		return f;
	}
	
	//------------------------------------------------
	//Método Aniade: aniadir una fila nueva (pruebas de otra marca)
	// PRE: fila.TotalUtilizados() <= NUM_COLS
	//	   filas_utilizadas < NUM_FILS
	void Aniade(SecuenciaMarcas fila_nueva){
		int numero_cols_fila_nueva = fila_nueva.TotalUtilizados();
		
		if(filas_utilizadas < NUM_FILAS && numero_cols_fila_nueva<=NUM_COLS){
			
			for(int c=0; c<numero_cols_fila_nueva; c++){
				matriz_privada[filas_utilizadas][c]=fila_nueva.Elemento(c);
			}
			
			num_cols_utilizadas[filas_utilizadas]=numero_cols_fila_nueva;
			filas_utilizadas++;
		}
	}
	
	//------------------------------------------------
	//Método Aniade: aniadir una marca a la fila correspondiente
	//PRE: cols_fila<NUM_COLS
	void AniadeMarca(RegistroDeMarca m, int fila){
		int cols_fila=num_cols_utilizadas[fila];
		
		if(cols_fila<NUM_COLS){
			matriz_privada[fila][cols_fila]=m;
			num_cols_utilizadas[fila]++;
		}
	}
	
	//------------------------------------------------
	//Método que inserta una fila nueva en la matriz
	//PRE: filas_utilizadas < NUM_FILS
	//	   num_cols_nueva <= NUM_COLS
	//	   fila_insercion >= 0 && fila_insercion <= filas_utilizadas
	void Inserta(SecuenciaMarcas fila_nueva, int fila_insercion){
		int num_cols_nueva = fila_nueva.TotalUtilizados();
		
		if (num_cols_nueva <= NUM_COLS && filas_utilizadas < NUM_FILAS &&
			fila_insercion >= 0 && fila_insercion <= filas_utilizadas) {
			
			for (int i = filas_utilizadas ; i > fila_insercion ; i--)
				ReemplazaFila(i, i-1);
		
			for (int j = 0; j < num_cols_nueva; j++)
				matriz_privada[fila_insercion][j] = fila_nueva.Elemento(j);
		
			filas_utilizadas++;
			num_cols_utilizadas[fila_insercion] = num_cols_nueva;
		}
	}
	
	//------------------------------------------------
	//Método que elimina una fila de la matriz
	//PRE: fila >= 0 && fila < filas_utilizadas
	void Elimina(int fila_elimina){
		for(int i=fila_elimina; i<filas_utilizadas; i++){
			ReemplazaFila(i, i+1);
		}
		
		filas_utilizadas--;
	}

	//------------------------------------------------
	// Compone y devuelve un string con el contenido de la matriz
	void SustituyeFila(int fila, SecuenciaMarcas s){
		int numero_cols_fila_nueva = s.TotalUtilizados();
		
		if(numero_cols_fila_nueva<=NUM_COLS){
			for(int c=0; c<numero_cols_fila_nueva; c++){
				matriz_privada[fila][c]=s.Elemento(c);
			}
			
			num_cols_utilizadas[fila]=numero_cols_fila_nueva;
		}
	}
	
private:
	//------------------------------------------------
	//Método auxiliar que reemplaza una fila (a_borrar), por otra
	//Lo usaremos en los métodos Inserta y Elimina
	void ReemplazaFila (int fila_a_borrar, int fila_origen){
		int columnas_utilizadas = num_cols_utilizadas[fila_origen];
		
		for (int col = 0; col < columnas_utilizadas; col++)
			matriz_privada[fila_a_borrar][col]=matriz_privada[fila_origen][col];
		
		num_cols_utilizadas[fila_a_borrar] = columnas_utilizadas;
	}
	
};

/****************************************************************************/
/****************************************************************************/
int main () {
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	//------------------------------------------------
	//	ENTRADA
	
	const string TERMINADOR = "FIN";
	

	// Este vector contendra los nombres y la posicion correspondiente en 
	// la matriz "marcas" (su fila) de cada prueba
	string pruebas[MAX_PRUEBAS];
	
	// PRE: 0 <= num_pruebas <= MAX_PRUEBAS
	int num_pruebas = 0;  

	
	//------------------------------------------------
	//	ENTRADA
	
	// Se leen las pruebas a procesar
		
	// Numero de pruebas 
	cin >> num_pruebas;
		
	for (int pos=0; pos<num_pruebas; pos++){
		cin >> pruebas[pos]; 
		
	}
		
		
	// Conociendo cuantas pruebas se van a procesar podemos crear una tabla 
	// dentada para guardar los datos leidos.
	// Todas las marcas de una prueba se guardaran en la misma fila
	
	TablaDentadaMarcas marcas (num_pruebas);

	// Leemos las marcas
	
	Fecha la_fecha; 
	Tiempo el_tiempo; 
			
	int cont_marcas = 0; // Número de líneas leidas

	// Cada elemento de una marca (prueba, fecha, licencia y tiempo) 
	// se lee en un dato string.
	string la_prueba, cad_fecha, cad_licencia, cad_tiempo;	
	
	//Lectura anticipada de la prueba
	cin >> la_prueba;

	while (la_prueba != TERMINADOR) {
		
		cont_marcas++;
			
		// Buscamos la posicion de la prueba leida en "marcas". Esta posicion
		// estaba guardada en el vector "pruebas"		
		int pos_prueba = 0; 		
		while (pruebas[pos_prueba] != la_prueba){
			pos_prueba++;  
		}
		
		// Leemos el resto de caracteristicas de la marca 
		//Fecha
		cin >> 	cad_fecha; 		
		Fecha la_fecha (cad_fecha);
		
		//Licencia				
		cin >> cad_licencia;
		
		//Tiempo
		cin >> cad_tiempo;
		Tiempo el_tiempo (cad_tiempo); // Crear objeto "Tiempo"	
	
		
		// Crearemos un objeto RegistroDeMarca y lo añadiremos a "marcas"
		// "pos_prueba" de "marcas". (Podria haber sido un objeto anonimo, pero
		// asi se ve mas claro.
		RegistroDeMarca la_marca (la_prueba, la_fecha, el_tiempo, cad_licencia);
		marcas.AniadeMarca (la_marca, pos_prueba); 

		// Leemos la siguiente prueba
		cin >> la_prueba;
		
	}
	
	
	//------------------------------------------------
	//	CALCULOS
	 
	// Ordenación de cada fila de la matriz "marcas" por "tiempo_marca"
	// Primero se extraera una copia de cada fila de la matriz
	// acto seguido se ordenara y por ultimo se sustituira la fila antigua 
	// (desordenada) por la secuencia ordenada. 
	
	for (int p=0; p<num_pruebas; p++) { // para cada prueba "p"
		
		// Extraer copia de la fila "p" 
 		SecuenciaMarcas marcas_fila_p = marcas.Fila(p);
		
		// Ordenar la secuencia 
		marcas_fila_p.OrdenaSecuencia();
		
		// Sustituir la fila "p" por la secuencia ordenada 
		marcas.SustituyeFila (p, marcas_fila_p);
			
	}
	 
	 
	 
	//------------------------------------------------
	//	SALIDA
	
	// Mostrar datos de "marcas" (ya ordenados por "tiempo_marca") 

	cout << endl; 
	cout << "Ranking final: "<< endl; 
	cout << endl; 
	
	for (int p = 0; p < num_pruebas; p++) {
				
		cout << setw(8) << pruebas[p] << endl; 
	
		for (int m = 0; m < marcas.ColumnasUtilizadas(p); m++){
			cout << '\t' << setw(3) << m+1 
			     << marcas.Elemento(p, m).ToString() << endl; 				 
		}
		cout << endl; 

	} 
	
	cout << endl; 
	
	return 0;
}
