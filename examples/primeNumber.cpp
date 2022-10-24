#include<iostream>
#include<iomanip>
#include <vector>

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

bool isPrimeCheckEven (int n) {
    if(n == 2) return true;
    if (n == 0 || n == 1 || n % 2 == 0)
        return false;
    
    bool flag = true; 
    for (int i = 3; i <= n/2; i=i+2) {
        if (n % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

void printIsPrime (int n) {
    bool check = isPrime(n);
    bool check2 = isPrimeCheckEven(n);
    cout << n <<" is ";
    if(check && check)
        cout << "prime";
    else if (check!=check2)
        cout << "unknown";
    else
        cout << "not prime";
    cout << endl;
}

vector<int> generatePrime (int n) {
    vector<int> primeList = vector<int>(n);
    primeList[0] = 2;
    int nActual = 3, nFound = 1;
    while (nFound < n) {
        int index = 0;
        bool thisIsPrime = true;
        while (index < nFound){
            if(nActual % primeList[index]==0){
                thisIsPrime = false;
                break;
            }
            index++;
        }
        if(thisIsPrime){
            primeList[nFound] = nActual;
            nFound++;
        }
        nActual++;
    }
    return primeList;
}

int main() {
    for (int i = 0; i<100; i++)
        printIsPrime(i);
    
    vector<int> list = generatePrime(100);
    for (int i = 0; i<list.size()-1; i++){
        cout<< list[i] << ", ";
    }
    cout << list[list.size()-1] << endl;
    return 0;
}