#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

string arr[100];
int check[100][100];
bool visit[100][100];
int n, m;
pair<int, int> d[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int i, int j){
    visit[i][j]=true;

    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while(q.size()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int k=0; k<4; k++){
            int new_x = x + d[k].first;
            int new_y = y + d[k].second;

            if(0<=new_x && new_x<m && 0<=new_y && new_y<n){
                if(arr[new_y][new_x]=='1' && !visit[new_y][new_x] && check[new_y][new_x]==0){
                    check[new_y][new_x] = check[y][x] + 1;
                    visit[new_y][new_x] = true;
                    q.push(make_pair(new_y, new_x));
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    bfs(0, 0);
    cout << check[n-1][m-1]+1 << '\n';
    return 0;
}