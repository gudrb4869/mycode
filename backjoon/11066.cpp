/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[501][501];
int cost[501];
int sum[501];

int dpf(int tx, int ty){
    if(dp[tx][ty] != 0x3f3f3f3f)
        return dp[tx][ty];
    
    if(tx == ty)
        return dp[tx][ty]=0;
    if(tx+1 == ty)
        return dp[tx][ty] = cost[tx] + cost[ty];

    for(int mid = tx; mid < ty; mid++){
        int left = dpf(tx, mid);
        int right = dpf(mid + 1, ty);
        dp[tx][ty] = min(dp[tx][ty], left + right);
    }

    return dp[tx][ty] += sum[ty] - sum[tx - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        memset(dp, 0x3f, sizeof(dp));
        int k;
        cin >> k;
        for(int i=1; i<=k; i++){
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
        }
        cout << dpf(1,k) << '\n';
    }
    return 0;
}
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 501
#define INF 1000000007

int Cost[MAX];
int Sum[MAX];
int DP[MAX][MAX];
int T, K;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> K;
        for(int i=1; i<=K; i++){
            cin >> Cost[i];
            Sum[i] = Sum[i-1] + Cost[i];
        }
        for(int d=1; d<K; d++){
            for(int tx=1; tx+d<=K; tx++){
                int ty = tx + d;
                DP[tx][ty] = INF;

                for(int mid=tx; mid<ty; mid++){
                    DP[tx][ty] = 
                    min(DP[tx][ty], DP[tx][mid] + DP[mid + 1][ty] + Sum[ty] - Sum[tx - 1]);
                }
            }
        }
        cout << DP[1][K] << '\n';
    }
    
    return 0;
}
