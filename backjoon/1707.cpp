#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 20000+1
#define RED 1
#define BLUE 2

using namespace std;

int K, V, E;
vector<int>graph[MAX_SIZE];
int visited[MAX_SIZE];

void bfs(int start);
bool isBipartiteGraph();

void bfs(int start){
    queue<int> q;
    int color = RED;

    visited[start] = color;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(visited[now] == RED){
            color = BLUE;
        }
        else if(visited[now] == BLUE){
            color = RED;
        }

        int gsize = graph[now].size();
        for(int i=0; i<gsize; i++){
            int next = graph[now][i];
            if(!visited[next]){
                visited[next] = color;
                q.push(next);
            }
        }
    }
}

void dfs(int start){
    if(!visited[start]){
        visited[start] = RED;
    }

    int gsize = graph[start].size();
    for(int i=0; i<gsize; i++){
        int next = graph[start][i];
        if(!visited[next]){
            if(visited[start] == RED){
                visited[next] = BLUE;
            }
            else if(visited[start] == BLUE){
                visited[next] = RED;
            }
            dfs(next);
        }
    }
}

bool isBipartiteGraph(){
    for(int i=1; i<=V; i++){
        int gsize = graph[i].size();
        for(int j=0; j<gsize; j++){
            int next = graph[i][j];
            if(visited[i] == visited[next]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    while(K--){
        cin >> V >> E;
        for(int i=0; i<E; i++){
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(int i=1; i<=V; i++){
            if(!visited[i]){
                bfs(i);
                //dfs(i);
            }
        }

        if(isBipartiteGraph()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

        for(int i=0; i<=V; i++){
            graph[i].clear();
        }

        memset(visited, false, sizeof(visited));
    }
    return 0;
}