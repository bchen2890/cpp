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

string BigInt::align(const long l) const{
    string aligned = digits;
    for (long i=0; i<l; i++){
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
    return os << n.toString();
}

string BigInt::toString() const{
    if (length() == 0 || getDigits() == "0") {
        return "0";
    }
    if(getSign())
        return "-" + getDigits();
    else
        return getDigits();
}

string BigInt::addDigits(const BigInt& other) const{
    int carry = 0, s, i;
    int n = other.length();
    string a = getDigits(), b = other.getDigits();

    a = align(n - length());

    const int ASCCI_ZERO_PLACE = 48;
    for (long i = n-1; i>=0; i--){
        s=a[i] + b[i] - ASCCI_ZERO_PLACE * 2 + carry;
        carry = s/10;
        a[i] = (char) (s%10 + ASCCI_ZERO_PLACE);
    }

    if (carry)
        a = "1" + a;

    return a;
}

string BigInt::subtractDigits(const BigInt& other) const {
    int carry = 0, s, i;
    int n = length();
    if( other.length() > n )
        return other.subtractDigits(*this);
    string a = getDigits(), b = other.align(n - other.length());
    const int ASCCI_ZERO_PLACE = 48;
    for (long i = n-1; i>=0; i--){
        s = a[i] - b[i] - carry;
        carry = 0;
        if (s<0){
            s+=10;
            carry = 1;
        }
        a[i] = (char) (s + ASCCI_ZERO_PLACE);
    }

    return a;
}

BigInt& BigInt::operator+(const BigInt & other) const {
    //a + (-b) = a - b
    if (!getSign() && other.getSign()) {
       // return *((new BigInt(getDigits())) - (new BigInt(other.getDigits())));
    }

    //(-a) + b = b - a
    if (getSign() && !other.getSign()) {
       // return *((new BigInt(other.getDigits())) - (new BigInt(getDigits())));
    }

    // a + b
    std::string result = addDigits(other);

    //(-a) + (-b) = -(a + b)
    if (getSign() && other.getSign()) 
        result = '-' + result;

    cout << "result = " << result << endl;
    return *new BigInt(result);
}



BigInt& BigInt::operator-(const BigInt &other) const {
    // 0 - b = -b
    //if (length() == 0)

    // a - 0 = a
    if (other.length() == 0)
        return *new BigInt(digits);

    // a - b
    if (!getSign() && !other.getSign()) {
        return *new BigInt(subtractDigits(other));
    }

    // a - (-b) = a + b
    if (!getSign() && other.getSign())
        return *new BigInt(this->addDigits(other));

    // (-a) - b = - (a + b)
    if (getSign() && !other.getSign()) 
        return *new BigInt('-' + this->addDigits(other));
    
    //(-a) - (-b) = b - a
    BigInt temp1 = *new BigInt(digits); 
    BigInt temp2 = *new BigInt(other.digits);

    return temp2 - temp1;
}

BigInt& BigInt::operator*(const BigInt &other) const {
    return *new BigInt(other.getDigits());
}



