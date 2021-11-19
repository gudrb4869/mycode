#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

bool visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void dfs(int start){
    visited[start] = true;
    for(int i=0; i<tree[start].size(); i++){
        int next = tree[start][i];
        if(!visited[next]){
            parent[next] = start;
            dfs(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1);
    for(int i=2; i<=N; i++){
        cout << parent[i] << '\n';
    }
    return 0;
}