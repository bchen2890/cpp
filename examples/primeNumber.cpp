#include<iostream>
#include<iomanip>

using namespace std;

bool isPrime (int n) {
    if (n == 0 || n == 1) {
        return false;
    }

    bool flag = true; 
    for (int i = 2; i <= n/2; ++i) {
        if (n % i == 0) {
        flag = false;
        break;
        }
    }
    return flag;
}

void printIsPrime (int n) {
    cout << n <<" is ";
    if(isPrime(n))
        cout << "prime";
    else
        cout << "not prime";
    cout << endl;
}

int main() {
    for (int i = 0; i<100; i++)
        printIsPrime(i);

    return 0;
}