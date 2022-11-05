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
    if(s[0] == '-') {
        sign = true;
    } else {
        size_t found = s.find_first_not_of("0");
        if(found != string::npos){
            digits = s.substr(found);
        } else {
            digits = "0";
        }
    }
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
    // remove zeros
    return a.substr(a.find_first_not_of("0"));
}

string BigInt::multiply(const BigInt& other) const {
    // Karatsuba algorithm
    int n = length()>other.length()?length(): other.length();
    cout<< "a2=" << getDigits() << ", b2=" << other.getDigits() << endl;

    const int ASCCI_ZERO_PLACE = 48;
    string a = align(n-length()), b = other.align(n - other.length());

    if(n == 1)
        return to_string((a[0]-ASCCI_ZERO_PLACE)*(b[0]-ASCCI_ZERO_PLACE));

    int m = n/2;
    cout<< "m=" << m << ", n=" << n << endl;
    BigInt x0 = *new BigInt(a.substr(0, m));
    BigInt x1 = *new BigInt(a.substr(m, n-m));
    BigInt y0 = *new BigInt(b.substr(0, m));
    BigInt y1 = *new BigInt(b.substr(m, n-m));
    cout<< "a=" << a << ", b=" << b << endl;

    cout<< "x0=" << x0 << ", x1=" << x1 
    << ", y0=" << y0
    << ", y1=" << y1 << endl;

    BigInt z2 = *new BigInt(x1.multiply(y1));
    BigInt z0 = *new BigInt(x0.multiply(y0));
        cout<< "z2=" << z2 << ", z0=" << z0 
     << ", x1+x0 =" << x1+x0 << endl;
    BigInt z1 = *new BigInt((x1+x0).multiply(y1+y0)) - z2 - z0;

    string aux_z2B2m = z2.getDigits();
    string aux_z1Bm = z1.getDigits();

    for (int i = 0; i < m-1; i++){
        aux_z2B2m.append("00");
        aux_z1Bm.append("0");
    }

    BigInt z2B2m = *new BigInt(aux_z2B2m);
    BigInt z1Bm = *new BigInt(aux_z1Bm);

    cout<< "z2B2m=" << z2B2m << ", z1Bm=" << z1Bm << endl;
         
    BigInt result = *new BigInt(z2B2m + z1Bm + z0);
    cout<< "result=" << result << endl;

    return result.getDigits();
}

BigInt& BigInt::operator+(const BigInt & other) const {
    // a + (-b) = a - b
    if (!getSign() && other.getSign()) 
        return *new BigInt(getDigits()) - *new BigInt(other.getDigits());
    
    // (-a) + b = b - a
    if (getSign() && !other.getSign()) 
        return *new BigInt(other.getDigits()) - *new BigInt(getDigits());
    
    // a + b
    std::string result = addDigits(other);

    // (-a) + (-b) = -(a + b)
    if (getSign() && other.getSign()) 
        result = '-' + result;

    return *new BigInt(result);
}



BigInt& BigInt::operator-(const BigInt &other) const {
    // 0 - b = -b
    if (length() == 0)
        return *new BigInt("-" + other.getDigits());
        
    // a - 0 = a
    if (other.length() == 0)
        return *new BigInt(getDigits());

    // a - b
    if (!getSign() && !other.getSign()) {
        if(*this > other)
            return *new BigInt(subtractDigits(other));
        // a - b = - (b - a)
        return *new BigInt("-" + other.subtractDigits(*this));
    }

    // a - (-b) = a + b
    if (!getSign() && other.getSign())
        return *new BigInt(this->addDigits(other));

    // (-a) - b = - (a + b)
    if (getSign() && !other.getSign()) 
        return *new BigInt('-' + this->addDigits(other));
    
    //(-a) - (-b) = b - a
    return *new BigInt(other.getDigits()) - *new BigInt(getDigits());
}

BigInt& BigInt::operator*(const BigInt &other) const {
    unsigned long n = length(), m = other.length();
    if(n == 0 || m == 0){
        return *new BigInt();
    }

    string result = (*this).multiply(other);

    if(getSign()!=other.getSign())
        return *new BigInt("-" + result);

    return *new BigInt(result);
}


bool BigInt::operator> (const BigInt& other) const{
    // a > -b
    if (getSign() && !other.getSign())
        return false;
    // b > -a
    if (!getSign() && other.getSign())
        return true;

    unsigned long n = length(), m = other. length();
    string a = getDigits(), b = other.getDigits();

    //both negative
    if (getSign() && other.getSign()) {
        if (n > m)
            return false;

        if (n < m)
            return true;

        for (long i = 0; i < n; i++) {
            if (a[i] > b[i])
                return false;

            if (a[i] < b[i])
                return true;
        }
    } else { //both positive
        if (n > m)
            return true;

        if (n < m)
            return false;

        for (long i = 0; i < n; i++) {
            if (a[i] > b[i])
                return true;

            if (a[i] < b[i])
                return false;
        }
    }

    // a == b
    return false;
}

bool BigInt::operator< (const BigInt& other) const{
    // a > -b
    if (getSign() && !other.getSign())
        return true;
    // b > -a
    if (!getSign() && other.getSign())
        return false;

    unsigned long n = length(), m = other. length();
    string a = getDigits(), b = other.getDigits();

    //both negative
    if (getSign() && other.getSign()) {
        if (n > m)
            return true;

        if (n < m)
            return false;

        for (long i = 0; i < n; i++) {
            if (a[i] > b[i])
                return true;

            if (a[i] < b[i])
                return false;
        }
    } else { //both positive
        if (n > m)
            return false;

        if (n < m)
            return true;

        for (long i = 0; i < n; i++) {
            if (a[i] > b[i])
                return false;

            if (a[i] < b[i])
                return true;
        }
    }

    // a == b
    return false;
}

bool BigInt::operator == (const BigInt& other) const{
    
    unsigned long n = length(), m = other.length();

    if (n == 0 && m == 0)
        return true;

    if (n != m)
        return false;

    if (getSign() != other.getSign())
        return false;

    string a = getDigits(), b = other.getDigits();

    for(long i = 0; i < n; i++){
        if (a[i] != b[i])
            return false;
    }

    return true;
}

bool BigInt::operator != (const BigInt& other) const{
    return !(*this == other);
}

bool BigInt::operator <= (const BigInt& other) const{
    return !(*this > other);
}

bool BigInt::operator >= (const BigInt& other) const{
    return !(*this < other);
}