/***************************************************************************/
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// CURSO 2021-2022
//
// FUNDAMENTOS DE PROGRAMACIÓN
// DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS
//
// EXAMEN PRÁCTICO 1 - NOVIEMBRE 2021
// 
// ¡RELLENAD LOS SIGUIENTES DATOS!
//
// Apellidos: Líndez Martínez 
// Nombre:  Mario
//
// GRUPO DE PRÁCTICAS: 2
//
// Fecha: 10 - Noviembre
// Aula: 2.2
// Ordenador (ver etiqueta): ei142077
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/***************************************************************************/
/***************************************************************************/
struct Narcisista{
   int num_narcisistas;
   string narcisistas; 
};
/***************************************************************************
// EsEntero

   Comprueba que en una cadena se tiene un número entero
   
   RECIBE: string
   DEVUELVE: True ó False
****************************************************************************/
bool EsEntero (string cadena){
   int longitud = cadena.length();
   bool es_entero = true;
   
   int n = 0;
   if (cadena.at(0) == '+' || cadena.at(0) == '-'){
        n++;
   }
   
   if (cadena == "+" || cadena == "-"){
      es_entero = false;
       
   } else {
      while (n < longitud && es_entero){
         if (cadena.at(n) < '0' || cadena.at(n) > '9'){
            es_entero = false;
         }
         
         n++;
      }
   }
   
   return es_entero;
}

/***************************************************************************
// LeeEntero

   Esta función leerá y filtrará un número entero. Si lo introducido
   no es un número entero, se volverá a pedir
   
   RECIBE: título a mostrar cada vez que se pida un número
   DEVUELVE: Número entero leido
****************************************************************************/
int LeeEntero (string titulo){
   string cadena;
   
   do {
      cout << titulo;
      cin >> cadena;
   } while (!EsEntero(cadena));
   
   int numero = stoi(cadena);
   
   return numero;
}

/***************************************************************************
// EsNarcisista

   Esta función comprobará si un número es narcisista
   
   RECIBE: Número a comprobar
   DEVUELVE: True ó False
****************************************************************************/
bool EsNarcisista (int numero){
   string numero_cad = to_string(numero);
   int num_digitos = numero_cad.length();
   
   int suma = 0;
   
   for (int n = 0; n < num_digitos && suma < numero; n++){
      string digito;
      digito += numero_cad.at(n);      
      
      suma += pow (stoi(digito), num_digitos);
   }
   bool es_narcisista = (suma == numero);  
   
   return es_narcisista;
}

Narcisista CalculaNarcisista (int lim_inferior, int lim_superior){
   Narcisista candidatos;
   candidatos.num_narcisistas = 0;
   
   string narcisistas;
   const string SEPARADOR = " ";
   
   for (int candidato = lim_inferior; candidato <= lim_superior; candidato++){
      if (EsNarcisista(candidato)){
         candidatos.narcisistas += to_string(candidato) + SEPARADOR ;
         candidatos.num_narcisistas++; 
      }
   }
   
   return candidatos;  
}


/***************************************************************************
// PintaSección

   Esta función pintará la sección del programa en la que nos encontremos en 
   la consola
   
   RECIBE: Número de la sección
****************************************************************************/
void PintaSeccion (int seccion){
   cout << "----------------------------------------------------------" 
        << endl;
   cout << "Apartado " << seccion << endl;
   cout << "----------------------------------------------------------" 
        << endl;
   cout << endl;
   
}

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
   
   PintaSeccion(1);
   
   int num1;
   int num2;
   
   do {
      num1 = LeeEntero("Un extremo (>0): ");
   } while (num1 <= 0);
   
   do {
      num2 = LeeEntero("Otro extremo (>0): ");
   } while (num2 <= 0);
   
   //CÁLDULOS
   
   //Ordenamos los numeros introducidos
   int lim_inferior, lim_superior;
   
   if (num1 < num2){
      lim_inferior = num1;
      lim_superior = num2;
   } else {
      lim_inferior = num2;
      lim_superior = num1;
   }
   
   //Apartado 1
   Narcisista candidatos1 = CalculaNarcisista(lim_inferior, lim_superior);
     
     
   //SALIDA
   cout << endl;
   cout << "Hay " << setw(3) << candidatos1.num_narcisistas 
        << " narcisistas entre " << setw(3) << lim_inferior << " y " 
        << setw(3) << lim_superior << endl;
   
   cout << candidatos1.narcisistas << endl;
   
   //Apartado 2
   PintaSeccion(2);
   
   int num_cifras;
   
   do{
      num_cifras = LeeEntero("Número de cifras (>0): ");
   } while (num_cifras <= 0);
   
   string num_inicial = to_string(1);
   string num_final = to_string(9);
   
   for (int n = 1; n < num_cifras; n++){
      num_inicial += '0';
      num_final += '9';
   }
   
   lim_inferior = stoi(num_inicial);
   lim_superior = stoi(num_final);
   
   
   //Cálculos
   
   Narcisista candidatos2 = CalculaNarcisista(lim_inferior, lim_superior);
   
   //SALIDA
   cout << endl;
   cout << "Hay " << setw(3) << candidatos2.num_narcisistas 
        << " narcisistas de " << setw(3) << candidatos2.num_narcisistas 
        << endl;
   
   cout << candidatos2.narcisistas << endl;
   
	return 0;
	
}

/***************************************************************************/
/***************************************************************************/
