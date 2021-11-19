/*
#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001], dp[10001];
int n;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> wine[i];
    }
    dp[1]=wine[1];
    dp[2]=wine[2]+wine[1];
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+wine[i]);
        dp[i]=max(dp[i],dp[i-3]+wine[i-1]+wine[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10001

int N, Arr[MAX], DP[MAX];

void Input(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> Arr[i];
}

void Solution(){
    DP[1]=Arr[1];
    DP[2]=Arr[1]+Arr[2];
    for(int i=3; i<=N; i++){
        DP[i] = max(DP[i - 3] + Arr[i - 1] + Arr[i], max(DP[i - 2] + Arr[i], DP[i - 1]));
    }
}

void Solve(){
    Input();
    Solution();
    cout << DP[N] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}