#include<iostream>
#include<iomanip>
#include <map>

using namespace std;

map<char, int> romanValueSymbol = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1} };
const map<int, string> romanSymbolValue = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
         {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

string toRoman (int n) {
    string result = "";
    for (auto rit=romanSymbolValue.rbegin(); rit!=romanSymbolValue.rend(); ++rit)
        {
            while (n >= rit->first)
            {
                result += rit->second;
                n -= rit->first;
            }
        }
    return result;
}

int toInteger(string roman) {
    int result = 0;
    for(int i = 0; i < roman.length(); i++){
        if(romanValueSymbol[roman[i+1]] <= romanValueSymbol[roman[i]])  result += romanValueSymbol[roman[i]]; 
        else  result -= romanValueSymbol[roman[i]];  
    }
    return result;
}
void printConversion (int n){
    string roman = toRoman(n);
    int integer = toInteger(roman);
    if(n == integer)
        cout << n << "-->" << roman << endl;
    else
        cout << "Error conversion of: " << n << endl;
}

int main() {
    printConversion(7);
    printConversion(9);
    printConversion(15);
    printConversion(3);
    printConversion(63);
    printConversion(48);
    printConversion(84);
    printConversion(98);
    printConversion(126);
    printConversion(181);
    printConversion(192);
    printConversion(235);
    printConversion(357);
    printConversion(469);
    printConversion(511);
    printConversion(683);
    printConversion(722);
    printConversion(890);
    printConversion(910);
    printConversion(1234);
    printConversion(2850);
    printConversion(3975);
    printConversion(867);
    printConversion(434);
    printConversion(748);
    printConversion(540);
    printConversion(937);
    printConversion(835);
    printConversion(949);
    printConversion(378);
    printConversion(10578);
    printConversion(938);
    printConversion(11953);
    printConversion(15028);
    printConversion(7701);
    printConversion(4900);
    return 0;
}