#include <iostream>
#include <algorithm>
using namespace std;

int K, N, A[10000];
long long Result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> K >> N;
    for(int i=0; i<K; i++){
        cin >> A[i];
    }
    sort(A, A+K);

    long long Low = 1, High = A[K-1];
    while(High >= Low){
        int Count = 0;
        long long Mid = (Low + High) / 2;

        for(int i=0; i<K; i++){
            Count += A[i] / Mid;
        }

        if(Count >= N){
            Result = max(Result, Mid);
            Low = Mid + 1;
        }
        else{
            High = Mid -1;
        }
    }
    cout << Result << '\n';
    return 0;
}