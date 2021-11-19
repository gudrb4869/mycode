#include <iostream>
using namespace std;

int N, sum, x, tmp;

int main(){
    cin >> N;
    sum += 2*N;
    for(int i=0; i<=N; i++){
        cin >> x;
        if(i==0) continue;
        tmp = 0;
        while(x){
            x /= 10;
            tmp++;
        }
        if(tmp) sum += tmp + 1;
    }
    cout << sum;
    return 0;
}