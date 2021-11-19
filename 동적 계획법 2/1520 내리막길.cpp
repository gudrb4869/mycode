#include <iostream>
using namespace std;

int M, N, map[501][501], dp[501][501];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};//상 하 좌 우

int dfs(int r, int c){
    if(r < 1 || c < 1 || r > M || c > N) return 0;
    if(r == M && c == N) return 1;
    if(dp[r][c] != -1) return dp[r][c];
    
    dp[r][c] = 0;    
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(map[nr][nc] < map[r][c]){
            dp[r][c] += dfs(nr, nc);
        }
    }
    return dp[r][c];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(1, 1);
    return 0;
}