#include <iostream>
using namespace std;

int N, M;
int number[2001];
bool dp[2001][2001];

void solve(int n){
    int i, j, diagonal;

    for(diagonal=0; diagonal<=n-1; diagonal++){
        for(i=1; i<=n-diagonal; i++){
            if(diagonal == 0){
                dp[i][i] = 1;
            }
            else{
                j = i + diagonal;
                if(dp[i+1][j-1] == 1 || diagonal == 1){
                    dp[i][j] = (number[i] == number[j]);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> number[i];
    }
    
    solve(N);
    
    cin >> M;
    for(int i=0; i<M; i++){
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }
    
    return 0;
}