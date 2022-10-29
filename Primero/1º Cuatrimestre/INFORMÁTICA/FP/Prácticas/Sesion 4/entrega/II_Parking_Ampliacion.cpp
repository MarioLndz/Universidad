/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 17 - II: La tabla para el cálculo del precio a pagar en un 
	parking para el 2020 es la siguiente, teniendo en cuenta la actualización
	con el nuevo tramo de la tarifa:

	Desde el minuto 0 al 30 (MUY CORTA): 	0.0412 euros cada minuto
	Desde el minuto 31 al 90 (CORTA): 		0.0370 euros cada minuto
	Desde el minuto 91 al 120 (MEDIA): 		0.0311 euros cada minuto
	Desde el minuto 121 al 660 (LARGA):		0.0305 euros cada minuto
	Desde el minuto 661 al 900 (MUY LARGA): 0.0270 euros cada minuto 
	Desde el minuto 901 hasta máximo 24 horas (MAXIMA): 35.00 euros

	La hora de entrada puede pertenecer al día inmediatamente anterior.
	Se supone que NO transcurren más de 24 horas entre la hora de entrada y 
	la hora de salida.  
	
	NOTA: no se consideran los segundos

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <iomanip>
using namespace std;

int main () {
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
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

	const int MINS_MUY_CORTA     =  30;
	const int MINS_CORTA     =  90;
	const int MINS_MEDIA     = 120;	
	const int MINS_LARGA = 660;
	const int MINS_MUY_LARGA = 900;

	/*
               30         90  	    120         660 		900
		0.0412     0.0370      0.0311     0.0305    0.0270 			35	
     |---------|----------|----------|----------|------------|***************     
      MUY_CORTA   CORTA       MEDIA     LARGA     MUY_LARGA		PLANA
	*/
	
	// Datos de entrada
	int hora_inic, minuto_inic;
	int hora_fin, minuto_fin;
	
	int num_mins;
	
	bool hora_inic_ok = false; 
	bool hora_fin_ok  = false; 
	bool minuto_inic_ok = false; 
	bool minuto_fin_ok  = false; 
	bool datos_ok = false; 
	
	// Valores calculados
	
	double precio;
	bool   tarifa_24h;	

	int num_mins_muy_larga = 0;
	int num_mins_larga     = 0;
	int num_mins_media     = 0;
	int num_mins_corta     = 0;
	int num_mins_muy_corta = 0;
	
	double cant_muy_larga = 0.0;
	double cant_larga     = 0.0;
	double cant_media     = 0.0;
	double cant_corta     = 0.0;
	double cant_muy_corta = 0.0;
		
			
	// Entrada de datos
	
	cout << "Introduzca hora inicial:" << endl;
	cout << "\tHora:    ";
	cin >> hora_inic;
	
 	hora_inic_ok = (hora_inic >= 0 && hora_inic < HORAS_DIA);
	
	if (hora_inic_ok) {

		cout << "\tMinuto:  ";
		cin >> minuto_inic;

 		minuto_inic_ok = (minuto_inic >= 0 && minuto_inic < MINS_HORA);

		if (minuto_inic_ok) {
	
		    cout << "Introduzca hora final:" << endl;
			cout << "\tHora:    ";
			cin >> hora_fin;	
			
		 	hora_fin_ok = (hora_fin >= 0 && hora_fin < HORAS_DIA);
		 		 
			if (hora_fin_ok) {
	
				cout << "\tMinuto:  ";
				cin >> minuto_fin;
		 
 				minuto_fin_ok = (minuto_fin >= 0 && minuto_fin < MINS_HORA);	
		 		
				if (minuto_fin_ok) {
					datos_ok = true; 
				}
			} // if (hora_fin_ok)
			
		} // if (minuto_inic_ok) 
		
	} //  if (hora_inic_ok) 
			
	// Cálculos
	
	if (datos_ok) {
			
		// 1. Calcular número de minutos entre la entrada y la salida
		
		int mins_hora_inic = (hora_inic*MINS_HORA) + minuto_inic;
		int mins_hora_fin = (hora_fin*MINS_HORA) + minuto_fin;
	
		num_mins = mins_hora_fin - mins_hora_inic;
	
		// Si el número de minutos es negativo significa que la hora de entrada
		// corresponde al día anterior
	
		if (num_mins < 0) {
	
			// (MINS_DIA - mins_hora_inic) + mins_hora_fin
			// MINS_DIA - mins_hora_inic + mins_hora_fin
			// MINS_DIA + (mins_hora_fin - mins_hora_inic)
			// MINS_DIA + num_mins
	
			num_mins = MINS_DIA + num_mins;
		}
		
		// 2. Determinar la tarifa por partes
		
		precio = 0; 
	
		int num_mins_quedan = num_mins;
		
		
		// El caso más simple es una larguísima permanencia --> precio único
		if (num_mins > MINS_MUY_LARGA) {
	/*
               30         90  	    120         660 		900
		0.0412     0.0370      0.0311     0.0305    0.0270 			35	
     |---------|----------|----------|----------|------------|***************     
      MUY_CORTA   CORTA       MEDIA     LARGA     MUY_LARGA		PLANA
	*/
			precio = CANT_MAX_DIA;
			tarifa_24h = true;
		}
			
		else { // Si no, hay que calcular el precio por tramo
	
			tarifa_24h = false;
	
			if (num_mins > MINS_LARGA) { // Muy larga estancia
	
	/*
               30         90  	    120         660 		900
		0.0412     0.0370      0.0311     0.0305    0.0270 			35	
     |---------|----------|----------|----------|************|----------------
      MUY_CORTA   CORTA       MEDIA     LARGA     MUY_LARGA		PLANA
	*/
				num_mins_muy_larga = num_mins_quedan - MINS_LARGA;
				cant_muy_larga = num_mins_muy_larga  * CANT_MUY_LARGA;
				precio += cant_muy_larga;
				num_mins_quedan = MINS_LARGA;
			}		
			
			if (num_mins > MINS_MEDIA) { // Larga estancia
		
	/*
               30         90  	    120         660 		900
		0.0412     0.0370      0.0311     0.0305    0.0270 			35	
     |---------|----------|----------|***********|------------|---------------     
      MUY_CORTA   CORTA       MEDIA     LARGA     MUY_LARGA		PLANA
	*/	
				num_mins_larga = num_mins_quedan - MINS_MEDIA;
				cant_larga = num_mins_larga * CANT_LARGA;
				precio += cant_larga;
				num_mins_quedan = MINS_MEDIA;
			}
	
			if (num_mins_quedan > MINS_CORTA) { // Media estancia
			
	/*
               30         90  	    120         660 		900
		0.0412     0.0370      0.0311     0.0305    0.0270 			35	
     |---------|----------|***********|----------|------------|--------------     
      MUY_CORTA   CORTA       MEDIA     LARGA     MUY_LARGA		PLANA
	*/
				num_mins_media = num_mins_quedan - MINS_CORTA;
				cant_media = num_mins_media * CANT_MEDIA;
				precio += cant_media;
				num_mins_quedan = MINS_CORTA;
			}
	
			if (num_mins_quedan > MINS_MUY_CORTA){ //Corta estancia
	/*
               30         90  	    120         660 		900
		0.0412     0.0370      0.0311     0.0305    0.0270 			35	
     |---------|***********|----------|----------|------------|--------------     
      MUY_CORTA   CORTA       MEDIA     LARGA     MUY_LARGA		PLANA
	*/
				num_mins_corta = num_mins_quedan - MINS_MUY_CORTA;
				cant_corta = num_mins_corta * CANT_CORTA;
				precio += cant_corta;
				num_mins_quedan = MINS_MUY_CORTA;
			}
			// Muy corta estancia
		
	/*
               30         90  	    120         660 		900
		0.0412     0.0370      0.0311     0.0305    0.0270 			35	
     |**********|----------|----------|----------|------------|--------------    
      MUY_CORTA   CORTA       MEDIA     LARGA     MUY_LARGA		PLANA
	*/
				
			num_mins_muy_corta = num_mins_quedan;
			cant_muy_corta = num_mins_muy_corta * CANT_MUY_CORTA;
			precio += cant_muy_corta;
	
		}
	}

	// Resultado

	if (datos_ok) {
			
		cout << endl;
		cout << "Tarifa final =  " <<setw(6)<< setprecision(2)<< precio<< endl;
		cout << endl;
		cout << "Minutos de estancia = " << num_mins << endl;
		cout << endl;
	
		if (tarifa_24h)
		
			cout << "\tSe ha aplicado tarifa maxima." << endl;
			
		else {
			
			cout << "\tMuy corta = " << setw(3)
			     << num_mins_muy_corta << " (x "
				 << setw(5) << setprecision(4) << CANT_MUY_CORTA << ") = "
				 << setw(5) << setprecision(2) << cant_muy_corta << endl;
			cout << "\tCorta     = " << setw(3)
			     << num_mins_corta << " (x "
				 << setw(5) << setprecision(4) << CANT_CORTA << ") = "
				 << setw(5) << setprecision(2) << cant_corta << endl;
			cout << "\tMedia     = " << setw(3)
			     << num_mins_media << " (x "
				 << setw(5) << setprecision(4) << CANT_MEDIA << ") = "
				 << setw(5) << setprecision(2) << cant_media << endl;
			cout << "\tLarga     = " << setw(3)
			     << num_mins_larga << " (x "
				 << setw(5) << setprecision(4) << CANT_LARGA << ") = "
				 << setw(5) << setprecision(2) << cant_larga << endl;
			cout << "\tMuy Larga = " << setw(3)
			     << num_mins_muy_larga << " (x "
				 << setw(5) << setprecision(4) << CANT_MUY_LARGA << ") = "
				 << setw(5) << setprecision(2) << cant_muy_larga << endl;
			cout << "                                     "
				 << "-----" << endl;
			cout << "                                     "
				 << setw(5) << setprecision(2) << precio << endl;
		}
		cout << endl;

	}
	
	else { // !datos_ok
	
		if (!hora_inic_ok) {
			cout << endl; 
			cout << "ERROR: Hora inicial incorrecta."<< endl; 
			cout << endl; 
		}
		else if (!minuto_inic_ok) {
			cout << endl; 
			cout << "ERROR: Minuto inicial incorrecto."<< endl; 
			cout << endl; 
		}
		else if (!hora_fin_ok) {
			cout << endl; 
			cout << "ERROR: Hora final incorrecta."<< endl; 
			cout << endl; 
		} 
		else {
 			cout << endl; 
			cout << "ERROR: Minuto final incorrecto."<< endl; 
			cout << endl; 	
		 }	 
	}
	return 0;
}
