#include<iostream>
#include<iomanip>

using namespace std;

/*
* Pre: r>0.0
* Post: print the diamater and the circumference
*/
void printDiameterAndCircumference (double r) {
    const double PI = 3.1416;
    cout << fixed << setprecision(2) << setw(8) << 2 * r << setprecision(3) << setw(18) << 2.0 * PI * r << endl;
}

int main() {
    cout << setw(10) << "Diameter" << setw(20) << "Circumferencia" << endl;
    cout << setw(10) << "========" << setw(20) << "==============" << endl;
    printDiameterAndCircumference(2.153);
    printDiameterAndCircumference(8.934);
    printDiameterAndCircumference(6.07);
    printDiameterAndCircumference(11.5);

    return 0;
}