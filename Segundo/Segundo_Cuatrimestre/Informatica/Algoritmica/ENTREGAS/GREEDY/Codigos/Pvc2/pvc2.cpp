//
// Created by mario on 21/04/23.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

struct Arista {
    int origen;
    int destino;

    int peso;

    bool operator< (const Arista & otro) const {
        return(this->peso > otro.peso);
    }

};

ostream & operator<< (ostream & os, const Arista & arista){
    os << "{" << arista.origen << "->" << arista.destino << " (" << arista.peso << ")}";
    return (os);
}

int BuscaRaiz (const vector<int> & caminos, int hoja){
    while (hoja != caminos[hoja]){
        hoja = caminos[hoja];
    }

    return (hoja);
}

int compareAristas (const void * a, const void * b) {
    Arista * ar1 = (Arista*)a;
    Arista * ar2 = (Arista*)b;

    int retorno = 0;

    if (ar1->peso < ar2->peso){
        retorno = 1;
    } else {
        retorno = -1;
    }
    return (retorno);
}


int main (int argc, char * argv[]){
    // LEEMOS LA MATRIZ DE DISTANCIAS DESDE FICHERO
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

    int aux = 0;
    file >> aux;

    const int NUM_NODOS = aux;

    // Reserva de memoria
    int ** distancias = new int * [NUM_NODOS];
    for( int i=0; i < NUM_NODOS; i++ )
        distancias[i] = new int[NUM_NODOS];

    // Leemos los datos y montamos la matriz de distancias
    for (int i = 0; i < NUM_NODOS; ++i) {
        distancias[i][i] = -1;
        for (int j = i+1; j < NUM_NODOS; ++j) {
            int num;
            file >> num;
            distancias[i][j] = num;
            distancias[j][i] = num;
        }
    }
    /*
    for (int i = 0; i < NUM_NODOS; ++i){
        for (int j = 0; j < NUM_NODOS; ++j)
            cout << distancias[i][j] << "\t";
        cout << endl;
    }
     */

    file.close();

    /*
    for (int i = 0; i < NUM_NODOS; ++i){
        for (int j = 0; j < NUM_NODOS; ++j)
            cout << distancias[i][j] << "\t";
        cout << endl;
    }*/

    // CREAMOS EL VECTOR DE ARISTAS. Aprovecharemos que las distancias son simétricas
    vector<Arista> aristas;
    for (int i = 0; i < NUM_NODOS; ++i){
        for (int j = i+1; j < NUM_NODOS; ++j){
            aristas.push_back(Arista{i,j,distancias[i][j]});
        }
    }

    // Ordenamos las aristas segun su peso de forma descendiente
    qsort(aristas.data(), aristas.size(), sizeof(Arista), compareAristas);

    /*
    cout << "ARISTAS:\t";
    for (auto it = aristas.begin(); it != aristas.end(); ++it){
        cout << *it << "\t";
    }
    cout << endl;
     */

    vector<int> caminos;    // Vector que guardara el camino seguido ( [0] = 1 Significa que 0 --> 1
    int num_conexiones[NUM_NODOS];  // Guardara el numero de conexiones que posee cada nodo

    for (int i = 0; i < NUM_NODOS; ++i){
        caminos.push_back(i);
        num_conexiones[i] = 0;
    }

    vector<Arista> solucion;

    high_resolution_clock::time_point t_antes, t_despues;
    duration<double> transcurrido;

    t_antes = high_resolution_clock::now();

    while (solucion.size() < NUM_NODOS-1){
        Arista siguiente_arista = aristas.back();
        aristas.pop_back();

        int origen = siguiente_arista.origen;
        int destino = siguiente_arista.destino;

        // Cada nodo solo podrá tener dos conexiones
        if ((num_conexiones[origen] < 2) && (num_conexiones[destino] < 2)){
            int raiz_a = BuscaRaiz(caminos, origen);    // O(n)
            int raiz_b = BuscaRaiz(caminos, destino);   // O(n)

            if (raiz_a != raiz_b){
                solucion.push_back(siguiente_arista);
                caminos[origen] = destino;
                ++num_conexiones[origen];
                ++num_conexiones[destino];
            }

        }
    }

    // Buscamos la ultima conexion faltante para completar el ciclo
    bool done = false;
    int i = 0;
    while (!done){  // O(n)
        if (num_conexiones[i] == 1){
            int j = i+1;
            while (!done){
                if (j != i && num_conexiones[j] == 1){
                    solucion.push_back(Arista{j,i,distancias[i][j]});
                    done = true;
                }
                ++j;
            }
        }
        ++i;
    }

    t_despues = high_resolution_clock::now();
    transcurrido = duration_cast<duration<double>>(t_despues - t_antes);


    cout << NUM_NODOS << "\t" << transcurrido.count() << endl;

    /*
    int distancia_solucion = 0;



    for (auto it = solucion.begin(); it != solucion.end(); ++it){
        distancia_solucion += it->peso;
    }


    cout << distancia_solucion << endl;

     */


    // Liberación de la memoria
    for( int i = 0; i < NUM_NODOS; i++ )
        delete[] distancias[i];

    delete[] distancias;

    return (0);

}
