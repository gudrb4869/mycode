#include <iostream>
#include <algorithm>
using namespace std;

long long zerocount(int a, int b){
    int num = 0;
    for(long long i = b; i <= a; i*= b){
        num += a/i;
    }
    return num;
}

int main(){
    int n, m;
    cin >> n >> m;
    long long five, two;
    five = zerocount(n, 5) - zerocount(m, 5) - zerocount(n-m, 5);
    two = zerocount(n, 2) - zerocount(m, 2) - zerocount(n-m, 2);
    cout << min(five, two) << '\n';
    return 0;
}