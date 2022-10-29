/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 31 - II: Este programa leerá la hora actual (minutos y segundos, 
	por separado) y una cantidad de dinero (en euros) y nos indicará hasta qué 
	hora podemos tener el coche aparcado si vamos a pagar con la cantidad 
	especificada.
	Implementar los filtros adecuados al problema.
	
	Si se dispone de 5 euros y 25 céntimos deberá indicar el valor 5.25 cuando 
	se le pida el dinero disponible

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <iomanip>
using namespace std;

int main () {
	// Constantes
	const int HORAS_DIA = 24;	
	const int MINS_HORA = 60;	
	const int MINS_DIA  = HORAS_DIA*MINS_HORA;
		
	const double CANT_MUY_CORTA =  	0.0412;
	const double CANT_CORTA     =  	0.0370;
	const double CANT_MEDIA     =  	0.0311;
	const double CANT_LARGA 	=  	0.0305;
	const double CANT_MUY_LARGA	=	0.0270;
	const double CANT_MAX_DIA   =	35.0000;

	const int MINS_MUY_CORTA    =  	30;
	const int MINS_CORTA     	=  	90;
	const int MINS_MEDIA    	= 	120;	
	const int MINS_LARGA 		= 	660;
	const int MINS_MUY_LARGA 	= 	900;
	
	
	/*
               30         90  	    120         660 		900
		0.0412     0.0370      0.0311     0.0305    0.0270 			35	
     |---------|----------|----------|----------|------------|--------------     
      MUY_CORTA   CORTA       MEDIA     LARGA     MUY_LARGA		PLANA
	*/
	
	// Datos de entrada
	int hora_inic, minuto_inic;
	double dinero_introducido;
	
	bool hora_inic_ok = false; 
	bool minuto_inic_ok = false;
	bool dinero_introducido_ok = false; 
	
			
	/* *******************************************
	//			 Entrada de datos				//
	*********************************************/
	
	//Introducimos la hora
	cout << "Introduzca hora inicial:" << endl;
	cout << "\tHora:    ";
	cin >> hora_inic;
	
 	hora_inic_ok = (hora_inic >= 0 && hora_inic < HORAS_DIA);
	
	while (!hora_inic_ok){
		cout << "ERROR: El valor introducido no es correcto. Vuelva a "
			 << "intentarlo" << endl;
			
		cout << endl;
		cout << "\tHora:    ";
		cin >> hora_inic;
		
	 	hora_inic_ok = (hora_inic >= 0 && hora_inic < HORAS_DIA);
	}
	
	//Introducimos los minutos
	cout << "\tMinuto:  ";
	cin >> minuto_inic;

 	minuto_inic_ok = (minuto_inic >= 0 && minuto_inic < MINS_HORA);

	while (!minuto_inic_ok){
		cout << "ERROR: El valor introducido no es correcto. Vuelva a "
			 << "intentarlo" << endl;
		
		cout << endl;
		cout << "\tMinuto:  ";
		cin >> minuto_inic;
	
	 	minuto_inic_ok = (minuto_inic >= 0 && minuto_inic < MINS_HORA);
	}
	
	//Pedimos el dinero introducido
    cout << "Dinero introducido:" << endl;
	cout << "\tDinero:    ";
	cin >> dinero_introducido;	
	
 	dinero_introducido_ok = (dinero_introducido >= 0);
 	
 	while (!dinero_introducido_ok) {
		cout << "ERROR: El valor introducido no es correcto. Vuelva a "
			 << "intentarlo" << endl;
		
		cout << endl;
		cout << "\tDinero:    ";
		cin >> dinero_introducido;	
		
	 	dinero_introducido_ok = (dinero_introducido >= 0);
	}
	cout << endl;
	
	/* *******************************************
	// 					Cálculos				//
	*********************************************/	
	
	int tiempo = 0;
	double dinero_restante = dinero_introducido;
		
	if (dinero_introducido < CANT_MAX_DIA){
		//Estancia muy corta
		while (dinero_restante >= CANT_MUY_CORTA && tiempo <= MINS_MUY_CORTA){
			dinero_restante -= CANT_MUY_CORTA;
			tiempo++;
			
		}
		
		//Estancia corta
		while (dinero_restante >= CANT_CORTA && tiempo <= MINS_CORTA){
			dinero_restante -= CANT_CORTA;
			tiempo++;
			
		}
		
		//Estancia media
		while (dinero_restante >= CANT_MEDIA && tiempo <= MINS_MEDIA){
			dinero_restante -= CANT_MEDIA;
			tiempo++;
			
		}
		
		//Estancia larga
		while (dinero_restante >= CANT_LARGA && tiempo <= MINS_LARGA){
			dinero_restante -= CANT_LARGA;
			tiempo++;
			
		}
		
		//Estancia muy larga
		while (dinero_restante >= CANT_MUY_LARGA && tiempo <= MINS_MUY_LARGA){
			dinero_restante -= CANT_MUY_LARGA;
			tiempo++;
			
		}
		
	} else {
		tiempo = MINS_DIA;
		dinero_restante -= CANT_MAX_DIA;
		
	}
	
	//Calculamos la hora de salida	
	int mins_hora_inic = (hora_inic * MINS_HORA) + minuto_inic;
	
	int mins_hora_salida = mins_hora_inic + tiempo;
	
	int hora_salida, mins_salida;
	
	hora_salida = mins_hora_salida / MINS_HORA;
	mins_salida = mins_hora_salida % MINS_HORA;
	
	bool dia_siguiente = false;
	
	if (hora_salida >= HORAS_DIA){
		hora_salida -= HORAS_DIA;
		
		dia_siguiente = true;
	}

	/* ******************************************
				 Salida de datos
	********************************************/
	if (dia_siguiente){
		cout << "Puede tener el coche aparcado hasta las " 
		 	 << setfill ('0') << setw (2) << hora_salida << ":" 
			 << setfill ('0') << setw (2) << mins_salida 
			 << " del día siguiente." << endl;
		 
	} else {
		cout << "Puede tener el coche aparcado hasta las " 
		 	 << setfill ('0') << setw (2) << hora_salida << ":" 
			 << setfill ('0') << setw (2) << mins_salida << endl;
		
	}
	
	//Mostramos el cambio
	cout << endl;
	cout << "Han sobrado " << fixed << setprecision (2) << dinero_restante 
		 << " euros" << endl;
	
	
	return 0;
}
