#include <iostream>
#include <algorithm>
using namespace std;

int w[10001], dp[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    dp[1]=w[1];
    dp[2]=w[1]+w[2];
    for(int i=3; i<=n; i++){
        dp[i] = max(dp[i-1], max(dp[i-3]+w[i-1]+w[i], dp[i-2]+w[i]));
    }
    cout << dp[n] << '\n';
    return 0;
}