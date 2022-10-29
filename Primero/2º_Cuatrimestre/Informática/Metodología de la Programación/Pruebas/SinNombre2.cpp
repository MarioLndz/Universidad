#include <iostream>
using namespace std;

void elevarAlCuadrado (int * p);

int main (){
	int a=6;
	int *q;
	q = &a;
	elevarAlCuadrado(q);
	cout << a << q; // Deber´ýa salir 36 0
	
	return 0;
}

void elevarAlCuadrado (int * &p){
	*p = (*p)*(*p);
	
}
