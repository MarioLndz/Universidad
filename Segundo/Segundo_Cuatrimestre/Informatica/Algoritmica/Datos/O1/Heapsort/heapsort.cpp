/**
   @file heapsort.cpp
   @brief Ordenación por montones
   @date 2023-3-6
*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using std::cerr;
using std::endl;
using std::cout;





/* ************************************************************ */
/*  Método de ordenación por montones  */

/**
   @brief Ordena un vector por el método de montones.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de ordenación por montones.
*/
inline static
void heapsort(float T[], int num_elem);



/**
   @brief Reajusta parte de un vector para que sea un montón.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.
   @param k: índice del elemento que se toma com raíz

   Reajusta los elementos entre las posiciones k y num_elem - 1
   de T para que cumpla la propiedad de un montón (APO),
   considerando al elemento en la posición k como la raíz.
*/
static void reajustar(float T[], int num_elem, int k);




/**
   Implementación de las funciones
**/


static void heapsort(float T[], int num_elem)
{
  int i;
  for (i = num_elem/2; i >= 0; i--)
    reajustar(T, num_elem, i);
  for (i = num_elem - 1; i >= 1; i--)
    {
      float aux = T[0];
      T[0] = T[i];
      T[i] = aux;
      reajustar(T, i, 0);
    }
}


static void reajustar(float T[], int num_elem, int k)
{
  int j;
  float v;
  v = T[k];
  bool esAPO = false;
  while ((k < num_elem/2) && !esAPO)
    {
      j = k + k + 1;
      if ((j < (num_elem - 1)) && (T[j] < T[j+1]))
	j++;
      if (v >= T[j]){
	esAPO = true;
      }else{
      T[k] = T[j];
      k = j;
      }
    }
  T[k] = v;
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

  srandom(time(0));

  for (int i = 0; i < n; i++)
    {
      float r = (random() * 5000) / static_cast<float>(RAND_MAX);
      T[i] = r;
      //cout << T[i] << endl;
    };

  // Variables que capturaran el tiempo
  clock_t t_antes;
  clock_t t_despues;

  //Captura el valor del reloj antes de la llamada a burbuja
  t_antes = clock();

  // Llama al algoritmo de ordenación heapsort
  heapsort(T, n);

  //Captura el valor del reloj después de la ejecución de burbuja
  t_despues = clock();

  cout << n << "\t";
  cout << (double)(t_despues - t_antes) / CLOCKS_PER_SEC << endl;

  delete [] T;

  return 0;
};
