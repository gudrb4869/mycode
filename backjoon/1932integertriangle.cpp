#include <iostream>
using namespace std;

int n, triangle[500][500], dp[501][501];

int max(int x, int y){
    return x > y ? x : y;
}

int func(int x = 0, int y = 0){ 
    if(dp[x][y]) return dp[x][y];
    if(x == n) return 0;

    dp[x][y] = triangle[x][y] + max(func(x + 1, y), func(x + 1, y + 1));
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> triangle[i][j];
        }
    }
    cout << func() << '\n';
    return 0;
}