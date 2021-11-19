#include <iostream>
#include <queue>
using namespace std;

bool visit[100001];
int check[100001];
queue<int> q;
int n, k;

void bfs(){
    while(!q.empty()){
        int current = q.front();
        q.pop();
        ///////////move_left, move_right, teleport//////////
        int next[3]={current-1,current+1,2*current};
        for(int i=0; i<3; i++){
            if(0<=next[i] && next[i]<=100000){
                if(!visit[next[i]]){
                    check[next[i]] = check[current] + 1;
                    visit[next[i]] = true;
                    q.push(next[i]);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    visit[n]=true;
    q.push(n);
    bfs();
    cout << check[k] << '\n';
    return 0;
}