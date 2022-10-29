/**
 * @file Histogram.cpp
 * @note To be implemented by students 
 * @author MP
 */
#include <iostream>
#include <string>
#include "MPTools.h"
#include "Byte.h"
#include "Histogram.h"

using namespace std;

const double Histogram::HISTOGRAM_TOLERANCE=0.01; ///< Value of the default tolerance

Histogram::Histogram(){
	int tamanio = size();
	for (int i = 0; i < tamanio; i++){
		_data[i] = 0;
	}
}

int Histogram::size() const {
	return (HISTOGRAM_LEVELS);
}

void Histogram::clear() {
	for (int i = 0; i < size(); i++){
		_data[i] = 0;
	}
}

int Histogram::getLevel(Byte level) const{
	return (_data[level.getValue()]);
	
}

void Histogram::setLevel(Byte level, int npixeles){
	_data[level.getValue()] = npixeles;
}

int Histogram::getMaxLevel() const{
	int tamanio = size();
	int maximo = 0;
	
	for (int i = 1; i < tamanio; i++){
		//Nuevo maximo
		if (getLevel(i) > getLevel(maximo)){
			maximo = i;
		}
		
	}
	
	return (getLevel(maximo));
}

int Histogram::getAverageLevel() const{
	int suma = 0;
	int tamanio = size();
	
	for (int i = 0; i < tamanio; i++){
		suma += getLevel(i);
		
	}
	
	int average = suma/tamanio;
	
	return (average);
}

int Histogram::getBalancedLevel() const{
	int suma = 0;
	int tamanio = size();
	
	//Calculamos la suma "exacta" de la mediana
	for (int i = 0; i < tamanio; i++){
		suma += getLevel(i);
		
	}
	
	int mediana = suma/2;
	
	//Buscamos el nivel que se corresponda con dicho valor (calcular la mediana)
	
	int tono = -1;
	bool encontrado = false;
	int acumulada = 0;
	
	while (!encontrado && tono < tamanio){
		tono++;
		acumulada += getLevel(tono);
		
		encontrado = acumulada >= mediana;
		
	}
	
	
	return (tono);
}

string Histogram::inspect() const{
    std::string result = "";
    for (int i = 0; i < HISTOGRAM_LEVELS; i++) {
        result += to_string(_data[i]);
    }
    result = std::to_string(mphash((unsigned char*)result.c_str(), result.length()));
    result = std::to_string(HISTOGRAM_LEVELS) + " " + result;
    return result;
}