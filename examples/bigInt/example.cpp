#include "bigInt.h"

#include<iostream>
using namespace std;

void test(long a, long b, char op){
    BigInt result, intA(a), intB(b);
    long expected = 0;
    switch (op)
    {
    case '+':
        result = intA + intB;
        expected = a + b;
        break;
    case '-':
        result = intA - intB;
        expected = a - b;
        break;
    default:
        break;
    }
    if(to_string(expected) == result.toString())
        cout << "(" << intA << ") " << op << " (" << intB << ") = " << result << endl; 
    else
        cout << "Error: (" << a << ") " << op << " (" << b 
                << ") expected to be " << expected << " but got " << result << endl;
}
int main() {

    // Check constructors
    BigInt a(95813);
    BigInt b(-184277);
    BigInt c("2345678987651234679485678");
    BigInt d("-12245848534947966796756763788");
    BigInt e(a); 
    BigInt f; 

    cout << "a = " << a << endl; 
    cout << "b = " << b << endl; 
    cout << "c = " << c << endl; 
    cout << "d = " << d << endl; 
    cout << "e = " << e << endl; 
    cout << "f = " << f << endl; 

    // Test arithmetic operators
    test(0, 0, '+');
    test(78379, 26114, '+');
    test(-214348, -6298457, '+');
    test(4219, -129357, '+');
    test(-97307, 81938, '+');

    test(0, 0, '-');
    test(2472, 0, '-');
    test(0, 6811, '-');
    test(78379, 26114, '-');
    test(18379, 26114, '-');
    test(78379, -26114, '-');
    test(-182434, 4572689, '-');
    test(-182434, -4572689, '-');

    return 0;
}