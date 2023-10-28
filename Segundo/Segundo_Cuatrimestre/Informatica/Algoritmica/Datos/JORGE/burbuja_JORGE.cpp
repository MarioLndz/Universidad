/**
   @file burbuja.cpp
   @brief Ordenación por burbuja
   @date 2023-3-6
*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <random>
#include <chrono>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;


/* ************************************************************ */ 
/*  Método de ordenación por burbuja  */

/**
   @brief Ordena un vector por el método de la burbuja.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de la burbuja.
*/
inline static
void burbuja(float T[], int num_elem);



/**
   @brief Ordena parte de un vector por el mÃ©todo de la burbuja.

   @param T: vector de elementos. Tiene un número de elementos 
                   mayor o igual a final.Es MODIFICADO.

   @param inicial: Posición que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posición detrás de la última de la parte del
                   vector a ordenar. 
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de la burbuja.
*/
static
void burbuja_lims(float T[], int inicial, int final);



/**
   Implementación de las funciones
**/

inline
void burbuja(float T[], int num_elem)
{
  burbuja_lims(T, 0, num_elem);
};


void burbuja_lims(float T[], int inicial, int final)
{
  int i, j;
  float aux;
  for (i = inicial; i < final - 1; i++)
    for (j = final - 1; j > i; j--)
      if (T[j] < T[j-1])
	{
	  aux = T[j];
	  T[j] = T[j-1];
	  T[j-1] = aux;
	}
}


int main(int argc, char * argv[])
{
	 if (argc != 2)
	    {
	      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
	      return -1;
	    }

	  int n = atoi(argv[1]);

	  if (n <= 0)
	    {
	      cerr << "El tamaño del vector debe ser positivo" << endl;
	      return -1;
	    }

	  float * T = new float[n];
	  assert(T);
	  
	  
	const int MIN=0, MAX=5000;

	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<float> distr(MIN,MAX);

	for (int i=0; i<n; i++){
		T[i] = distr(eng);
		// cout << T[i] << endl;
	};

	  for (int i = 0; i < n; i++)
	    {
	      T[i] = random();
	    };
	
	
	clock_t t_antes, t_despues;
	
	//Captura el valor del reloj antes de la llamada a burbuja
	t_antes = clock();
	
	// Llamamos a la función burbuja
	burbuja(T, n);

	//Captura el valor del reloj después de la ejecución de burbuja
	t_despues = clock();
	
	cout << n << "	";
	// Obtenemos el tiempo en segundos
	cout << (double)(t_despues - t_antes) / CLOCKS_PER_SEC << endl;
	
	
	delete [] T;

	return 0;
};