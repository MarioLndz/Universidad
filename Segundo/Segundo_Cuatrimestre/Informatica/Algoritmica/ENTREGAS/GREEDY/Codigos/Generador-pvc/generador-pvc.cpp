//
// Created by mario on 23/04/23.
//

#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <random>

using namespace std;

int main (int argc, char * argv[]){
    if (argc != 2 && argc != 3){
        cout << "ERROR: FALTA NUMERO DE NODOS A GENERAR" << endl;
        exit (-1);
    }


    int aux = atoi(argv[1]);
    const int NUM_CASOS = aux;
    string fichero = argc == 2 ? "data_pvc.txt" : argv[2];

    ofstream file;
    file.open(fichero.c_str());

    if (!file){
        cout << "ERROR ABRIENDO ARCHIVO" << endl;
        exit (-1);
    }

    file << NUM_CASOS << endl;

    srandom(time(NULL));
    std::random_device rd;
    std::default_random_engine eng (rd());
    std::uniform_int_distribution distr (0, 100);

    // Generamos tantos puntos como indique TOPE
    // Las coordenadas estarán entre ]-LIMITE_SUP, LIMITE_SUP[
    for (int i = 0; i < NUM_CASOS; ++i){
        for (int j = i+1; j < NUM_CASOS; ++j){
            int x = distr(eng);
            file << x << endl;
        }
    }

    file.close();

    return (0);
}
