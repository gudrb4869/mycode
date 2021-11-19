#include <iostream>
#include <algorithm>
using namespace std;

int N, P[1000], sum;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> P[i];
    }
    sort(P, P+N);
    sum = P[0];
    for(int i=1; i<N; i++){
        P[i] += P[i-1];
        sum += P[i];
    }
    cout << sum << '\n';
    return 0;
}