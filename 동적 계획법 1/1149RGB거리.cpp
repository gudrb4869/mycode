#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3], N;

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
        for(int j=0; j<3; j++){
            dp[i][j] += min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
        }
    }
    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
    return 0;
}