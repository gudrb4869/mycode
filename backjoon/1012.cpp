#include <iostream>
#include <cstring>
using namespace std;

int cnt, t, m, n, k;
bool field[50][50], visit[50][50];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

void dfs(int x, int y){
    visit[x][y]=true;
    for(int i=0; i<4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(0<=new_x && new_x<m && 0<=new_y && new_y<n)
            if(field[new_x][new_y] && !visit[new_x][new_y])
                dfs(new_x, new_y);
    }
}

void solve(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(field[i][j] && !visit[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << '\n';
}

void init(){
    cnt = 0;
    memset(field, false, sizeof(field));
    memset(visit, false, sizeof(visit));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        init();
        cin >> m >> n >> k;
        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            field[x][y] = true;
        }
        solve();
    }
    return 0;
}