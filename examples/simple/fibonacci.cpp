#include<iostream>
#include<iomanip>
#include <vector>

using namespace std;

vector<unsigned long long> fibonacciSequence (int n) {
    vector<unsigned long long> fibonacciList = vector<unsigned long long>(n+1);
    fibonacciList[0] = 0;
    if(n < 1) return fibonacciList;
    int index = 1;
    fibonacciList[index] = 1;
    while (index < n) {
        index++;
        fibonacciList[index] = fibonacciList[index-1] + fibonacciList[index-2];
    }
    return fibonacciList;
}

unsigned long long fibonacci (int n) {
    unsigned long long fib1 = 0, fib2 = 1, fib3;
    int index = 2;
    if (n < 1) return fib1;
    while (index <= n){
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
        index++;
    }
    return fib2;
}

int main() {
    int n = 93; // unsigned long long can store up to f(93)
    vector<unsigned long long> fibonacciList = fibonacciSequence(n);
    unsigned long long nFib = fibonacciList[fibonacciList.size()-1], otherNFid = fibonacci(n);
    if(nFib != otherNFid){
        cout << "Error: " << nFib << " is not equal to " << otherNFid << endl;
        return -1;
    }

    cout << "The first " << n << " numbers of the Sequence: ";
    for (int i=0; i<fibonacciList.size()-1; i++)
        cout << fibonacciList[i] << ", ";
    cout << nFib << endl;
    return 0;
}