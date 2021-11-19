#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[100][100][100];
int m, n, h, result;
queue<pair<pair<int, int>, int>> q;
////////////위,아래,왼,오,앞,뒤////////
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

void bfs(){
    while(!q.empty()){
        int x = q.front().first.second;
        int y = q.front().second;
        int z = q.front().first.first;
        q.pop();
        
        for(int i=0; i<6; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            int new_z = z + dz[i];

            if(0<=new_x && new_x<n && 0<=new_y && new_y<m && 0<=new_z && new_z<h){
                if(arr[new_z][new_x][new_y]==0){
                    arr[new_z][new_x][new_y] = arr[z][x][y] + 1;
                    q.push({{new_z, new_x}, new_y});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> h;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k]==1){
                    q.push({{i, j}, k});
                }
            }
        }
    }

    bfs();

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(arr[i][j][k]==0){
                    cout << "-1\n";
                    return 0;
                }
                result = max(result, arr[i][j][k]);
            }
        }
    }
    cout << result-1 << '\n';
    return 0;
}