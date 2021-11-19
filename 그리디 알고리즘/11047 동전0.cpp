#include <iostream>
using namespace std;

int main(){
    int N, K, w[10];
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> w[i];
    }
    int x = N - 1;
    int ans = 0;
    while(K){
        ans += K / w[x];
        K %= w[x];
        x--;
    }
    cout << ans << '\n';
    return 0;
}