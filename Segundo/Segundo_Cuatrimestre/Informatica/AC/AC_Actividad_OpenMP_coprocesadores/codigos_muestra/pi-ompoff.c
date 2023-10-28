/**
 * 
PI secuencial con integración numérica. 
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <math.h>
/**
 * @file  pi.c 
 * @brief PI secuencial con integración numérica, área de rectángulos
 * @author Mancia Anguita
 *  
 * **Compilación**
 * @code
 *  gcc -O2 pi.c -o pi
 * @endcode
 * 
 *  **Ejecución**
 * ~~~~~~~~~~~~~~~~~~~~~
 * ./pi   1000000    (1000000 intervalos de integración)
 * ~~~~~~~~~~~~~~~~~~~~~
 * 
*/
int main(int argc, char **argv)
{  
  register double width;
  double sum;
  register int intervals, i; 
    
  //Los procesos calculan PI en paralelo
  if (argc<2) {printf("Falta número de intevalos");exit(-1);}
  intervals=atoi(argv[1]);  
  if (intervals<1) {intervals=1E6; printf("Intervalos=%d",intervals);}
  width = 1.0 / intervals;
  sum = 0;
  
  double t1 = omp_get_wtime();
  
  #pragma omp target enter data map(to: width, intervals, sum)
  
  double t2 = omp_get_wtime();
  
  #pragma omp target teams distribute parallel for reduction (+:sum)
	  for (i = 0; i < intervals; ++i) {
		  register double x = (i + 0.5) * width;
		  sum += 4.0 / (1.0 + x * x);
	  }
	  
  double t3 = omp_get_wtime();
  
  #pragma omp target exit data map(delete: intervals, width) map (from: sum)
  sum *= width;
  
  double t4 = omp_get_wtime();
  
  printf ("Iteraciones:\t%d\t\\ PI:\t%26.24f\t\\ Tiempo:\t%8.6f\n", intervals, sum, t4-t2);
  printf ("Error:\t%8.6f\n", fabs(M_PI-sum));
  
  printf (" *\t(Target enter data): %11.9f\n", t2-t1);
  printf (" *\t(Target teams distribute parallel for): %11.9f\n", t3-t2);
  printf (" *\t(Target exit data): %11.9f\n", t4-t3);
  printf (" *\t(TOTAL): %11.9f\n", t4-t1);

  return(0);
}
