#include <iostream>
using namespace std;

int gcd(int a, int b){
    int tmp, n;
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b != 0){
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(void){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
    cout << lcm(a, b) << '\n';          
    return 0;
}