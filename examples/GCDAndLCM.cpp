#include<iostream>

using namespace std;

// the Euclidean algorithm
int gcd (int a, int b) {
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
// recursive version of the Euclidean algorithm
int gcdRecursive (int a, int b) {
    if (a == 0)
        return b;
    return gcdRecursive(b % a,a);
} 

int lcm (int a, int b) {
    if(a == 0 || b == 0) return 0;
    int max = a > b? a: b;
    while (1) {
        if(max % a == 0 && max % b == 0)
            return max;
        max++;
    }
} 

//lcm from gcd
int lcmFromGcd   (int a, int b) {
    if(a == 0 || b == 0) return 0;
    //GCD (a, b) * LCM (a, b) = a * b.
    return (a * b) / gcd(a, b);
} 

void checkAndPrint (int a, int b) {
    int check = gcd(a, b);
    int check2 = gcdRecursive(a, b);
    if(check == check2)
        printf("GCD(%d, %d) = %d\n", a, b, check);
    else
        printf("Error");
    check = lcm(a, b);
    check2 = lcmFromGcd(a, b);
    if(check == check2)
        printf("LCM(%d, %d) = %d\n", a, b, check);
    else
        printf("Error");
}

int main() {
    checkAndPrint(270, 192);
    checkAndPrint(210, 45);
    checkAndPrint(3846, 153);
    checkAndPrint(0, 192);
    checkAndPrint(0, 0);
    checkAndPrint(49, 57);
    checkAndPrint(16, 48);
    checkAndPrint(88, 121);
    checkAndPrint(81, 126);
    checkAndPrint(244, 165);
    checkAndPrint(399, 429);
    return 0;
}