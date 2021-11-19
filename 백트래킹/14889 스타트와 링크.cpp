#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Result = 9999, N, S[20][20];
vector<int> Start, Link;

void DFS(int n){
    if(n == N){
        if(Start.size() == N/2 && Link.size() == N/2){
            int start = 0;
            int link = 0;

            for(int i=0; i<N/2; i++){
                for(int j=i+1; j<N/2; j++){
                    if(i == j) continue;

                    start += S[Start[i]][Start[j]] + S[Start[j]][Start[i]];
                    link += S[Link[i]][Link[j]] + S[Link[j]][Link[i]];
                }
            }
            Result = min(Result, abs(start - link));
        }
        return;
    }

    Start.push_back(n);
    DFS(n+1);
    Start.pop_back();

    Link.push_back(n);
    DFS(n+1);
    Link.pop_back();
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> S[i][j];
        }
    }
    DFS(0);
    cout << Result << '\n';
    return 0;
}