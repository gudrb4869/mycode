#include <iostream>
using namespace std;

int main(){
    int n, sum=0;
    cin >> n;
    while(n>=5){
        sum+=n/5;
        n/=5;
    }
    cout << sum << '\n';
    return 0;
}