#include <iostream>

using namespace std;

long long mem[101];

long long padoban(int n){
    if(n==1 || n==2){
        if(mem[n]) return mem[n];
        mem[n]=1;
        return mem[n];
    }
    else if(n==0) return mem[n];
    else{
        if(mem[n]) return mem[n];
        mem[n]=padoban(n-2)+padoban(n-3);
        return mem[n];
    }
}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << padoban(n) << '\n';
    }
    return 0;
}