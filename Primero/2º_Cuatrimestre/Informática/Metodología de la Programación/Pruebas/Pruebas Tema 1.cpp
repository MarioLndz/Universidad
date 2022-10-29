#include <iostream>	// Inclusión de los recursos de E/S

using namespace std;

/**************************************************************/
// Calcula el mayor elemento de un vector dada una dirección de
// memoria y el número de casillas a explorar a partir de ella.
//
// Recibe: pv, Dirección del primer elemento del vector.
// num_datos, número de casillas para la búasqueda.
// Devuelve: el valor del mayor número entero, desde la
// dirección de memoria pv.
// PRE: "pv" referencia a una zona de memoria reservada
// PRE: num_datos > 0
int & ValorMayor (int *pv, int num_datos)
{
	int *fin; // Marca el final de la zona de búsqueda
	int *pos_mayor; // Posicion (de memoria) del mayor valor
	fin = pv+num_datos; // Última casilla de interés
	pos_mayor = pv; // El primer elemento será el primer mayor
	int *p = pv+1; // Primera casilla de la búsqueda
	while (p < fin) {
		if (*p > *pos_mayor) pos_mayor = p;
		p++;
	}
	return (*pos_mayor);
}

int main (){
	// Vector de datos
	const int CAPACIDAD = 20; // Capacidad del array
	int vector[CAPACIDAD] = {10, 2, 33, 4, 66, 45, 33, 23, 55, 66,
	3, 0, 12, 0, 5, 44, 89, 88, 8, 22};
	
	int num_datos = CAPACIDAD;
	int v_mayor = ValorMayor(vector, num_datos);
	
	const int MAXIMO = 99;
	ValorMayor(vector, num_datos) = MAXIMO;
	
	cout << "Mayor = " << v_mayor << endl;
	cout << "Mayor = " << ValorMayor(vector, num_datos) << endl;
	cout << vector[16] << endl;
}
