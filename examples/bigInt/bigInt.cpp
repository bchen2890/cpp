#include "bigInt.h"
#include <ctype.h>
#include<iostream>
#include <string.h>
#include <string>

const int ASCCI_ZERO_PLACE = 48;
const string ZERO_VALUE = "0";
const string ONE_VALUE = "1";
const char MINUS_CHAR = '-';

BigInt::BigInt(){
    digits = ZERO_VALUE;
}

BigInt::BigInt(long long n){
    sign = false;
    if (n < 0){
        sign = true;
        n *= -1;
    }
    digits = to_string(n);
}

BigInt::BigInt(BigInt & other){
    digits = other.digits;
}

BigInt::BigInt(const string & s){
    if(s[0] == MINUS_CHAR) {
        sign = true;
        digits = s.substr(1);
    } else {
        size_t found = s.find_first_not_of(ZERO_VALUE);
        if(found != string::npos){
            digits = s.substr(found);
        } else {
            digits = ZERO_VALUE;
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
        aligned = ZERO_VALUE + aligned;
    }
    return aligned;
}

unsigned long BigInt::length() const{
    if (digits == ZERO_VALUE)
        return 0;
    return digits.length();
}


ostream &operator<<(ostream &os,const BigInt &n) {
    return os << n.toString();
}

string BigInt::toString() const{
    if (length() == 0 || getDigits() == ZERO_VALUE) {
        return ZERO_VALUE;
    }
    if(getSign())
        return MINUS_CHAR + getDigits();
    else
        return getDigits();
}

string BigInt::addDigits(const BigInt& other) const{
    int carry = 0, s, i;
    int n = other.length();
    if( length() > n )
        return other.addDigits(*this);
    string a = getDigits(), b = other.getDigits();

    a = align(n - length());


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
    size_t found = a.find_first_not_of(ZERO_VALUE);
    if(found != string::npos){
        return a.substr(found);
    } else {
        return ZERO_VALUE;
    }
}

string BigInt::multiply(const BigInt& other) const {
    // Karatsuba algorithm
    int n = length()>other.length()?length(): other.length();
    string a = align(n-length()), b = other.align(n - other.length());

    if(n <= 1)
        return to_string((a[0]-ASCCI_ZERO_PLACE)*(b[0]-ASCCI_ZERO_PLACE));

    int m = n/2;
    BigInt x1 = *new BigInt(a.substr(0, m));
    BigInt x0 = *new BigInt(a.substr(m, n-m));
    BigInt y1 = *new BigInt(b.substr(0, m));
    BigInt y0 = *new BigInt(b.substr(m, n-m));

    BigInt z2 = *new BigInt(x1.multiply(y1));
    BigInt z0 = *new BigInt(x0.multiply(y0));
    BigInt z1 = *new BigInt((x1+x0).multiply(y1+y0)) - z2 - z0;

    string aux_z2B2m = z2.getDigits();
    string aux_z1Bm = z1.getDigits();

    // 10^(2(n-m)) & 10^(n-m) 
    for (int i = 0; i < n-m; i++){
        aux_z2B2m.append(ZERO_VALUE+ZERO_VALUE);
        aux_z1Bm.append(ZERO_VALUE);
    }
   
    BigInt z2B2m = *new BigInt(aux_z2B2m);
    BigInt z1Bm = *new BigInt(aux_z1Bm);
         
    BigInt result = *new BigInt(z2B2m + z1Bm + z0);

    return result.getDigits();
}

BigInt& BigInt::operator+(const BigInt & other) const {

    if(length()==0)
        return *new BigInt(other.getDigits());

    if(other.length()==0)
        return *new BigInt(getDigits());

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
        result = MINUS_CHAR + result;
    
    return *new BigInt(result);
}



BigInt& BigInt::operator-(const BigInt &other) const {
    // 0 - b = -b
    if (length() == 0)
        return *new BigInt(MINUS_CHAR + other.getDigits());
        
    // a - 0 = a
    if (other.length() == 0)
        return *new BigInt(getDigits());

    // a - b
    if (!getSign() && !other.getSign()) {
        if(*this > other)
            return *new BigInt(subtractDigits(other));
        // a - b = - (b - a)
        return *new BigInt(MINUS_CHAR + other.subtractDigits(*this));
    }

    // a - (-b) = a + b
    if (!getSign() && other.getSign())
        return *new BigInt(this->addDigits(other));

    // (-a) - b = - (a + b)
    if (getSign() && !other.getSign()) 
        return *new BigInt(MINUS_CHAR + this->addDigits(other));
    
    //(-a) - (-b) = b - a
    return *new BigInt(other.getDigits()) - *new BigInt(getDigits());
}

BigInt& BigInt::operator*(const BigInt &other) const {
    unsigned long n = length(), m = other.length();
    if(n == 0 || m == 0){
        return *new BigInt();
    }
    
    string result = "0";
    if(getDigits()==ONE_VALUE)
        result = other.getDigits();
    else if(other.getDigits()==ONE_VALUE)
        result = getDigits();  
    else
        result = (*this).multiply(other);

    if(getSign()!=other.getSign())
        return *new BigInt(MINUS_CHAR + result);

    return *new BigInt(result);
}

BigInt& BigInt::operator/(const BigInt &divider) const {
    if(divider.length()==0)
        throw runtime_error ("Error: Attemped to divide by Zero\n");
    if(length()==0)
        return *new BigInt();

    string result = "";
    if(divider.getDigits()==ONE_VALUE){
        result = getDigits();
    } else {
        //long division 
        BigInt abs_divider = *new BigInt(divider.getDigits());
        //|b| > |a|
        if(abs_divider > *new BigInt(getDigits()))
            return *new BigInt();

        unsigned long index = 0;
        BigInt temp = *new BigInt(to_string(digits[index] - ASCCI_ZERO_PLACE));

        while (temp < abs_divider){
            temp = temp * 10 + *new BigInt(to_string(digits[++index] - ASCCI_ZERO_PLACE));
        }
        while (index < length()){
            if (temp < abs_divider){
                result = result + ZERO_VALUE;
                temp = temp * 10 + *new BigInt(to_string(digits[++index] - ASCCI_ZERO_PLACE));
                continue;
            }
            BigInt multiplier(1);
            BigInt remainder = temp - abs_divider;
            while (remainder >= abs_divider){
                remainder = remainder - abs_divider;
                multiplier = multiplier + 1;
            } 
            result = result + multiplier.toString();
            temp = remainder * 10 + *new BigInt(to_string(digits[++index] - ASCCI_ZERO_PLACE));
        }
    }

    if(getSign()==divider.getSign())
        return *new BigInt(result);
    else
        return *new BigInt(MINUS_CHAR + result);
}

BigInt& BigInt::operator%(const BigInt &divider) const {
    if(divider.length()==0)
        throw runtime_error ("Error: Attemped to modulo by Zero\n");
    // 0%b = 0 & a%1= 0    
    if(length()==0 || divider.getDigits()==ONE_VALUE)
        return *new BigInt();

    //always positive result
    BigInt abs_dividend = *new BigInt(getDigits());
    BigInt abs_divider = *new BigInt(divider.getDigits());
    if(abs_divider > abs_dividend)
        return *new BigInt(abs_dividend);

    BigInt quotient = abs_dividend / abs_divider;
    BigInt remainder = abs_dividend - (abs_divider * quotient);

    return *new BigInt(remainder);
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

BigInt & pow (BigInt &base, BigInt &exp){
    if(exp.getDigits()==ZERO_VALUE)
        return *new BigInt(ONE_VALUE);
    if(exp < 0)
        return *new BigInt(ZERO_VALUE);

    return base * pow(base, exp-1);
}