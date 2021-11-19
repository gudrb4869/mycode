#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
bool Map[25][25];
bool visited[25][25];
vector<int> ans;

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

void Get_Input(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d",&Map[i][j]);
        }
    }
}

void DFS(int x, int y){
    visited[x][y]=true;
    cnt++;
    for(int i=0; i<4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(0<=new_x && new_x<n && 0<=new_y && new_y<n)
            if(Map[new_x][new_y] && !visited[new_x][new_y])
                DFS(new_x, new_y);
    }
}

void Solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(Map[i][j] && !visited[i][j]){
                cnt = 0;
                DFS(i, j);
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());

    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++)
        printf("%d\n",ans[i]);
}

int main(){
    Get_Input();
    Solve();
    return 0;
}