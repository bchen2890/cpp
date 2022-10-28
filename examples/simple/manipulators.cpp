#include <iostream>
#include <iomanip>     
using namespace std;

int main () {
    int number = 77;
    cout << "setbase(16)" << endl;
    cout << setbase(16) << number << endl;
    cout << "using hex" << endl;
    cout << hex << number << endl;
    cout << "using oct" << endl;
    cout << oct << number << endl;
    cout << "using dec" << endl;
    cout << dec << number << endl;
    cout << "setw(10)" << endl;
    cout << setw(10) << number << endl;
    cout << "setfill('_')" << endl;
    cout << setfill('_') << setw(10) << number << endl;

    cout << "setprecision(4)" << endl;
    double pi = 3.141592653589793238462643;
    cout << setprecision(5) << pi << '\n';

    cout << "using showpos" << endl;
    cout << showpos << number << endl;
    cout << "using uppercase & nouppercase" << endl;
    cout << showbase << hex;
    cout << uppercase << number << '\n';
    cout << nouppercase << number << endl;

    cout << "using fixed" << endl;
    cout << fixed << pi << endl;

    cout << "using fixed" << endl;
    cout << scientific << pi << endl;

    cout << "using cout.width(10) & left & right" << endl;
    cout.width(10);
    cout << left << number << endl;
    cout.width(10);
    cout << right << number << endl;
        
    cout << "using boolalpha & noboolalpha" << endl;
    bool b = true;
    cout << boolalpha << b << endl;
    cout << noboolalpha << b << endl;
    return 0;
}