#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[300][300];
int l, start_i, start_j, end_i, end_j; 

int dx[8]={1, 2, 2, 1, -1, -2, -2, -1};
int dy[8]={2, 1, -1, -2, -2, -1, 1, 2};

void bfs(){
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        if(x==end_j && y==end_i){
            cout << arr[y][x] << '\n';
            return;
        }

        for(int i=0; i<8; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(0<=new_x && new_x<l && 0<=new_y && new_y<l){
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
    int t;
    cin >> t;
    while(t--){
        cin >> l;
        cin >> start_i >> start_j;
        cin >> end_i >> end_j;
        bfs();
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}