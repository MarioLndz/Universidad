/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 25 - VI: Implementar una clase RedSocial para gestionar
	una red social. La red debe almacenar los nombres de los usuarios y las 
	relaciones de amistad.

******************************************************************************/

#include <iostream>	// Inclusión de los recursos de E/S
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

/***************************************************************************
//	Clase RedSocial para gestionar una red social. 
	
	La red almacenara los nombres de los usuarios y las relaciones
	de amistad.
***************************************************************************/
class RedSocial {
private:
	static const int MAXIMO_USUARIOS = 100;
	string usuarios[MAXIMO_USUARIOS];
	bool relaciones_amistad[MAXIMO_USUARIOS][MAXIMO_USUARIOS];
	//la componente (i; j) es true, si el usuario i es amigo del usuario j, 
	//y false, en otro caso. Asumiremos que las relaciones de amistad son 
	//simétricas, por lo que la matriz binaria también lo es.
	
	int usuarios_utiles;

public:
	//----------------------------------------------
	//	Constructor sin argumentos, crea una red vacía
	RedSocial():usuarios_utiles(0)
	{
		//Inicializo toda la matriz de relaciones a false
		for(int f=0; f<MAXIMO_USUARIOS; f++){
			for(int c=0; f<MAXIMO_USUARIOS; f++){
				relaciones_amistad[f][c]=false;
			}
		}
	}
	
	//----------------------------------------------
	//	Devuelve usuarios_utiles
	
	int NumUsuarios(){
		return usuarios_utiles;
	}
	
	//----------------------------------------------
	//Añade un usuario a la red
	
	void AniadeUsuario (string usr){
		if(!Existe(usr)){
			usuarios[usuarios_utiles]=usr;
			usuarios_utiles++;
		}
	}
	
	//----------------------------------------------
	//	Elimina un usuario de la red, y sus amistades
	//	PRE: usr existe
	
	void EliminaUsuario (string usr){
		
		int pos_encontrado = PosicionUsuarioBuscado (usr);
		
		if(pos_encontrado != -1){
			int tope = usuarios_utiles-1;
			for (int i = pos_encontrado ; i < tope ; i++){
				usuarios[i] = usuarios[i+1];
				
				//Borro también las relaciones de amistad
				for(int j=pos_encontrado; j< tope; j++){
					relaciones_amistad[i][j]=relaciones_amistad[i+1][j];
					relaciones_amistad[j][i]=relaciones_amistad[j][i+1];
				}
			}
				
			usuarios_utiles--;
		}
	}
	
	//----------------------------------------------
	//	Indica si un usuario existe en la red
	
	bool Existe (string usr){
		int i = 0;
		bool encontrado=false;
		
		while (i < usuarios_utiles && !encontrado){
			if (usuarios[i] == usr){
				encontrado = true;
			}
			else i++;
		}
		
		return encontrado;
	}
	
	//----------------------------------------------
	//	En la matriz de las relaciones pone true en la interseccion de las 
	//	casillas de esos usuarios
	//	PRE: usr1 y usr2 deben existir, usr1 y usr2 deben ser distintos
	
	void HacerAmigos(string usr1, string usr2){
		if(Existe(usr1) && Existe(usr2) && usr1!=usr2){	
			int pos_usr1=PosicionUsuarioBuscado(usr1);
			int pos_usr2=PosicionUsuarioBuscado(usr2);
				
			relaciones_amistad[pos_usr1][pos_usr2]=true;
			relaciones_amistad[pos_usr2][pos_usr1]=true;
		}
	}
	
	//----------------------------------------------
	//	En la matriz de las relaciones pone false en la interseccion de las 
	//	casillas de esos usuarios
	//	PRE: usr1 y usr2 deben existir
	
	void DeshacerAmigos(string usr1, string usr2){
		if(Existe(usr1) && Existe(usr2)){
			int pos_usr1=PosicionUsuarioBuscado(usr1);
			int pos_usr2=PosicionUsuarioBuscado(usr2);
				
			relaciones_amistad[pos_usr1][pos_usr2]=false;
			relaciones_amistad[pos_usr2][pos_usr1]=false;
		}
		
	}
	
	//----------------------------------------------
	// 	Indica si dos usuarios son amigos
	// 	PRE: usr1 y usr2 existen y son distintos
	
