#include <iostream>
using namespace std;

long long mem[1000001];

long long fibo(long long n){
    if(n==1) return 1;
    else if(n==2) return 2;
    else{
        if(mem[n]) return mem[n];
        mem[n]=(fibo(n-1)%15746+fibo(n-2)%15746)%15746;
        return mem[n];
    }
}

int main(){
    long long n;
    cin >> n;
    cout << fibo(n) << '\n';
    return 0;
}