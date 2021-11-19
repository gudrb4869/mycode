#include <iostream>

using namespace std;

int t, n;
int memo[41]{};

int fibonacci(int n){
    if(n==1 || n==0)
    return n;
    else if(n<0)
    return 1;
    else{
        if(memo[n]!=0) return memo[n];
        memo[n]=fibonacci(n-1)+fibonacci(n-2);
        return memo[n];
    }
}

int main(){
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        cout << fibonacci(n-1) << ' ' << fibonacci(n) << '\n';
    }
    return 0;
}