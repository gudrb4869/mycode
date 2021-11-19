#include <iostream>
#include <queue>
using namespace std;

int N, M, T;
int arr[101][101];
bool visit[101][101][2];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

struct coor{
    int r;
    int c;
    int t;
    bool w;
};

void bfs(){
    visit[1][1][0] = true;
    queue<coor> q;
    q.push({1, 1, 0, false});

    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int time = q.front().t;
        bool weapon = q.front().w;
        q.pop();
        
        if(time > T){
            cout << "Fail\n";
            return;
        }
        if(r == N && c == M){
            cout << time << '\n';
            return;
        }

        for(int k = 0; k < 4; ++k){
            int nr = r + dr[k];
            int nc = c + dc[k];
            int nt = time + 1;
            if(nr>=1 && nr<=N && nc>=1 && nc<=M){
                if(weapon){
                    if(!visit[nr][nc][1]){
                        visit[nr][nc][1] = true;
                        q.push({nr, nc, nt, true});
                    }
                }
                else{
                    if(arr[nr][nc] == 0 && !visit[nr][nc][0]){
                        visit[nr][nc][0] = true;
                        q.push({nr, nc, nt, false});
                    }
                    else if(arr[nr][nc] == 2 && !visit[nr][nc][0]){
                        visit[nr][nc][0] = true;
                        q.push({nr, nc, nt, true});
                    }
                }
            }
        }   
    }
    cout << "Fail\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> T;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> arr[i][j];
        }
    }
    bfs();
    return 0;
}