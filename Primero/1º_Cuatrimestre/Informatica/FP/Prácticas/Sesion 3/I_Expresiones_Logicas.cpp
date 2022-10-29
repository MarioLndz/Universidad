/*****************************************************************************
	Mario L�ndez Mart�nez
	Grupo: A2

	Ejercicio 36: Suponga un caso de elecci�n en el que se decide entre tres 
	opciones: A, B y C:
	-	El n�mero de votantes totales (censo) est� registrado en la constante 
		VOTANTES.
	-	El n�mero total de de votos registrados es votos_emitidos, donde el 
		n�mero total de de votos presenciales es votos_presenciales y el n�mero 
		total de de votos por correo es votos_correo.
	-	Los votos registrados se dividen en v�lidos (votos_validos) y nulos
		(votos_nulos).
	-	Entre los votos v�lidos se distinguen entre los recibidos por correo 
		(votos_validos_correo) y presencialmente (votos_validos_presenciales).
	-	Cada opci�n recibe un n�mero de votos v�lidos que se registra en las 
		variables votos_A, votos_B y votos_C, respectivamente.	
	Escriba expresiones l�gicas para reflejar las situaciones que se describen 
	a continuaci�n.

	Para cada caso, el resultado debe guardarse en una variable l�gica (escoja 
	un nombre adecuado).
	a) 	El n�mero de votos emitidos totales es mayor que el n�mero de votantes.
	
	b) 	El n�mero de votos v�lidos no es igual a la suma de los votos recibidos 
		por las tres opciones.
		
	c) 	El n�mero de votos registrados es igual a la suma de los votos v�lidos 
		y nulos.
		
	d) 	Gana la opci�n A.
	
	e) 	Gana la opci�n B.
	
	f) 	Gana la opci�n C.
	
	g)	Empatan dos opciones.
	
	h) 	Hay un empate t�cnico entre las opciones A y B. Definimos que ocurre un 
		empate t�cnico cuando la diferencia entre los dos valores es menor que 
		el 5% de su suma.
		
	i) 	La opci�n A obtiene mayor�a absoluta.
	
	j) 	Hay una coalici�n de dos opciones que obtiene mayor�a absoluta.
	
	k) 	La coalici�n A-C obtiene mayor�a absoluta.
	
	l) 	La opci�n B obtiene menos de 3% de los votos v�lidos registrados.
	
	m) 	La participaci�n es mayor que el 75% del censo de votantes.
	
	n) 	Queremos saber si la opci�n A puede gobernar "s�lo o en compa��a de 
		otros".
		
	�) 	El n�mero de votos nulos � el n�mero de abstenciones es mayor que el 
		n�mero de votos v�lidos.
		
	o) 	El n�mero de votos nulos y el n�mero de abstenciones es mayor que el 
		n�mero de votos v�lidos, pero las abstenciones no son mayores que los 
		votos nulos.
		
	p) 	El n�mero de votos por correo es mayor que el 20% de los votos 
		presenciales o el n�mero de abstenciones.
		
	q) 	El n�mero de votos nulos por correo es mayor que el n�mero de votos 
		nulos presenciales.
		
	r) 	El n�mero de votos nulos por correo es mayor que el n�mero de votos 
		v�lidos por correo.

*****************************************************************************/

