#include <iostream>
#include <algorithm>
using namespace std;

const int INF = INT32_MAX;
int N, d[501], M[501][501];

int minimult(int n){
    int diagonal, i, j, k;
    
    for(diagonal=1; diagonal <=n-1; diagonal++){
        for(i=1; i<=n-diagonal; i++){
            j = i + diagonal;
            M[i][j] = INF;
            for(k=i; k<=j-1; k++){
                M[i][j] = min(M[i][j], M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j]);
            }
        }
    }
    
    return M[1][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> d[i] >> d[i+1];
    }
    cout << minimult(N) << '\n';
    return 0;
}