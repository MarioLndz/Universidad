#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main(int nargs, char * args[]) {
    string sread;
    if (nargs == 2) {
        ifstream fi;
        fi.open(args[1]);
        if (!fi) {
            cerr << "Error opening " << args[1] << endl;
        } else {
            fi >> sread;
            fi.close();
            for (int i = 0; i < sread.length(); i++) {
                sread[i] = sread[i] + 28;
            }
            cout << "Found a hidden message: " << sread << endl;
        }
    } else if (nargs == 3) {
        ofstream fo;
        fo.open(args[1]);
        if (!fo) {
            cerr << "Error opening " << args[1] << endl;
        } else {
            sread =  args[2];
            for (int i = 0; i < sread.length(); i++) {
                sread[i] = sread[i] - 28;
            }
            cout << sread << endl;
            fo << sread;
            fo.close();
        }
        
    } else {
        cerr << "Wrong number of arguments" << endl;
    }
    return 0;
}
