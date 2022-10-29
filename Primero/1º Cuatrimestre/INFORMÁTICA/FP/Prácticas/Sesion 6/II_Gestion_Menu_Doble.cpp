/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 81 - II: Este programa presentará un menú principal para que el 
	usuario pueda elegir entre las siguientes opciones:
	
		A –> Calcular adición.
		P –> Calcular producto.
		X –> Salir.
		
	Si el usuario elige en el menú principal:
	
	a) Salir, el programa terminará su ejecución.
	b) Calcular adición se presenta un menú (secundario) para que el usuario 
	pueda elegir entre las siguientes opciones:
		
		S–>Calcular suma.
		R–>Calcular resta.
		X–>Salir.
		
	c) Calcular producto se presenta un menú (secundario) para que el usuario 
	pueda elegir entre las siguientes opciones:
	
		M–>Calcular multiplicación.
		D–>Calcular división.
		X–>Salir.
		
	En las operaciones seleccionadas desde los menús secundarios el programa 
	pedirá dos números reales, realizará la operación seleccionada, mostrará el 
	resultado y volverá a mostrar el menú secundario seleccionado anteriormente.
	
	En los dos menús secundarios la selección de Salir hace que el programa 
	vuelva a mostrar el menú principal.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S

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
		cout << "\t| Menú principal |" << endl;
		cout << "\t==================" << endl;
    	cout << "\t (A) ---> Calcular adición" << endl;
    	cout << "\t (P) ---> Calcular producto" << endl;
    	cout << "\t (X) ---> Salir" << endl;
    	
    	cin >> menu_principal;
    	menu_principal = toupper (menu_principal);
    	
    	switch (menu_principal){
    		case 'A':
    			while (!volver){
					cout << endl;
	    			cout << "\t + Menú adición +" << endl;
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
			    			cout << "ERROR: Caracter inválido." << endl << endl;
			    		
					}
				} //Fin menú adición
				break;
		    	
    		case 'P':
    			while (!volver){
					cout << endl;
	    			cout << "\t * Menú producto *" << endl;
	    			cout << "\t -----------------" << endl;
					cout << "\t (M) ---> Calcular multiplicación" << endl;
			    	cout << "\t (D) ---> Calcular división" << endl;
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
			    			cout << "ERROR: Caracter inválido." << endl << endl;
			    		
					}
				} //Fin menú producto
				break;
				
    		case 'X':
    			salir = true;
    			break;
    			
    		default:
    			cout << "ERROR: Caracter inválido." << endl << endl;
    			
		}
	}
	
	return 0;
}
