#include <iostream>
using namespace std;

int dp[1001][1001];

int main(){
    int n, k;
    cin >> n >> k;
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=1000;i++){
        dp[i][0]=1;
        for(int j=1;j<i;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%10007;
        }
        dp[i][i]=1;
    }
    cout << dp[n][k] << '\n';
    return 0;
}