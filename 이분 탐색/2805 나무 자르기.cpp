#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long long Result, A[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    long long Low = 0, High = A[N-1];
    while(High>=Low){
        long long Sum = 0;
        long long Mid = (Low + High) / 2;
        for(int i=0; i<N; i++){
            if(A[i] > Mid)
                Sum += A[i] - Mid;
        }
        if(Sum >= M){
            Result = max(Result, Mid);
            Low = Mid + 1;
        }
        else{
            High = Mid - 1;
        }
    }
    cout << Result << '\n';
    return 0;
}