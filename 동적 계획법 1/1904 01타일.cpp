#include <iostream>
using namespace std;

int dp[1000001], N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[1]=1;
    dp[2]=2;
    cin >> N;
    for(int i=3; i<=N; i++){
        dp[i]=(dp[i-2]+dp[i-1])%15746;
    }
    cout << dp[N] << '\n';
    return 0;
}