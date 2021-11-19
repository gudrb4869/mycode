#include <iostream>
using namespace std;

long long dp[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp[1]=1, dp[2]=1;
    
    for(int i=3; i<101; i++){
        dp[i] = dp[i-3] + dp[i-2];
    }

    int T;
    cin >> T;
    
    while(T--){
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }
    
    return 0;
}