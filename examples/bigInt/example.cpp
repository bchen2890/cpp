#include "bigInt.h"

#include<iostream>
#include<vector>
using namespace std;

void testArithmetic(long a, long b, char op){
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

void testRelational(long a, long b, string op){
    BigInt intA(a), intB(b);

    bool expected, result;
    if(op == "=="){
        result = intA == intB;
        expected = a == b;
    } else if(op == ">="){
        result = intA >= intB;
        expected = a >= b;
    } else if(op == "<="){
        result = intA <= intB;
        expected = a <= b;
    } else if(op == "!="){
        result = intA != intB;
        expected = a != b;
    } else if(op == ">"){
        result = intA > intB;
        expected = a > b;
    } else if(op == "<"){
        result = intA < intB;
        expected = a < b;
    } else {

    }
 
    string boolString = result? "true": "false";
    if(result == expected)
        cout << "(" << intA << ") " << op << " (" << intB << ") = " << boolString << endl; 
    else
        cout << "Error: (" << a << ") " << op << " (" << b 
                << ") expected to be " << expected << " but got " << boolString << endl;
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
    testArithmetic(0, 0, '+');
    testArithmetic(78379, 26114, '+');
    testArithmetic(-214348, -6298457, '+');
    testArithmetic(4219, -129357, '+');
    testArithmetic(-97307, 81938, '+');

    testArithmetic(0, 0, '-');
    testArithmetic(2472, 0, '-');
    testArithmetic(0, 6811, '-');
    testArithmetic(78379, 26114, '-');
    testArithmetic(18379, 26114, '-');
    testArithmetic(78379, -26114, '-');
    testArithmetic(-182434, 4572689, '-');
    testArithmetic(-1248754, -7287542, '-');

    // Test relational operators
    vector<string> compOps = {">", "<", ">=", "<=", "==", "!="};
    for(int i=0; i<compOps.size(); i++){
        testRelational(178412, -1235, compOps[i]);
        testRelational(-7384, 363811, compOps[i]);
        testRelational(-46384, -2982, compOps[i]);
        testRelational(-9203, -363811, compOps[i]);
        testRelational(-9203, -9213, compOps[i]);
        testRelational(-9192, -9112, compOps[i]);
        testRelational(178412, 363811, compOps[i]);
        testRelational(178412, 2982, compOps[i]);
        testRelational(9203, 363811, compOps[i]);
        testRelational(67944, 67142, compOps[i]);
        testRelational(67242, 67944, compOps[i]);
        testRelational(0, 0, compOps[i]);
        testRelational(812943, 812, compOps[i]);
        testRelational(-9283, 7684, compOps[i]);
        testRelational(7395, 37395, compOps[i]);
        testRelational(98396, 98396, compOps[i]);
    }
    return 0;
}