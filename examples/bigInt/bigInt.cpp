#include "bigInt.h"
#include <ctype.h>
#include<iostream>
#include <string.h>
#include <string>

BigInt::BigInt(){
    digits = "0";
}

BigInt::BigInt(long long n){
    sign = 0;
    if (n < 0){
        sign = 1;
        n *= -1;
    }
    digits = to_string(n);
}

BigInt::BigInt(BigInt & other){
    digits = other.digits;
}

BigInt::BigInt(const string & s){
    digits = "";
    if(s[0] == '-') {
        sign = true;
        digits = s.substr(1);
    } else
        digits.append(s);
}

string BigInt::getDigits() const{
    return digits;
}

bool BigInt::getSign() const{
    return sign;
}

string BigInt::align(const unsigned long l) const{
    string aligned = digits;
    for (unsigned long i=0; i<l; i++){
        aligned = "0" + aligned;
    }
    return aligned;
}

unsigned long BigInt::length() const{
    if (digits == "0")
        return 0;
    return digits.length();
}



ostream &operator<<(ostream &os,const BigInt &n) {
    if (n.length() == 0 || n.getDigits() == "0") {
        return os << "0";
    }
    if (n.getSign()) os << '-';

        os << n.getDigits();
    return os;
}

BigInt BigInt::operator+(const BigInt & other) const{
    int carry = 0, s, i;
    int n = length(), m = other.length();
    string a = getDigits(), b = other.getDigits();
     if(m > n)
        a = align(m - n);
    n = m;

    const int ASCCI_ZERO_PLACE = 48;
    for (long i = n-1; i>=0; i--){
        s=a[i] + b[i] - ASCCI_ZERO_PLACE * 2 + carry;
        carry = s/10;
        a[i] = (char) (s%10 + ASCCI_ZERO_PLACE);
    }

    if (carry)
        a = "1" + a;

    return *new BigInt(a);
}





