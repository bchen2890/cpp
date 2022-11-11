#include "bigInt.h"
#include<iostream>
#include<vector>
#include <stdlib.h>     /* abs */
#include <math.h>       /* pow, sqrt */

using namespace std;

void testArithmetic(long long a, long long b, char op){
    BigInt result, intA(a), intB(b);
    long long expected = 0;
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
        case '*':
            result = intA * intB;
            expected = a * b;
            break;
        case '/':
            result = intA / intB;
            expected = a / b;
            break;
        case '%':
            result = intA % intB;
            expected = abs(a % b);
            break;
        default:
            break;
    }
    if(to_string(expected) == result.toString())
        cout << "(" << intA << ") " << op << " (" 
                << intB << ") = " << result << endl; 
    else
        cout << "Error: (" << a << ") " << op << " (" << b 
                << ") expected to be " << expected 
                << " but got " << result << endl;
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
        cout << "(" << intA << ") " << op 
                << " (" << intB << ") = " << boolString << endl; 
    else
        cout << "Error: (" << a << ") " << op << " (" << b 
                << ") expected to be " << expected 
                << " but got " << boolString << endl;
}

void testPow(long long a, long long b){
    BigInt intA(a), intB(b);
    long long expected = long(pow(a, b));
    BigInt result = pow(intA, intB);

    if(to_string(expected) == result.toString())
        cout << "pow(" << intA << "," << intB 
        << ") = " << result << endl; 
    else
        cout << "Error:" << "pow(" << intA << "," << intB 
                << ") expected to be " << expected 
                << " but got " << result << endl;
}

void testSqrt(long long x){
    BigInt intX(x);
    unsigned long expected = (unsigned long)(sqrt(x));
    BigInt result = sqrt(intX);

    if(to_string(expected) == result.toString())
        cout << "sqrt(" << intX << ") = " << result << endl; 
    else
        cout << "Error:" << "sqrt(" << intX << ") expected to be "
                << expected << " but got " << result << endl;
}

void testNFunction(int n, string func, string expected){
    BigInt result;
    if(func == "factorial"){
        result = factorial(n);
    } else if(func == "fibonacci"){
        result = fibonacci(n);
    }
    if(expected == result.toString())
        cout << func << "(" << n << ") = " << result << endl; 
    else
        cout << "Error:"  << func << "(" << n 
                << ") expected to be " << expected 
                << " but got " << result << endl;
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
    testArithmetic(5, 4, '+');

    testArithmetic(0, 0, '-');
    testArithmetic(2472, 0, '-');
    testArithmetic(0, 6811, '-');
    testArithmetic(78370, 2611, '-');
    testArithmetic(18379, 26114, '-');
    testArithmetic(78379, -26114, '-');
    testArithmetic(-182434, 4572689, '-');
    testArithmetic(-1248754, -7287542, '-');

    testArithmetic(0, 0, '*');
    testArithmetic(10, 1, '*');
    testArithmetic(1, 72, '*');
    testArithmetic(10, 5, '*');
    testArithmetic(0, 235, '*');
    testArithmetic(5635, 0, '*');
    testArithmetic(12345, 6789, '*');
    testArithmetic(678, 27491, '*');
    testArithmetic(-214348, -6298457, '*');
    testArithmetic(4219, -129357, '*');
    testArithmetic(-97307, 8193, '*');
    testArithmetic(909090909, 11, '*');
    testArithmetic(-1, 1, '*');
    testArithmetic(-1, -1, '*');
    testArithmetic(1, -1, '*');

    // testArithmetic(0, 0, '/'); // throw error
    testArithmetic(0, 1, '/');
    testArithmetic(0, 3947, '/');
    testArithmetic(18254, 1, '/');
    testArithmetic(-2379, -1, '/');
    testArithmetic(6631, -1, '/');
    testArithmetic(-8772, 1, '/');
    testArithmetic(-8771, 2, '/');
    testArithmetic(7902, 11, '/');
    testArithmetic(91389, 3980, '/');
    testArithmetic(1828980, 810, '/');
    testArithmetic(456, 3992, '/');
    testArithmetic(-198, 33, '/');
    testArithmetic(6137, -9, '/');
    testArithmetic(-893, 918, '/');
    testArithmetic(893, -918, '/');
    testArithmetic(9999999999, 11, '/');
    testArithmetic(900000009, 11, '/');


    // testArithmetic(0, 0, '%'); // throw error
    testArithmetic(0, 13, '%');
    testArithmetic(24747, 1, '%');
    testArithmetic(8, 9, '%');
    testArithmetic(900000009, 11, '%');
    testArithmetic(-8963, 11, '%');
    testArithmetic(180, -11, '%');
    testArithmetic(81924, 123, '%');
    testArithmetic(81918, 123, '%');

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

    testPow(8, 0);
    testPow(2, 1);
    testPow(1, 23);
    testPow(8, 0);
    testPow(-1, 2);
    testPow(-1, 3);
    testPow(4, 3);
    testPow(-3, 4);
    testPow(3, -1);
    testPow(-5, 5);
    testPow(-24, -5);
    testPow(-24, 3);
    testPow(24, 6);
    testPow(11, 8);
    testPow(2, 10);

    testNFunction(1, "factorial", "1");
    testNFunction(12, "factorial", "479001600");
    testNFunction(100, "factorial", "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
    testNFunction(200, "factorial", "788657867364790503552363213932185062295135977687173263294742533244359449963403342920304284011984623904177212138919638830257642790242637105061926624952829931113462857270763317237396988943922445621451664240254033291864131227428294853277524242407573903240321257405579568660226031904170324062351700858796178922222789623703897374720000000000000000000000000000000000000000000000000");
   
    testNFunction(0, "fibonacci", "0");
    testNFunction(1, "fibonacci", "1");
    testNFunction(23, "fibonacci", "28657");
    testNFunction(97, "fibonacci", "83621143489848422977");
    testNFunction(241, "fibonacci", "103881042195729914708510518382775401680142036775841");
    testNFunction(300, "fibonacci", "222232244629420445529739893461909967206666939096499764990979600");
    testNFunction(999, "fibonacci", "26863810024485359386146727202142923967616609318986952340123175997617981700247881689338369654483356564191827856161443356312976673642210350324634850410377680367334151172899169723197082763985615764450078474174626");

    testSqrt(0);
    testSqrt(1);
    testSqrt(4);
    testSqrt(5);
    testSqrt(8);
    testSqrt(121);
    testSqrt(9284);
    testSqrt(89);
    testSqrt(12345);
    testSqrt(999999);
    return 0;
}