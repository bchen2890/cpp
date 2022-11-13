#include<iostream>
#include <math.h>       /* sqrt */
#include <stdlib.h>     /* abs */

using namespace std;

void quadraticEquation (double a, double b, double c) {
    double discriminant = b * b - 4.0 * a * c;
    if(discriminant >= 0.0){
        cout << "x1 = " << (-b + sqrt(discriminant)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(discriminant)) / (2 * a) << endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

int main() {
    double a, b, c;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;
    quadraticEquation(a, b, c);
    return 0;
}