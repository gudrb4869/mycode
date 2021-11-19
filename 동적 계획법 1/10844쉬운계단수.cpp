#include <iostream>
using namespace std;

long long int dp[101][11];
long long int sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=1; i<=9; i++){
        dp[1][i]=1;
    }
    for(int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][1] % 1000000000;
        for(int j=1; j<=9; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }
    for(int i=0; i<=9; i++){
        sum += dp[N][i];
    }
    cout << sum % 1000000000 << '\n';
    return 0;
}