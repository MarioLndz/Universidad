//
// Created by mario on 18/04/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// Algoritmo de kruskal = Diapositiva 50
// Problema de viajante de comercio = Diapositiva 133

int main (int argc, char * argv[]){
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


    visita.push_back(0);  // la empresa está en 0
    int pos_actual = 0;   // posicion en la que estamos

    int indice_minimo = 1;   // para calcular la siguiente posicion
    int min_dist = distancias[pos_actual][indice_minimo];

    int distancia_solucion = 0;

    high_resolution_clock::time_point t_antes, t_despues;
    duration<double> transcurrido;

    t_antes = high_resolution_clock::now();

    while (visita.size() < NUM_NODOS){
        min_dist = 500;
        for (int i = 1; i < NUM_NODOS; ++i){
            int num = distancias[pos_actual][i];

            if((!ya_pertenece[i]) && (num < min_dist) && (i != pos_actual)){
                min_dist = num;
                indice_minimo = i;
            }
        }
        distancia_solucion += min_dist;

        pos_actual = indice_minimo;
        visita.push_back(pos_actual);
        ya_pertenece[pos_actual] = true;
    }

    distancia_solucion += distancias[visita.at(0)][visita.at(visita.size()-1)];

    t_despues = high_resolution_clock::now();
    transcurrido = duration_cast<duration<double>>(t_despues - t_antes);

    cout << NUM_NODOS << "\t" << transcurrido.count() << endl;


    /*

    cout << "ORDEN DE VISITA:\t";
    for (auto it = visita.begin(); it != visita.end(); ++it)
        cout << *it << "\t";
    cout << endl;

     */



    //cout << distancia_solucion << endl;


    return (0);

}
