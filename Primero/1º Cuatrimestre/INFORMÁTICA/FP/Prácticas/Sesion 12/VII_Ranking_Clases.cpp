/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 36 - VII: Reescriba la solución del ejercicio 44 de la Relación 
	de Problemas V usando clases, siguiendo las pautas dadas en el ejercicio 
	35 de esta Relación de Problemas

******************************************************************************/

#include <iostream>	// Inclusión de los recursos de E/S
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

/***************************************************************************/
//Función que pasa a string un número entero, con los espacios que se deseen.
//Si no sobran espacios, estos se rellenan
//Recibe: entero, numero de casillas y el carácter de relleno
//Devuelve: string
//PRE: entero es estrictamente un dato entero
//	   num_casillas>0
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

/***************************************************************************/
//	CLASES
/***************************************************************************/

/**************************************************************************/
//	Fecha
//	Caracterizada por día, mes y anio
class Fecha{
private: 
	int dia; 	// 	1 <= dia <= 31;
	int mes; 	//	1 <= mes <= 12;
	int anio;
	
public:
	/**************************************************************************/
	//	Constructores
	
	//--------------------------------------------------
	//	Constructor con argumentos
	Fecha(string fecha) 
	{
		ComponeFecha(fecha);
	}
	
	//--------------------------------------------------
	//	Constructor sin argumentos
	Fecha(): 
		dia(0), mes(0), anio(0)
	{}
	
	/***************************************************************/
	//	Métodos SET
	
	//--------------------------------------------------
	//	Dia
	void SetDia(string d){
		dia = stoi(d);
	}
	
	//--------------------------------------------------
	//	Mes
	void SetMes(string m){
		mes = stoi(m);
	}
	
	//--------------------------------------------------
	//	Anio
	void SetAnio(string a){
		anio = stoi(a);
	}
	
	//--------------------------------------------------
	//	Fecha completa (Dia, mes, anio)
	void ComponeFecha(string fecha_leida){
		SetDia(fecha_leida.substr(0,2));
		SetMes(fecha_leida.substr(3,2));
		SetAnio(fecha_leida.substr(6,4));
	}
	
	
	/********************************************************************/
	//	Metodos de consulta
	
	//--------------------------------------------------
	//	Pasa a string una fecha, incluyendo el mes a letra
	string ToString(){
		const int NUM_MESES = 12;
		string meses[NUM_MESES] = {	"Enero     ", "Febrero   ", "Marzo     ", 
							  		"Abril     ", "Mayo      ", "Junio     ", 
							  		"Julio     ", "Agosto    ", "Septiembre", 
									"Octubre   ", "Noviembre ", "Diciembre "};
		
		string resultado;
		
		string mes_cad = meses[mes - 1];
		
		resultado = ToStringInt(dia, 3, ' ') + " " + mes_cad + " " +
				  	ToStringInt(anio, 4, ' ');
		
		return resultado;
	}
	
};

/**************************************************************************/
//	Tiempo
//	Caracterizada por horas, minutos, segundos y milisegundos
class Tiempo{
private:
	int horas; 			//	horas < HORAS_DIA
	int minutos; 		//	minutos < MINUTOS_HORA
	int segundos; 		//	segundos < SEGUNDOS_HORA
	int milisegundos; 	//	milisegundos < MILISEGUNDOS_SEGUNDO 

public:	
	/****************************************************************/
	//	Constructores
	
	//--------------------------------------------------
	//	Constructos con argumentos
	Tiempo(string tiempo)
	{
		ComponeTiempo(tiempo);
	}					
	
	//--------------------------------------------------
	//	Constructor sin argumentos
	Tiempo(): 
		horas(0), minutos(0), segundos(0), milisegundos(0)
	{}
	
	/*****************************************************************/
	//	Métodos SET
	
	//--------------------------------------------------
	//	Horas
	void SetHoras(string h){
		horas = stoi(h);
	}
	
	//--------------------------------------------------
	//	Minutos
	void SetMinutos(string m){
		minutos = stoi(m);
	}
	
