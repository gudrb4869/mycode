#include <iostream>
#include <algorithm>
using namespace std;

int N, A[11], Op[4];
int Max = -1000000001;
int Min = 1000000001;

void DFS(int n, int result){
    if(n == N){
        Max = max(Max, result);
        Min = min(Min, result);
    }
    else{
        for(int i=0; i<4; i++){
            if(Op[i]){
                Op[i]--;
                if(i == 0) DFS(n + 1, result + A[n]);
                else if(i == 1) DFS(n + 1, result - A[n]);
                else if(i == 2) DFS(n + 1, result * A[n]);
                else if(i == 3) DFS(n + 1, result / A[n]);
                Op[i]++;
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<4; i++){
        cin >> Op[i];
    }
    DFS(1, A[0]);
    cout << Max << '\n' << Min << '\n';
    return 0;
}