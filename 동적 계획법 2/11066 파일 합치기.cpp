#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
int K, arr[501], cache[501][501], presum[501];

int dp(int a, int b){
    if(a == b)
        return arr[a];
            
    int& ret = cache[a][b];
    if(ret != -1){
        return ret;
    }

    ret = INF;

    int sum = presum[b + 1] - presum[a];
    for(int i = a; i < b; i++){
        ret = min(ret, dp(a, i) + dp(i + 1, b) + sum);
    }

    return ret;
}

void solve(int n){
    int ret = INF;

    for(int i = 0; i < n - 1; i++){
        ret = min(ret, dp(0, i) + dp(i + 1, n - 1));
    }
    cout << ret << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--){
        memset(cache, -1, sizeof(cache));
        int K;
        cin >> K;
        
        for(int i = 0; i < K; i++){
            cin >> arr[i];
        }

        for(int i = 1; i <= K; i++){
            presum[i] = presum[i - 1] + arr[i - 1];
        }

        solve(K);
    }
    return 0;
}