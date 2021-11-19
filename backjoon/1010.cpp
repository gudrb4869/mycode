#include <iostream>
using namespace std;

int dp[30][30];

int main(){
    dp[0][0]=1;
    for(int i=1;i<30;i++){
        dp[i][0]=1;
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }

    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
    return 0;
}