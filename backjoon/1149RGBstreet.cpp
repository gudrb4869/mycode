#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int n, cost[1000][3], dp[1001][4];

int rgb(int pos, int prev=3){
    int& ret = dp[pos][prev];
    if(ret != -1) return ret;
    if(pos==n) return ret = 0;

    ret=INF;
    for(int i=0; i<3; i++)
        if(prev != i) ret = min(ret, rgb(pos+1, i) + cost[pos][i]);
    return ret;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    memset(dp, -1, sizeof(dp));
    cout << rgb(0) << '\n';
    return 0;
}