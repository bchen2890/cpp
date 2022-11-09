#ifndef BIG_INT_H
#define BIG_INT_H
#include <string>
using namespace std;

class BigInt;


class BigInt {
    string digits = "0";
    bool sign = false;
public:

    //Constructors:
    BigInt();
    BigInt(long long n);
    BigInt(BigInt &);
    BigInt(const string &);

    string getDigits() const;
    bool getSign() const;
    string align(const long) const;

    //Arithmetic operators:
    BigInt& operator+(const BigInt&) const;
    BigInt& operator-(const BigInt&) const;
    BigInt& operator*(const BigInt&) const;
    BigInt& operator/(const BigInt&) const;
    //always positive result
    BigInt& operator%(const BigInt&) const;

    //Relational operators:
    bool operator == (const BigInt&) const;
    bool operator != (const BigInt&) const;
    bool operator >= (const BigInt&) const;
    bool operator <= (const BigInt&) const;
    bool operator > (const BigInt&) const;
    bool operator < (const BigInt&) const;

    //Stream operators:
    friend ostream & operator << (ostream &os, const BigInt &n);
    friend istream & operator >> (istream &is,  BigInt &n);
    
    //Others:
    string toString() const;
    unsigned long length() const;
    friend BigInt &pow(BigInt &exp, BigInt &base);
    friend BigInt sqrt(BigInt &a);
    friend BigInt factorial(int n);
    friend BigInt fibonacci(int n);

    private:
    string subtractDigits(const BigInt&) const;
    string addDigits(const BigInt&) const;
    string multiply(const BigInt&) const;

};

#endif //BIG_INT_H