	//--------------------------------------------------
	//	Segundos
	void SetSegundos(string s){
		segundos = stoi(s);
	}
	
	void SetMilisegundos(string mili){
		milisegundos = stoi(mili);
	}
	
	//--------------------------------------------------
	//	Tiempo completo (Horas, Minutos, Segundos, Milisegundos
	void ComponeTiempo(string tiempo_leido){
		SetHoras(tiempo_leido.substr(0,2));
		SetMinutos(tiempo_leido.substr(3,2));
		SetSegundos(tiempo_leido.substr(6,2));
		SetMilisegundos(tiempo_leido.substr(9,3));
	}
	
	
	/***************************************************************/
	//	Metodos de consulta
	
	//--------------------------------------------------
	//	Se pasara a string una marca
	//	La marca se imprimira en pantalla hasta la maginutd minima usada
	string ToString(){
		//Usaremos un tipo enumerado para comprobar hasta que magnitud se
		//debera pintar
		enum class CategoriaTiempo{horas, minutos,segundos};
		
		CategoriaTiempo categoria;
		string resultado;
		
		//Compruebo hasta que magnitud tengo que imprimir
		if (horas != 0){
			categoria = CategoriaTiempo::horas;
			
		} else if (minutos != 0){
			categoria = CategoriaTiempo::minutos;
			
		} else {
			categoria = CategoriaTiempo::segundos;
			
		}
		
		//Formo el string
		switch (categoria){
			case CategoriaTiempo::segundos:
				resultado = ToStringInt(segundos, 2, '0') + ":" + 
						  	ToStringInt(milisegundos, 3, '0');
				break;
				
			case CategoriaTiempo::minutos:
				resultado = ToStringInt(minutos, 2, '0') + ":" +
						  	ToStringInt(segundos, 2, '0') + ":" + 
						  	ToStringInt(milisegundos, 3, '0');
				break;
				
			case CategoriaTiempo::horas:
				resultado =	ToStringInt(horas, 2, '0') + ":" +
						  	ToStringInt(minutos, 2, '0') + ":" +
						  	ToStringInt(segundos, 2, '0') + ":" + 
						  	ToStringInt(milisegundos, 3, '0');
				break;
		}
		
		return resultado;
	}
	
	//--------------------------------------------------
	//	Se compararan dos objetos de tipo Tiempo
	bool EsMayor(Tiempo tiempo2){
		const int MINS_HORA = 60;
		const int SEGS_MIN = 60;
		const int MILISEGS_SEGS = 1000;
		
		double milisegs_tiempo1 = (horas*MINS_HORA*SEGS_MIN*MILISEGS_SEGS) +
								  (minutos*SEGS_MIN*MILISEGS_SEGS) +
								  (segundos*MILISEGS_SEGS) + 
								  milisegundos;
								  
		double milisegs_tiempo2 = 
							(tiempo2.horas*MINS_HORA*SEGS_MIN*MILISEGS_SEGS) + 
							(tiempo2.minutos*SEGS_MIN*MILISEGS_SEGS) +
							(tiempo2.segundos*MILISEGS_SEGS) +
							tiempo2.milisegundos;
		
		return (milisegs_tiempo1 > milisegs_tiempo2);
	}
};

/**************************************************************************/
//	RegistroDeMarca
//	Caracterizada por prueba, tiempo, fecha y licencia
class RegistroDeMarca{
private:
	string prueba; 		//Prueba corrida
	Fecha fecha; 		//Fecha en la que se realiza la marca
	Tiempo tiempo; 		//Tiempo en el que se finaliza dicha carrera
	string licencia; 	//Licencia del corredor	
	
public:
	/******************************************************************/
	//	Constructores
	
	//--------------------------------------------------
	//	Constructor con argumentos
	RegistroDeMarca(string p, Fecha f, Tiempo t, string l)
		:	prueba(p), 
			fecha(f), 
			tiempo(t), 
			licencia(l)
	{}
	
	//--------------------------------------------------
	//	Constructor sin argumentos
	RegistroDeMarca(): 
		prueba(""), fecha(), tiempo(), licencia("")
	{}
	
