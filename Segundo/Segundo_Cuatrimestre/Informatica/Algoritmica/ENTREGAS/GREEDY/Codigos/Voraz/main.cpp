#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

bool Pertenece(const vector<int> & v,int n){            // O(n)

    bool pertenece=false;
    int contador=0;

    while(!pertenece && contador<v.size()){

        if(v.at(contador)==n)
            pertenece=true;

        contador++;
    }

    return pertenece;
}

int CancionMasLejana (const vector<int> & inmediato, const vector<int> & peticiones, int pos_inicial){
    int indice = 0;
    int max_distancia = 0;
    int contador = 0;

    for (int i = 0; contador != peticiones.size() && i < inmediato.size(); ++i){
        bool encontrado = false;
        contador = pos_inicial;

        while (contador < peticiones.size() && !encontrado){
            if (inmediato.at(i) == peticiones.at(contador)){
                encontrado = true;
            } else {
                ++contador;
            }
        }

        if (contador > max_distancia){
            max_distancia = contador;
            indice = i;
        }
    }
    return (indice);
}


int main (int argc, char * argv[]) {
    if (argc != 2){
        cout << "ERROR: NUMERO INCORRECTO DE ARGUMENTOS" << endl;
        exit (-1);
    }

    ifstream file;
    file.open(argv[1]);

    if (!file){
        cout << "ERROR ABRIENDO EL ARCHIVO" << endl;
        exit (-1);
    }

    vector<int> peticiones;  // peticiones de canciones realizadas por el cliente
    while (!file.eof()){
        int id;
        file >> id;

        peticiones.push_back(id);
    }

    file.close();

    const int NUM_PETICIONES = peticiones.size();
    const int TAMANIO_INMEDIATO = NUM_PETICIONES/5;
    /*
    cout << "Tamaño de la lista inmediata:\t" << TAMANIO_INMEDIATO << endl;
    */

    vector<int> inmediato;    // canciones que están en la reproducción inmediata

    int NUM_INTERCAMBIOS = 0;
    /*
    cout << "VECTOR DE PETICIONES:\t";
    for (int i = 0; i < NUM_PETICIONES; ++i)
        cout << peticiones.at(i) << "\t";
    cout << endl << endl;
    */
    high_resolution_clock::time_point t_antes, t_despues;
    duration<double> transcurrido;

    t_antes = high_resolution_clock::now();

    for (int i = 0; i < NUM_PETICIONES; ++i){
        if (!Pertenece(inmediato, peticiones.at(i))){ // Pertenece = O(N)
            if (inmediato.size() < TAMANIO_INMEDIATO){
                inmediato.push_back(peticiones.at(i));

            } else {
                inmediato.at(CancionMasLejana(inmediato, peticiones, i)) = peticiones.at(i);
                ++NUM_INTERCAMBIOS;
            }

        }
    }

    t_despues = high_resolution_clock::now();
    transcurrido = duration_cast<duration<double>>(t_despues - t_antes);
    cout << NUM_PETICIONES << "\t" << transcurrido.count() << endl;

    return 0;
}