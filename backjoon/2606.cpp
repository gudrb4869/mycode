#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 101;

int cnt;
bool check[MAX];
int adj_matrix[MAX][MAX];
queue<int> q;
vector<int> adj_list[MAX];

void dfs(int start){
    check[start] = true;
    cnt++;

    for(auto i=0; i<adj_list[start].size(); i++){
        int next = adj_list[start][i];
        if(check[next]) continue;
        dfs(next);
    }
}

void bfs(int start){
    memset(check, false, sizeof(check));
    cnt=0;
    check[start] = true;
    q.push(start);

    while(q.size()){
        int current = q.front();
        cnt++;
        q.pop();
        
        for(auto i=0; i<adj_list[current].size(); i++){
            int next = adj_list[current][i];
            if(!check[next]){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        sort(adj_list[i].begin(), adj_list[i].end());
    }
    dfs(1);
    cout << cnt-1 << '\n';
    bfs(1);
    cout << cnt-1 << '\n';
    return 0;
}