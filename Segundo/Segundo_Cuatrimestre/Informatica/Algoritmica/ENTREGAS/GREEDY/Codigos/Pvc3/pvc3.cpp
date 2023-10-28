//
// Created by mp on 23/04/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// algoritmo de inserción
// eficiencia n²log2(n), n³

// https://code-with-me.global.jetbrains.com/QMEr96kuffnKWYZy8TvYeA#p=CL&fp=E3C0370DBA44241E9419D98EE3D076413908BBBE8850DE1D9702946C969822F4

int main(int argc, char * argv[]){

    if (argc != 2) {
        cout << "NUMERO INCORRECTO DE ARGUMENTOS" << endl;
        exit(-1);
    }

    ifstream file;
    file.open(argv[1]);

    if (!file){
        cout << "ERROR ABRIENDO EL ARCHIVO" << endl;
        exit(-1);
    }

    int aux;
    file >> aux;

    const int NUM_NODOS = aux;

    vector<vector<int>> distancias (NUM_NODOS);
    for (int i = 0; i < NUM_NODOS; ++i){
        distancias[i].reserve(NUM_NODOS);
    }

    vector<bool> ya_pertenece(NUM_NODOS);

    for (int i = 0; i < NUM_NODOS; ++i) {
        distancias[i][i] = -1;
        for (int j = i+1; j < NUM_NODOS; ++j) {
            int num;
            file >> num;
            distancias[i][j] = num;
            distancias[j][i] = num;
        }
        ya_pertenece[i] = false;
    }

    file.close();

    vector<int> visita;
    visita.resize(NUM_NODOS);

    // en primer lugar buscamos el nodo más cercanos de 0

    int minimo = 100;
    int p1 = 1;

    high_resolution_clock::time_point t_antes, t_despues;
    duration<double> transcurrido;

    t_antes = high_resolution_clock::now();

    for(int i = 1; i < NUM_NODOS; ++i){
        if(distancias[0][i] < minimo){
            minimo = distancias[0][i];
            p1 = i;
        }

    }

    visita.at(0) = 0;                    // metemos 0 al principio salimos de la empresa
    visita.at(NUM_NODOS-1)=p1;          // metemos p1 al final que es el
    // ya sabemos que la minima distancia es minimo y que se produce entre los puntos p1 y 0
    // vamos a coger el nodo k que tenga menor cantidad dist(p1,k) + dist(0,k) - dist(p1,0)
    ya_pertenece[0] = true;
    ya_pertenece[p1] = true;


    int contador=1, indice=0;
    int distancia_solucion = 0;

    while(contador < NUM_NODOS-1){
        int suma_minima=200;
        for (int i = 1; i < NUM_NODOS; ++i){
            int num = distancias[i][p1] + distancias[i][0] - minimo;
            if((!ya_pertenece[i]) && (num < suma_minima) && (i != p1)){
                suma_minima=num;
                indice=i;

            }
        }
        visita.at(NUM_NODOS-contador-1)=indice;  // lo metemos en la última posición no ocupada
        ya_pertenece[indice] = true;

        p1=indice;
        distancia_solucion += suma_minima;
        contador++;
    }

    t_despues = high_resolution_clock::now();
    transcurrido = duration_cast<duration<double>>(t_despues - t_antes);

    cout << NUM_NODOS << "\t" << transcurrido.count() << endl;

    /*
    cout << "ORDEN DE VISITA:\t";
    for (auto it = visita.begin(); it != visita.end(); ++it)
        cout << *it << "\t";

    cout << endl;
    cout << endl;

    distancia_solucion += distancias[visita.at(0)][visita.at(visita.size()-1)];
    cout << "distancia reocrrida:" << endl;

    */
    //cout << distancia_solucion << endl;

    return 0;
}
