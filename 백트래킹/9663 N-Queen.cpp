#include <iostream>
#include <cstdlib>
using namespace std;

int N, Total;
int col[15];

bool promising(int i){
    int k = 1;
    bool sw = true;
    while(k<i && sw){
        if(col[i] == col[k] || abs(col[i] - col[k]) == i-k){
            sw = false;
        }
        k++;
    }
    return sw;
}

void N_Queen(int i){
    if(promising(i)){
        if(i == N){
            Total++;
        }
        else{
            for(int j=1; j<=N; j++){
                col[i+1] = j;
                N_Queen(i+1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    N_Queen(0);
    cout << Total << '\n';
    return 0;
}