#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, dp[501][501];
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> dp[i][j];
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    cout << *max_element(&dp[n][1],&dp[n][n]+1) << '\n';
    return 0;
}