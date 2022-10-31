#ifndef BIG_INT_H
#define BIG_INT_H
#include <string>
using namespace std;

class BigInt;


class BigInt {
    string value;
    bool sign = false;
public:

    //Constructors:
    BigInt(unsigned long long n = 0);
    BigInt(BigInt &);
    BigInt(string &);
    BigInt(const char *);

    //Arithmetic operators:
    BigInt operator + (BigInt const &other);
    BigInt operator - (BigInt const &other);
    BigInt operator * (BigInt const &other);
    BigInt operator / (BigInt const &other);
    BigInt operator % (BigInt const &other);

    //Relational operators:
    bool operator == (const BigInt&);
    bool operator != (const BigInt&);
    bool operator >= (const BigInt&);
    bool operator <= (const BigInt&);
    bool operator > (const BigInt&);
    bool operator < (const BigInt&);

    //Stream operators:
    friend ostream & operator << (ostream &out, const BigInt &n);
    friend istream & operator >> (istream &in,  BigInt &n);
    
    //Others:
    unsigned long length();
    friend BigInt pow(BigInt &a, BigInt &b);
    friend BigInt sqrt(BigInt &a);
    friend BigInt factorial(int n);
    friend BigInt fibonacci(int n);
};

#endif //BIG_INT_H
