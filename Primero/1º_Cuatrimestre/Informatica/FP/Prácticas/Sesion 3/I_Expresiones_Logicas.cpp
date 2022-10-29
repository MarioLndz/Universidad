/*****************************************************************************
	Mario Líndez Martínez
	Grupo: A2

	Ejercicio 36: Suponga un caso de elección en el que se decide entre tres 
	opciones: A, B y C:
	-	El número de votantes totales (censo) está registrado en la constante 
		VOTANTES.
	-	El número total de de votos registrados es votos_emitidos, donde el 
		número total de de votos presenciales es votos_presenciales y el número 
		total de de votos por correo es votos_correo.
	-	Los votos registrados se dividen en válidos (votos_validos) y nulos
		(votos_nulos).
	-	Entre los votos válidos se distinguen entre los recibidos por correo 
		(votos_validos_correo) y presencialmente (votos_validos_presenciales).
	-	Cada opción recibe un número de votos válidos que se registra en las 
		variables votos_A, votos_B y votos_C, respectivamente.	
	Escriba expresiones lógicas para reflejar las situaciones que se describen 
	a continuación.

	Para cada caso, el resultado debe guardarse en una variable lógica (escoja 
	un nombre adecuado).
	a) 	El número de votos emitidos totales es mayor que el número de votantes.
	
	b) 	El número de votos válidos no es igual a la suma de los votos recibidos 
		por las tres opciones.
		
	c) 	El número de votos registrados es igual a la suma de los votos válidos 
		y nulos.
		
	d) 	Gana la opción A.
	
	e) 	Gana la opción B.
	
	f) 	Gana la opción C.
	
	g)	Empatan dos opciones.
	
	h) 	Hay un empate técnico entre las opciones A y B. Definimos que ocurre un 
		empate técnico cuando la diferencia entre los dos valores es menor que 
		el 5% de su suma.
		
	i) 	La opción A obtiene mayoría absoluta.
	
	j) 	Hay una coalición de dos opciones que obtiene mayoría absoluta.
	
	k) 	La coalición A-C obtiene mayoría absoluta.
	
	l) 	La opción B obtiene menos de 3% de los votos válidos registrados.
	
	m) 	La participación es mayor que el 75% del censo de votantes.
	
	n) 	Queremos saber si la opción A puede gobernar "sólo o en compañía de 
		otros".
		
	ñ) 	El número de votos nulos ó el número de abstenciones es mayor que el 
		número de votos válidos.
		
	o) 	El número de votos nulos y el número de abstenciones es mayor que el 
		número de votos válidos, pero las abstenciones no son mayores que los 
		votos nulos.
		
	p) 	El número de votos por correo es mayor que el 20% de los votos 
		presenciales o el número de abstenciones.
		
	q) 	El número de votos nulos por correo es mayor que el número de votos 
		nulos presenciales.
		
	r) 	El número de votos nulos por correo es mayor que el número de votos 
		válidos por correo.

*****************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;

int main () {
	//Variables 
		const int VOTANTES = 10000; 
		
		int votos_emitidos = 9500; 
		int votos_presenciales = 6000;
		int votos_correo = 3500;
		
		int votos_nulos = 1500;
		int votos_validos = 8000; 
		int votos_validos_correo = 2500; 
		int votos_validos_presenciales = 5500;
		
		int votos_A = 3000; 
		int votos_B = 1500;
		int votos_C = 3500;
		
	//Muestra de los datos
		cout << "Número de votantes: " << VOTANTES << endl << endl;
		
		
		cout << "Número de votos emitidos: " << votos_emitidos << endl;
		cout << "Número de votos presenciales: " << votos_presenciales << endl;
		cout << "Número de votos por correo: " << votos_correo << endl << endl;
		
		cout << "Número de votos nulos: " << votos_nulos << endl;
		cout << "Número de votos válidos: " << votos_validos << endl;
		cout << "Número de votos válidos por correo: " 
		  	 << votos_validos_correo << endl;
		cout << "Número de votos válidos presenciales: "
			 << votos_validos_presenciales << endl << endl;
			 
		cout << "Número de votos para A: " << votos_A << endl;
		cout << "Número de votos para B: " << votos_B << endl;
		cout << "Número de votos para C: " << votos_C << endl;
		
		cout << "_____________________________________________________________" 
			 << endl;
		cout << endl << "ACLARACIÓN: Si la condición es falsa se mostrará "
			 << "un 0, si es cierta, un 1" << endl << endl;
			 
	//A
		bool voto_doble = (VOTANTES < votos_emitidos);
		
		cout << "\t- El número de votos emitidos totales es mayor que el "
			 << "número de votantes: " << voto_doble << endl; 
		
	//B
		bool validos_igual_suma_A_B_C = 
			 (votos_A + votos_B + votos_C) != votos_validos;
		
		cout << "\t- El número de votos válidos no es igual a la suma de los "
			 << "votos recibidos por las tres opciones: "
			 << validos_igual_suma_A_B_C << endl;
	
	//C
		bool emitidos_igual_nulos_y_validos =
			 votos_emitidos == (votos_nulos + votos_validos);
			 
		cout << "\t- El número de votos registrados es igual a la suma de los "
			 << "votos válidos y nulos: " << emitidos_igual_nulos_y_validos
			 << endl;
			 
	//D
		bool gana_A = (votos_A > votos_B) && (votos_A > votos_C);
		
		cout << "\t- Gana la opción A: " << gana_A << endl;
		
	//E
		bool gana_B = (votos_B > votos_A) && (votos_B > votos_C);
		
		cout << "\t- Gana la opción B: " << gana_B << endl;
		
	//F
		bool gana_C = (votos_C > votos_A) && (votos_C > votos_B);
		
		cout << "\t- Gana la opción C: " << gana_C << endl;
		
	//G
		bool empate = 
		(votos_A == votos_B) || (votos_A == votos_C) || (votos_B == votos_C);
		
		cout << "\t- Empatan dos opciones: " << empate << endl;
		
	//H
		bool empate_tecnico = (votos_A - votos_B) < 0.05 * (votos_A + votos_B);
		
		cout << "\t- Se produce un empate técnico entre A y B: " 
			 << empate_tecnico << endl;
			 
	//I
		bool mayoria_A = votos_A > (votos_validos * 0.5);
		
		cout << "\t- La opción A obtiene mayoría absoluta: " << mayoria_A
			 << endl;
	
	//J
		bool mayoria_absoluta = ((votos_A + votos_B) > (votos_validos * 0.5))
			 || ((votos_A + votos_C) > (votos_validos * 0.5))
			 || ((votos_B + votos_C) > (votos_validos * 0.5));
			 
		cout << "\t- Hay una coalición de dos opciones que obtiene mayoría "
			 << "absoluta: " << mayoria_absoluta << endl;
	
	//K
		bool coalicion_A_C_mayoria = 
			 (votos_A + votos_C) > (votos_validos * 0.5);
			 
		cout << "\t- La coalición A-C obtiene mayoría absoluta: "
			 << coalicion_A_C_mayoria << endl;
			 
	//L
		bool votosB_menos_3porciento = votos_B < (votos_emitidos * 0.03);
		
		cout << "\t- La opción B obtiene menos de 3% de los votos válidos "
			 << "registrados: " << votosB_menos_3porciento << endl; 
	
	//M
		bool participacion_mayor_75porciento = 
			 votos_emitidos > (VOTANTES * 0.75);
			 
		cout << "\t- La participación es mayor que el 75% del censo de "
			 << "votantes: " << participacion_mayor_75porciento << endl;
		
	//N
		bool A_gobierna_solo = mayoria_A == 1;
		bool A_gobierna_coalicion = 
			 ((votos_A + votos_B) > (votos_validos * 0.5)) ||
			 ((votos_A + votos_C) > (votos_validos * 0.5));
			 
		cout << "\t- A puede gobernar solo: " << A_gobierna_solo << endl;
		cout << "\t- A puede gobernar en compañía: " << A_gobierna_coalicion 
			 << endl;
		
	//Ñ
		int abstencion = VOTANTES - votos_emitidos;
		
		bool votos_no_utiles_mayor_votos_validos = 
			 votos_nulos > votos_validos || 
			 (abstencion) > votos_validos;
			 
		cout << "\t- El número de votos nulos ó el número de abstenciones "
			 << "es mayor que el número de votos válidos: "
			 << votos_no_utiles_mayor_votos_validos << endl;
			 
	//O
		bool nulos_y_abstencion_mayor_validos =
			 ((votos_nulos + abstencion) > votos_validos) && 
			 (abstencion < votos_nulos);
			 
		cout << "\t- El número de votos nulos y el número de abstenciones es "
			 << "mayor que el número de votos válidos, pero las abstenciones "
			 << "no son mayores que los votos nulos: "
			 << nulos_y_abstencion_mayor_validos << endl;
			 
	//P
		bool votos_correo_mayor_20xciento_presen_abstenc =
			 (votos_correo > 0.2 * votos_presenciales) ||
			 (votos_correo > 0.2 * abstencion);
			 
		cout << "\t- El número de votos por correo es mayor que el 20% de "
			 << "los votos presenciales o el número de abstenciones: "
			 << votos_correo_mayor_20xciento_presen_abstenc << endl;
		
	//Q
		int votos_nulos_correo = votos_correo - votos_validos_correo;
		int votos_nulos_presenciales = 
			votos_presenciales - votos_validos_presenciales;
		
		bool nulos_correo_mayor_nulos_presenciales =
			 (votos_nulos_correo > votos_nulos_presenciales);
			 
		cout << "\t- El número de votos nulos por correo es mayor que el "
			 << "número de votos nulos presenciales: " 
			 << nulos_correo_mayor_nulos_presenciales << endl; 
		
	//R
		bool nulos_correo_mayor_validos_correo = 
			 votos_nulos_correo > votos_validos_correo;
			 
		cout << "\t- El número de votos nulos por correo es mayor que el "
			 << "número de votos válidos por correo: " 
			 << nulos_correo_mayor_validos_correo << endl;
		
	return 0;
}
