#include <iostream>
using namespace std;

int n, m, sum, bead;
int weight[31];
bool dp[31][55001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> weight[i];
        dp[i][weight[i]] = 1;
        sum += weight[i];
        for(int j=1; j<=sum; j++){
            if(dp[i-1][j]){
                dp[i][j] = 1;
                dp[i][j+weight[i]] = 1;
                dp[i][abs(j-weight[i])]=1;
            }
        }
    }
    
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> bead;
        if(bead > sum || bead <= 0){
            cout << "N ";
            continue;
        }
        
        if(dp[n][bead]) cout << "Y ";
        else cout << "N ";
        
    }
    return 0;
}