	bool SonAmigos(string usr1, string usr2){
		int pos_usr1=PosicionUsuarioBuscado(usr1);
		int pos_usr2=PosicionUsuarioBuscado(usr2);
				
		return relaciones_amistad[pos_usr1][pos_usr2];
		
	}
	
	//----------------------------------------------
	//	Dado un usuario A de la red, sugiera un amigo potencial para A
	//	Un amigo potencial es aquel usuario de la red (no amigo de A) que tiene 
	//	más amigos en común con A.
	//	PRE: usr existe
	//	POST: amigo_potencial existe
	
	string SugerenciaAmigoPotencialDe(string usr){
		int pos_usr=PosicionUsuarioBuscado(usr);
		
		int max_amigos_comun=0;
		int pos_amigo_potencial=0;
		
		//Va recorriendo todos los usuarios y comparando los amigos en 
		//común con usr
		for(int u=0; u<usuarios_utiles; u++){
			int amigos_comun=0;
			
			if(usr!=usuarios[u] && !SonAmigos(usr, usuarios[u])){
				for(int i=0; i<usuarios_utiles; i++){
					if(relaciones_amistad[pos_usr][i] && 
						relaciones_amistad[u][i]){
						
						amigos_comun++;	
					}
				}
				if(amigos_comun>max_amigos_comun){
					max_amigos_comun=amigos_comun;
					pos_amigo_potencial=u;
				}
			}
		}
		
		string amigo_potencial=usuarios[pos_amigo_potencial];
		
		return amigo_potencial;
	}
	
	//----------------------------------------------
	//	Indica si son amigos pero no tienen amigos en común.
	//	PRE: usr1, usr2 existen
	
	bool AmigosCircunstanciales(string usr1, string usr2){
		bool son_amigos_circunstanciales=true;
		
		int pos_usr1=PosicionUsuarioBuscado(usr1);
		int pos_usr2=PosicionUsuarioBuscado(usr2);
		
		if(SonAmigos(usr1, usr2)){
			int i=0;
			
			while(i<usuarios_utiles && son_amigos_circunstanciales){
				if(relaciones_amistad[pos_usr1][i] && 
					relaciones_amistad[pos_usr2][i]){
					son_amigos_circunstanciales=false;	
				}
				i++;
			}
		}else{
			son_amigos_circunstanciales=false;
		}
		
		return son_amigos_circunstanciales;
	}
	
	//----------------------------------------------
	//	Metodo Get para conseguir el nombre de un usuario en la posicion
	//	n
	string GetUsuario (int posicion){
		return usuarios[posicion];
	}

private:
	//----------------------------------------------
	//	Indica la posicion del usuario buscado dentro del vector
	//	PRE: usr existe
	
	int PosicionUsuarioBuscado(string usr){
		int i = 0;
		int pos_encontrado = -1;
		bool encontrado=false;
		
		while (i < usuarios_utiles && !encontrado){
			if (usuarios[i] == usr){
				encontrado = true;
				pos_encontrado = i;
			}
			else i++;
		}
		
		return pos_encontrado;
	}
	
};

/*****************************************************************************
//	PintaMenu
	
	Pinta el menu en la consola
*****************************************************************************/
void PintaMenu(){
	cout << "=================================================" << endl;
	cout << "|" << "\t\t" << "MENÚ" << "\t\t\t\t" << "|" << endl;
	cout << "=================================================" << endl;
	cout << "|" << "\t" << "1. Añadir usuario" << "\t\t\t" << "|" << endl;
	cout << "|" << "\t" << "2. Eliminar usuario" << "\t\t\t" << "|" << endl;
	cout << "|" << "\t" << "3. Añadir amistad" << "\t\t\t" << "|" << endl;
	cout << "|" << "\t" << "4. Eliminar amistad" << "\t\t\t" << "|" << endl;
	cout << "|" << "\t" << "5. Búsqueda de usuario" << "\t\t\t" << "|" << endl;
	cout << "|" << "\t" << "6. Sugerencia de amistad" << "\t\t" << "|" 
		 << endl;
	cout << "|" << "\t" << "7. Comprobación amistad" << "\t\t\t" << "|" 
		 << endl;
	cout << "|" << "\t" << "8. Mostrar Amistades Circunstanciales" 
		 << "\t" << "|" << endl;
	cout << "|" << "\t" << "9. SALIR" << "\t\t\t\t" << "|" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << endl;
	
}