	/******************************************************************/
	//	Metodo SET
	
	//--------------------------------------------------
	//	Marca completa
	void SetMarca (string p, Fecha f, Tiempo t, string l){
		prueba = p;
		fecha = f;
		tiempo = t;
		licencia = l;
	}
	
	/******************************************************************/
	//	Métodos GET
	
	//--------------------------------------------------
	//	Tiempo
	Tiempo GetTiempo(){
		return tiempo;
	}
	
	//--------------------------------------------------
	//	Licencia
	string GetLicencia(){
		return licencia;
	}
	
	//--------------------------------------------------
	//	Fecha
	Fecha GetFecha(){
		return fecha;
	}
};

/****************************************************************************/
/****************************************************************************/
int main () {
	const string TERMINADOR = "FIN";
	
	//Array que se usa para guardar los datos leidos y procesados
	const int MAX_PRUEBAS = 20;
	const int MAX_MARCAS_EN_PRUEBA = 100;
	RegistroDeMarca marcas[MAX_PRUEBAS][MAX_MARCAS_EN_PRUEBA];
	
	//Número de filas ocupadas de "marcas"
	int num_pruebas; // PRE: 0 <= num_pruebas <= MAX_PRUEBAS
	
	//Número de marcas por prueba
	//PRE: 0 <= num_marcas_en_prueba[i] <= MAX_MARCAS_EN_PRUEBA
	int num_marcas_en_prueba[MAX_PRUEBAS]={0}; 
	
	//----------------------------------
	//	ENTRADA
	
	//Leo el numero de pruebas que hay
	cin >> num_pruebas;
	
	//Leo el nombre de cada prueba
	string nombre_pruebas[MAX_PRUEBAS];
	
	for (int i = 0; i < num_pruebas; i++){
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
		
		//Leo la fecha
		string fecha;
		cin >> fecha;
		
		//Creo el objeto tipo Fecha
		Fecha fec(fecha);
	
		//Leo licencia
		string licencia;
		cin >> licencia ;
		
		//Leo tiempo
		string tiempo;
		cin >> tiempo;
		
		//Creo el objeto tipo Tiempo
		Tiempo t(tiempo);
		
		//Establezco la marca
		marcas[p][num_marcas_en_prueba[p]].SetMarca(prueba, fec, t, licencia);
		
		//Actualizamos el numero de marcas registradas
		num_marcas_en_prueba[p]++;
		
		//Leemos la siguiente linea
		cin >> prueba;
	}
	
	//----------------------------------
	//	CALCULOS
	
	for (int n = 0; n < num_pruebas; n++){
		// Ordenaremos la matriz utilizando el algoritmo de ordenacon
		// por seleccion
		for (int izda = 0; izda < num_marcas_en_prueba[n] ; izda++){
			// Calcular el mínimo entre "izda" y "marcas_registradas"-1
			Tiempo maximo; 
			int pos_max = izda; // Posición del maximo
			
			for (int i = izda + 1; i < num_marcas_en_prueba[n] ; i++){
				if (!maximo.EsMayor(marcas[n][i].GetTiempo())){ // Nuevo maximo
					maximo = marcas[n][i].GetTiempo();
					pos_max = i;
				}
			}
			
			// Intercambiar los valores guardados en "izda" y "pos_min"
			RegistroDeMarca intercambia = marcas[n][izda];
			marcas[n][izda] = marcas[n][pos_max];
			marcas[n][pos_max] = intercambia;
		}
	}
	
	//Muestro los resultados
	cout << endl;
	cout << "Ranking general" << endl << endl;
	
	for(int p = 0; p < num_pruebas; p++){
		cout << nombre_pruebas[p] << endl ;
		
		for (int c = num_marcas_en_prueba[p]; c > 0; c--){
			cout << "\t" << (num_marcas_en_prueba[p] - c + 1) << ". " 
				 << setw(10) << marcas[p][c-1].GetLicencia() << " "
				 << marcas[p][c-1].GetFecha().ToString() << " "
				 << marcas[p][c-1].GetTiempo().ToString()
				 << endl;
		}
	}
	
	return 0;
}
