#include <iostream>
#include <algorithm>
using namespace std;

int w[100000], dp[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    dp[0]=w[0];
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1] + w[i], w[i]);
    }
    cout << *max_element(dp,dp+n) << '\n';
    return 0;
}