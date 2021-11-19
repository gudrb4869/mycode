#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 801
#define INF 987654321
using namespace std;

int N, E, v1, v2, Answer;
vector<pair<int, int>> Vertex[MAX];
int Dist[MAX];

void Input(){
    cin >> N >> E;
    for(int i=0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Vertex[a].push_back(make_pair(b, c));
        Vertex[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;
}

void Dijkstra(int Start){
    priority_queue<pair<int, int>> PQ;
    Dist[Start] = 0;
    PQ.push(make_pair(0, Start));
    
    while(!PQ.empty()){
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for(int i=0; i<Vertex[Cur].size(); i++){
            int Next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;

            if(Dist[Next] > Cost + nCost){
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
}

void Solution(){
    bool Flag1, Flag2;
    Flag1 = Flag2 = true;

    for(int i=1; i<=N; i++) Dist[i] = INF;
    Dijkstra(1);
    int Route1 = Dist[v1];
    int Route2 = Dist[v2];
    if(Route1 == INF) Flag1 = false;
    if(Route2 == INF) Flag2 = false;

    for(int i=1; i<=N; i++) Dist[i] = INF;
    Dijkstra(v1);
    if(Flag1 == true) Route1 += Dist[v2];
    if(Flag2 == true) Route2 += Dist[v2];

    for(int i=1; i<=N; i++) Dist[i] = INF;
    Dijkstra(v2);
    if(Flag1 == true) Route1 += Dist[N];

    for(int i=1; i<=N; i++) Dist[i] = INF;
    Dijkstra(v1);
    if(Flag2 == true) Route2 += Dist[N];

    if(Flag1 == false && Flag2 == false) Answer = -1;
    else{
        Answer = min(Route1, Route2);
    }
    if(Answer == INF) Answer = -1;
}

void Solve(){
    Input();
    Solution();

    cout << Answer << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}