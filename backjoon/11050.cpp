#include <iostream>
using namespace std;

int BC(int n, int k){
    int result = 1;
    for(int i=n;i>n-k;i--){
        result*=i;
    }
    for(int i=k;i>0;i--){
        result/=i;
    }
    return result;
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << BC(n, k) << '\n';
    return 0;
}