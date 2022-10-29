#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (){
	ifstream f;
	
	f.open("./data.txt");
	string cadena;
	
	ofstream ox, oy;
	ox.open("./output/pt_x.txt");
	oy.open("./output/pt_y.txt");
	
	bool error = false;
	int c = 0;
	
	getline(f, cadena);
	
	if (f.eof()){
		error = true;
	} else {
		c++;
	}
	
	do {
		int pos = cadena.find("((");
		cadena = cadena.substr(5, cadena.length()-5);
		
		pos = cadena.find(",");
		string x = cadena.substr(0, pos);
		
		cadena = cadena.substr(pos+1, cadena.length()-pos);
		
		pos = cadena.find("),");
		string y = cadena.substr(0, pos);
		
		ox << x << ", ";
		oy << y << ", ";
		
		if (c%5 == 0){
			ox << endl;
			oy << endl;
		}
		
		getline(f, cadena);	//LABEL
		
		getline(f, cadena);	//NUEVO PUNTO
		
		if (f.eof()){
			error = true;
		} else {
			c++;
		}
		
	} while (!error);
	
	ox << endl << c;
	oy << endl << c;
	
}
