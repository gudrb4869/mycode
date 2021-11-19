#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main(){
    int N, K, W, V;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> W >> V;
        for(int j = K; j >= W; j--){
            dp[j] = max(dp[j], dp[j - W] + V);
        }
    }
    cout << dp[K] << '\n';
    return 0;
}