/*****************************************************************************
//	LeeOpcion
	
	Lee una opcion dentro del rango de opciones del menu
*****************************************************************************/
int LeeOpcion(){
	const int MIN_OPCION = 1;
	const int MAX_OPCION = 9;
	
	int opcion;
	do{
		cout << "Opción: ";
		cin >> opcion;
		cin.ignore(100, '\n');
	}while(opcion < MIN_OPCION || opcion > MAX_OPCION);
		
	return opcion;
}

/****************************************************************************/
/****************************************************************************/
int main(){
	bool seguir=true;
	
	RedSocial red;
	while(seguir){
		
		//Salida del menú
		PintaMenu();
		int opcion = LeeOpcion();
	
		string usr1;
		string usr2;
		
		//Funcionamiento del menú
		switch (opcion){
			case 1:{ //Añadir usr
				bool continuo = true;
				while (continuo){
					cout << endl;
					cout << "Introduzca un usuario:";
					cin >> usr1;
					cin.ignore(100, '\n');
					
					//Añado al usuario
					if(red.Existe(usr1))
						cout << "Ya existe el usuario " << usr1 << endl;
					else{
						red.AniadeUsuario(usr1);
						cout << "Usuario " << usr1 << " añadido"<< endl 
							 << endl;
					}
					
					//Opcion de seguir añadiendo
					char salir;
					do{
						cout << endl;
						cout << "¿Desea añadir otro usuario? (S/N): ";
						cin >> salir;
						cin.ignore(100, '\n');
						
						salir=toupper(salir);
					} while(salir != 'S' && salir != 'N');
					
					//Pide otro usuario o sale
					continuo = salir != 'N';
					
				}
					
				break;
			}
			case 2: { //Eliminar usr
				bool continuo = true;
				while(continuo){
					cout << endl;
					cout << "Introduzca un usuario:";
					cin >> usr1;
					cin.ignore(100, '\n');
					
					//Elimina
					if (red.Existe(usr1)){
						red.EliminaUsuario(usr1);
						cout << "Se ha eliminado el usuario " << usr1 << endl;
					} else {
						cout << "No existe el usuario " << usr1 << endl;
					}
					
					//Opcion de seguir eliminando
					char seguir;
					do{
						cout << endl;
						cout << "¿Desea eliminar otro usuario? (S/N): ";
						cin >> seguir;
						cin.ignore(100, '\n');
						seguir=toupper(seguir);
					} while(seguir!='S' && seguir!='N');
					
					//Pide otro usuario o sale
					continuo = seguir != 'N';
					
				}
				
				break;
			}
			case 3:{ //Añadir amistad
				bool continuo=true;
				while(continuo){
					cout << endl;
					cout << "Introduzca un usuario:";
					cin >> usr1;
					cin.ignore(100, '\n');
					
					do{
						cout << "Introduzca otro usuario:";
						cin >> usr2;
						cin.ignore(100, '\n');
					} while(usr1 == usr2);
					
					//Añado la amistad
					cout << endl;
					if(red.Existe(usr1) && red.Existe(usr2)){
						red.HacerAmigos(usr1, usr2);
						
						cout << "Ahora " << usr1 << " y " << usr2 
							 << " son amigos"
							 << endl;
							 
					} else if(!red.Existe(usr1) && red.Existe(usr2)){
						cout << "Lo siento, " << usr1 << " no existe" << endl;
						
					} else if(red.Existe(usr1) && !red.Existe(usr2)){
						cout << "Lo siento, " << usr2 << " no existe" << endl;
						
					} else {
						cout << "Lo siento, " << usr1 << " y " << usr2 
							 << " no existen" << endl;
							 
					}
					
					//Opcion de seguir añadiendo
					char seguir;
					
					do{
						cout << endl;
						cout << "¿Desea añadir otra amistad? (S/N): ";
						cin >> seguir;
						cin.ignore(100, '\n');
						seguir=toupper(seguir);
					} while(seguir != 'S' && seguir != 'N');
					
					//Compruebo si seguir añadiendo amistades
					continuo = seguir != 'N';
					
				}
				break;
			}
			case 4:{ //Eliminar amistad
				bool continuo=true;
				while(continuo){
					cout << endl;
					cout << "Introduzca un usuario:";
					cin >> usr1;
					cin.ignore(100, '\n');
					
					do{
						cout << "Introduzca otro usuario:";
						cin >> usr2;
						cin.ignore(100, '\n');
					}while(usr1 == usr2);
					
					cout << endl;
					if(red.Existe(usr1) && red.Existe(usr2)){
						red.DeshacerAmigos(usr1, usr2);
						
						cout << "Ahora " << usr1 << " y " << usr2 
							 << " no son amigos" << endl;
							 
					}else if(!red.Existe(usr1) && red.Existe(usr2)){
						cout << "Lo siento, " << usr1 << " no existe" << endl;
						
					}else if(red.Existe(usr1) && !red.Existe(usr2)){
						cout << "Lo siento, " << usr2 << " no existe" << endl;
						
					} else {
						cout << "Lo siento, " << usr1 << " y " << usr2 
							 << " no existen" << endl;
							 
					}
					
					//Opcion de seguir eliminando
					char seguir;
						
					do{
						cout << endl;
						cout << "¿Desea eliminar otra amistad? (S/N): ";
						cin >> seguir;
						cin.ignore(100, '\n');
						seguir = toupper(seguir);
					}while(seguir != 'S' && seguir != 'N');
					
					//Compruebo si continuar eliminando
					continuo = seguir != 'N';

				}
				break;
			}
			case 5:{ //Ver si existe
				bool continuo=true;
				while(continuo){
					cout << endl;
					cout << "Introduzca un usuario:";
					cin >> usr1;
					cin.ignore(100, '\n');
					
					if(red.Existe(usr1)){
						cout << endl;
						cout << usr1 << " existe" << endl;
					}else{
						cout << endl;
						cout << usr1 << " no existe" << endl;
					}
					
					//Opcion de seguir comprobando la existencia de un usuario
					char seguir;
						
					do{
						cout << endl;
						cout << "¿Desea comprobar otro usuario? (S/N): ";
						cin >> seguir;
						cin.ignore(100, '\n');
						seguir=toupper(seguir);
					}while(seguir!='S' && seguir!='N');
						
					if(seguir=='N') continuo=false;
				}
				break;
			}
			case 6:{ //Sugerencia amigo potencial
				cout << endl;
				do{	
					cout << "Introduzca un usuario existente:";
					cin >> usr1;
					cin.ignore(100, '\n');
				}while(!red.Existe(usr1));
				
				string amigo_potencial=red.SugerenciaAmigoPotencialDe(usr1);
				
				if(red.Existe(usr1)){
					cout << endl;
					cout << "Un amigo potencial de " << usr1
						 << " es el usuario " << amigo_potencial 
						 << endl;
				}else{
					cout << endl;
					cout << usr1 << " no existe. No puedo ayudarle" << endl;
				}
				
				break;
			}
			case 7: //Comprobar amistad
				cout << endl;
				do{	
					cout << "Introduzca un usuario existente: ";
					cin >> usr1;
					cin.ignore(100, '\n');
				}while(!red.Existe(usr1));
				
				do{	
					cout << "Introduzca otro usuario existente: ";
					cin >> usr2;
					cin.ignore(100, '\n');
				}while(!red.Existe(usr2));
				
				if(red.AmigosCircunstanciales(usr1, usr2)){
					cout << endl;
					cout << usr1 << " y " << usr2 
						 << " son amigos pero no tienen" 
						 << " amigos en común" << endl;
				} else if (red.SonAmigos(usr1, usr2) && 
						 !red.AmigosCircunstanciales(usr1, usr2)){
					cout << endl;
					cout << usr1 << " y " << usr2 
						 << " son amigos y tienen amigos en común"
						 << endl;
					
				} else {
					cout << endl;
					cout << usr1 << " y " << usr2 << " no son amigos" << endl;
				}
				
				break;
			
			case 8:	//Mostrar todas las amistades circunstanciales
				cout << endl;
				for (int pos_usr1 = 0; pos_usr1 < red.NumUsuarios(); 
					 pos_usr1++){
					usr1 = red.GetUsuario(pos_usr1);
					
					for (int pos_usr2 = pos_usr1+1; 
						 pos_usr2 < red.NumUsuarios(); pos_usr2++){
						usr2 = red.GetUsuario(pos_usr2);
						
						if (red.AmigosCircunstanciales(usr1, usr2)){
							cout << usr1 << " y " << usr2 
								 << " son amigos circunstanciales" << endl;
						}
					}
				}
				
				break;
			
			case 9: //Salir
				seguir = false;
				break;
		}
	}
	
	return 0;
}
