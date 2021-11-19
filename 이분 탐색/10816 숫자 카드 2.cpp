#include <iostream>
#include <algorithm>
using namespace std;

int N, M, X, A[500000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> X;
        cout << upper_bound(A, A+N, X)-lower_bound(A, A+N, X) << ' ';
    }
    return 0;
}