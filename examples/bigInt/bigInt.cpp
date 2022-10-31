#include "bigInt.h"
#include <ctype.h>
#include<iostream>
#include <string.h>

BigInt::BigInt(unsigned long long n){
    do{
        value.push_back(n % 10);
        n /= 10;
    } while (n);
}

BigInt::BigInt(BigInt & other){
    value = other.value;
}

BigInt::BigInt(string & s){
    value = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--){
        if(!isdigit(s[i]))
            throw("Error: string is not a integer");
        value.push_back(s[i] - '0');
    }
}

BigInt::BigInt(const char *s){
    value = "";
    for (int i = strlen(s) - 1; i >= 0;i--)
    {
        if(!isdigit(s[i]))
            throw("ERROR");
        value.push_back(s[i] - '0');
    }
}

ostream &operator<<(ostream &out,const BigInt &n){
    for (int i = n.value.size() - 1; i >= 0;i--)
        cout << (short)n.value[i];
    return cout;
}



