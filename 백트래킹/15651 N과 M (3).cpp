#include <iostream>
using namespace std;

int N, M;
int vindex[9];

void dfs(int i){
    if(i==M){
        for(int j=1; j<=M; j++){
            cout << vindex[j] << ' ';
        }
        cout << '\n';
    }
    else{
        for(int j=1; j<=N; j++){
            vindex[i+1] = j;
            dfs(i+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    dfs(0);
    return 0;
}