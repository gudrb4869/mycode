#include <iostream>
using namespace std;

int N, M;
int vindex[9];

bool promising(int i){
    bool sw = true;
    for(int j=1; j<i; j++){
        if(vindex[j] >= vindex[i]) sw = false;
    }
    return sw;
}

void dfs(int i){
    if(promising(i)){
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
}

int main(){
    cin >> N >> M;
    dfs(0);
    return 0;
}