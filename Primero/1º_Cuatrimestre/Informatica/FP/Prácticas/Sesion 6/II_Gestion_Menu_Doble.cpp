/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 81 - II: Este programa presentar� un men� principal para que el 
	usuario pueda elegir entre las siguientes opciones:
	
		A �> Calcular adici�n.
		P �> Calcular producto.
		X �> Salir.
		
	Si el usuario elige en el men� principal:
	
	a) Salir, el programa terminar� su ejecuci�n.
	b) Calcular adici�n se presenta un men� (secundario) para que el usuario 
	pueda elegir entre las siguientes opciones:
		
		S�>Calcular suma.
		R�>Calcular resta.
		X�>Salir.
		
	c) Calcular producto se presenta un men� (secundario) para que el usuario 
	pueda elegir entre las siguientes opciones:
	
		M�>Calcular multiplicaci�n.
		D�>Calcular divisi�n.
		X�>Salir.
		
	En las operaciones seleccionadas desde los men�s secundarios el programa 
	pedir� dos n�meros reales, realizar� la operaci�n seleccionada, mostrar� el 
	resultado y volver� a mostrar el men� secundario seleccionado anteriormente.
	
	En los dos men�s secundarios la selecci�n de Salir hace que el programa 
	vuelva a mostrar el men� principal.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S

using namespace std;

int main() {
    char menu_principal;
    char submenu;
    
    double x;
    double y;
    double resultado;
    char signo;
    
    bool volver;
    bool salir = false;
    
    while (!salir) {
    	volver = false;
    	
    	cout << "\t==================" << endl;
		cout << "\t| Men� principal |" << endl;
		cout << "\t==================" << endl;
    	cout << "\t (A) ---> Calcular adici�n" << endl;
    	cout << "\t (P) ---> Calcular producto" << endl;
    	cout << "\t (X) ---> Salir" << endl;
    	
    	cin >> menu_principal;
    	menu_principal = toupper (menu_principal);
    	
    	switch (menu_principal){
    		case 'A':
    			while (!volver){
					cout << endl;
	    			cout << "\t + Men� adici�n +" << endl;
	    			cout << "\t-----------------" << endl;
					cout << "\t (S) ---> Calcular suma" << endl;
			    	cout << "\t (R) ---> Calcular resta" << endl;
			    	cout << "\t (X) ---> Volver" << endl;
			    	
			    	cin >> submenu;
			    	submenu = toupper (submenu);
			    	
			    	switch (submenu){
			    		case 'S':
			    		case 'R':
			    			cout << "x = ";
			    			cin >> x;
			    			
			    			cout << "y = ";
			    			cin >> y;
			    			
			    			if (submenu == 'S'){
								resultado = x + y;
								signo = '+';
							} else {
								resultado = x - y;
								signo = '-';
							}
							cout << x << " " << signo << " " << y << " = " 
								 << resultado << endl;
							
							break;
							
			    		case 'X':
			    			volver = true;
			    			break;
			    			
			    		default:
			    			cout << "ERROR: Caracter inv�lido." << endl << endl;
			    		
					}
				} //Fin men� adici�n
				break;
		    	
    		case 'P':
    			while (!volver){
					cout << endl;
	    			cout << "\t * Men� producto *" << endl;
	    			cout << "\t -----------------" << endl;
					cout << "\t (M) ---> Calcular multiplicaci�n" << endl;
			    	cout << "\t (D) ---> Calcular divisi�n" << endl;
			    	cout << "\t (X) ---> Volver" << endl;
			    	
			    	cin >> submenu;
			    	submenu = toupper (submenu);
			    	
			    	switch (submenu){
			    		case 'M':
			    		case 'D':
			    			cout << "x = ";
			    			cin >> x;
			    			
			    			cout << "y = ";
			    			cin >> y;
			    			
			    			if (submenu == 'M'){
								resultado = x * y;
								signo = '*';
							} else {
								resultado = x / y;
								signo = '/';
							}
							cout << x << " " << signo << " " << y << " = " 
								 << resultado << endl;
							
							break;
							
			    		case 'X':
			    			volver = true;
			    			break;
			    			
			    		default:
			    			cout << "ERROR: Caracter inv�lido." << endl << endl;
			    		
					}
				} //Fin men� producto
				break;
				
    		case 'X':
    			salir = true;
    			break;
    			
    		default:
    			cout << "ERROR: Caracter inv�lido." << endl << endl;
    			
		}
	}
	
	return 0;
}