#include <iostream>   // Inclusi�n de los recursos de E/S
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
		cout << "N�mero de votantes: " << VOTANTES << endl << endl;
		
		
		cout << "N�mero de votos emitidos: " << votos_emitidos << endl;
		cout << "N�mero de votos presenciales: " << votos_presenciales << endl;
		cout << "N�mero de votos por correo: " << votos_correo << endl << endl;
		
		cout << "N�mero de votos nulos: " << votos_nulos << endl;
		cout << "N�mero de votos v�lidos: " << votos_validos << endl;
		cout << "N�mero de votos v�lidos por correo: " 
		  	 << votos_validos_correo << endl;
		cout << "N�mero de votos v�lidos presenciales: "
			 << votos_validos_presenciales << endl << endl;
			 
		cout << "N�mero de votos para A: " << votos_A << endl;
		cout << "N�mero de votos para B: " << votos_B << endl;
		cout << "N�mero de votos para C: " << votos_C << endl;
		
		cout << "_____________________________________________________________" 
			 << endl;
		cout << endl << "ACLARACI�N: Si la condici�n es falsa se mostrar� "
			 << "un 0, si es cierta, un 1" << endl << endl;
			 
	//A
		bool voto_doble = (VOTANTES < votos_emitidos);
		
		cout << "\t- El n�mero de votos emitidos totales es mayor que el "
			 << "n�mero de votantes: " << voto_doble << endl; 
		
	//B
		bool validos_igual_suma_A_B_C = 
			 (votos_A + votos_B + votos_C) != votos_validos;
		
		cout << "\t- El n�mero de votos v�lidos no es igual a la suma de los "
			 << "votos recibidos por las tres opciones: "
			 << validos_igual_suma_A_B_C << endl;
	
	//C
		bool emitidos_igual_nulos_y_validos =
			 votos_emitidos == (votos_nulos + votos_validos);
			 
		cout << "\t- El n�mero de votos registrados es igual a la suma de los "
			 << "votos v�lidos y nulos: " << emitidos_igual_nulos_y_validos
			 << endl;
			 
	//D
		bool gana_A = (votos_A > votos_B) && (votos_A > votos_C);
		
		cout << "\t- Gana la opci�n A: " << gana_A << endl;
		
	//E
		bool gana_B = (votos_B > votos_A) && (votos_B > votos_C);
		
		cout << "\t- Gana la opci�n B: " << gana_B << endl;
		
	//F
		bool gana_C = (votos_C > votos_A) && (votos_C > votos_B);
		
		cout << "\t- Gana la opci�n C: " << gana_C << endl;
		
	//G
		bool empate = 
		(votos_A == votos_B) || (votos_A == votos_C) || (votos_B == votos_C);
		
		cout << "\t- Empatan dos opciones: " << empate << endl;
		
	//H
		bool empate_tecnico = (votos_A - votos_B) < 0.05 * (votos_A + votos_B);
		
		cout << "\t- Se produce un empate t�cnico entre A y B: " 
			 << empate_tecnico << endl;
			 
	//I
		bool mayoria_A = votos_A > (votos_validos * 0.5);
		
		cout << "\t- La opci�n A obtiene mayor�a absoluta: " << mayoria_A
			 << endl;
	
	//J
		bool mayoria_absoluta = ((votos_A + votos_B) > (votos_validos * 0.5))
			 || ((votos_A + votos_C) > (votos_validos * 0.5))
			 || ((votos_B + votos_C) > (votos_validos * 0.5));
			 
		cout << "\t- Hay una coalici�n de dos opciones que obtiene mayor�a "
			 << "absoluta: " << mayoria_absoluta << endl;
	
	//K
		bool coalicion_A_C_mayoria = 
			 (votos_A + votos_C) > (votos_validos * 0.5);
			 
		cout << "\t- La coalici�n A-C obtiene mayor�a absoluta: "
			 << coalicion_A_C_mayoria << endl;
			 
	//L
		bool votosB_menos_3porciento = votos_B < (votos_emitidos * 0.03);
		
		cout << "\t- La opci�n B obtiene menos de 3% de los votos v�lidos "
			 << "registrados: " << votosB_menos_3porciento << endl; 
	
	//M
		bool participacion_mayor_75porciento = 
			 votos_emitidos > (VOTANTES * 0.75);
			 
		cout << "\t- La participaci�n es mayor que el 75% del censo de "
			 << "votantes: " << participacion_mayor_75porciento << endl;
		
	//N
		bool A_gobierna_solo = mayoria_A == 1;
		bool A_gobierna_coalicion = 
			 ((votos_A + votos_B) > (votos_validos * 0.5)) ||
			 ((votos_A + votos_C) > (votos_validos * 0.5));
			 
		cout << "\t- A puede gobernar solo: " << A_gobierna_solo << endl;
		cout << "\t- A puede gobernar en compa��a: " << A_gobierna_coalicion 
			 << endl;
		
	//�
		int abstencion = VOTANTES - votos_emitidos;
		
		bool votos_no_utiles_mayor_votos_validos = 
			 votos_nulos > votos_validos || 
			 (abstencion) > votos_validos;
			 
		cout << "\t- El n�mero de votos nulos � el n�mero de abstenciones "
			 << "es mayor que el n�mero de votos v�lidos: "
			 << votos_no_utiles_mayor_votos_validos << endl;
			 
	//O
		bool nulos_y_abstencion_mayor_validos =
			 ((votos_nulos + abstencion) > votos_validos) && 
			 (abstencion < votos_nulos);
			 
		cout << "\t- El n�mero de votos nulos y el n�mero de abstenciones es "
			 << "mayor que el n�mero de votos v�lidos, pero las abstenciones "
			 << "no son mayores que los votos nulos: "
			 << nulos_y_abstencion_mayor_validos << endl;
			 
	//P
		bool votos_correo_mayor_20xciento_presen_abstenc =
			 (votos_correo > 0.2 * votos_presenciales) ||
			 (votos_correo > 0.2 * abstencion);
			 
		cout << "\t- El n�mero de votos por correo es mayor que el 20% de "
			 << "los votos presenciales o el n�mero de abstenciones: "
			 << votos_correo_mayor_20xciento_presen_abstenc << endl;
		
	//Q
		int votos_nulos_correo = votos_correo - votos_validos_correo;
		int votos_nulos_presenciales = 
			votos_presenciales - votos_validos_presenciales;
		
		bool nulos_correo_mayor_nulos_presenciales =
			 (votos_nulos_correo > votos_nulos_presenciales);
			 
		cout << "\t- El n�mero de votos nulos por correo es mayor que el "
			 << "n�mero de votos nulos presenciales: " 
			 << nulos_correo_mayor_nulos_presenciales << endl; 
		
	//R
		bool nulos_correo_mayor_validos_correo = 
			 votos_nulos_correo > votos_validos_correo;
			 
		cout << "\t- El n�mero de votos nulos por correo es mayor que el "
			 << "n�mero de votos v�lidos por correo: " 
			 << nulos_correo_mayor_validos_correo << endl;
		
	return 0;
}
