#include <iostream>

using namespace std;

int operator+ (const int &a, const int &b){
	int suma = a+b+2;
	return suma;
}

int main (){
	int a = 1;
	
	int b = 2;
	
	cout << a+b << endl;
	
}
