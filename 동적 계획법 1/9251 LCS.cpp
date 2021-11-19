#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
string x, y;
int lx, ly;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x;
    cin >> y;
    lx = x.length();
    ly = y.length();

    for(int i=1; i<=lx; i++){
        for(int j=1; j<=ly; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[lx][ly] << '\n';
    return 0;
}