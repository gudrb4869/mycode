#include <iostream>
#include <string>
#include <queue>
using namespace std;

string arr[1000];
int visit[1000][1000][2];
int n, m;
//////////상, 하, 좌, 우////////////
int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};

void bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visit[0][0][1] = true;
    while(!q.empty()){
        int x = q.front().first.second;
        int y = q.front().first.first;
        int block = q.front().second;
        q.pop();

        if(x==m-1 && y==n-1){
            cout << visit[y][x][block] << '\n';
            return;
        }
        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(0<=new_x && new_x<m && 0<=new_y && new_y<n){
                if(arr[new_y][new_x]=='1' && block){
                    visit[new_y][new_x][block-1] = visit[y][x][block] + 1;
                    q.push({{new_y, new_x}, block-1});
                }
                if(arr[new_y][new_x]=='0' && visit[new_y][new_x][block]==0){
                    visit[new_y][new_x][block] = visit[y][x][block] + 1;
                    q.push({{new_y, new_x}, block});
                }
            }
        } 
    }
    cout << "-1\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    bfs();
    return 0;
}