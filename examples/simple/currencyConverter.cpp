#include<iostream>
#include <map>

using namespace std;

const map<string, float> currency_usd_equivalent = {{"USD", 1.0}, 
            {"EUR", 1.01},
            {"GBP", 0.92196},
            {"INR", 81.71646},
            {"AUD", 1.54358},
            {"CAD", 1.36967},
            {"ZAR", 17.97507},
            {"NZD", 1.75562},
            {"JPY", 144.71461},
            {"SGD", 1.43839},
            {"CNY", 7.13198},
            {"CHF", 0.98269},
            {"MYR", 4.63548},
            {"HUF", 434.71049},
            {"HKD", 7.84999},
            {"AED", 3.64445},
            {"THB", 38.06511},
            {"KRW", 1430.39357},
            {"SEK", 11.28992},
            {"PHP", 58.58232}};

void printCurrencyList () {
    cout << "   USD (United States Dollars)" << endl;
    cout << "   EUR (Euro)" << endl;
    cout << "   GBP (United Kingdom Pounds)" << endl;
    cout << "   INR (India Rupees)" << endl;
    cout << "   AUD (Australia Dollars)" << endl;
    cout << "   CAD (Canada Dollars)" << endl;
    cout << "   ZAR (South Africa Rand)" << endl;
    cout << "   NZD (New Zealand Dollars)" << endl;
    cout << "   JPY (Japan Yen)" << endl;
    cout << "   SGD (Singapore Dollars)" << endl;
    cout << "   CNY (China Yuan Renminbin)" << endl;
    cout << "   CHF (Switzerland Francs)" << endl;
    cout << "   MYR (Malaysia Ringgiys)" << endl;
    cout << "   HUF (Hungary Forint)" << endl;
    cout << "   HKD (Hong Kong Dollars)" << endl;
    cout << "   AED (United Arab Emirates Dirhams)" << endl;
    cout << "   THB (Thailand Baht)" << endl;
    cout << "   KRW (Korea Won)" << endl;
    cout << "   SEK (Sweden Kronor)" << endl;
    cout << "   PHP (Philippines Pesos)" << endl;
}

int main() {
    float currency;
    string from;
    string to;
    const double BP = 1.487, FRNC = 0.172;
    float dollar;  
    float bp = ( 1 / BP );  
    float frnc = ( 1 / FRNC );  
    float deutschmark = ( 1 / 0.584 );  
    float yen = ( 1 / 0.00955 );  
    float ind = ( 1 / 0.013 );  
    cout << "Convert from:\n"<<endl;  
    printCurrencyList();
    cin >> from;
    auto from_usd_equivalent = currency_usd_equivalent.find(from);  
    while (from_usd_equivalent == currency_usd_equivalent.end()){
        cout << from <<" not found\n";  
        cin >> from;
        from_usd_equivalent = currency_usd_equivalent.find(from);  
    }

    cout << "Enter currency:\n"<<endl; 
    cin >> currency;
    
    cout << "Convert to:\n"<<endl;
    printCurrencyList();
    cin >> to;
    auto to_usd_equivalent = currency_usd_equivalent.find(to);  
    while (to_usd_equivalent == currency_usd_equivalent.end()){
        cout << to <<" not found\n";  
        cin >> to;
        to_usd_equivalent = currency_usd_equivalent.find(to);  
    }

    cout << currency << " (" << from << ") --> " 
            << (1/from_usd_equivalent->second)*to_usd_equivalent->second 
            << " (" << to << ")" <<endl;

    return 0;
}