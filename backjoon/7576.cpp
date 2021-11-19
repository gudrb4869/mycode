#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[1000][1000];
int result, m, n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

void bfs(){
    while(q.size()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(0<=new_x && new_x<m && 0<=new_y && new_y<n){
                if(arr[new_y][new_x]==0){
                    arr[new_y][new_x] = arr[y][x] + 1;
                    q.push({new_y, new_x});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                q.push({i, j});
            }
        }
    }

    bfs();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==0){
                cout << "-1\n";
                return 0;
            }
            result = max(result, arr[i][j]);
        }
    }
    cout << result-1 << '\n';
    return 0;
}