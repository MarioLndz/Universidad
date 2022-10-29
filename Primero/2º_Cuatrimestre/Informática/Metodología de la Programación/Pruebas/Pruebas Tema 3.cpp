#include <iostream>
using namespace std;
int main (){
	int *p1, *p2;
	
	p1 = new int;
	*p1 = 42;
	p2 = p1;
	cout << *p1 << " y " << *p2 << endl;	//42 y 42
	
	*p2 = 53;
	cout << *p1 << " y " << *p2 << endl;	//53 y 53
	
	p1 = new int;
	*p1 = 88;
	cout << *p1 << " y " << *p2 << endl;	//88 y 53
}

