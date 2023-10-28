//
// Created by mario on 22/04/23.
//
#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

int main (int argc, char * argv[]){
    if (argc != 2 && argc != 3){
        cout << "ERROR: FALTA NUMERO DE CASOS A GENERAR" << endl;
        exit (-1);
    }

    srand(time(NULL));

    int num_casos = atoi(argv[1]);
    string fichero = argc == 2 ? "data_jukebox" : argv[2];

    ofstream file;
    file.open(fichero.c_str());

    if (!file){
        cout << "ERROR ABRIENDO ARCHIVO" << endl;
        exit (-1);
    }

    for (int i = 0; i < num_casos; ++i){
        int num = rand()%num_casos;
        file << num << endl;
    }

    return (0);
}
