#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, X;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> X;
    
    if(26*N < X || N > X){
        cout << "!";
        return 0;
    }
    string answer;
    for(int i = 0; i < N; i++){
        answer += "A";
    }
    X -= N;
    for(int i = N - 1; i >= 0 && X > 0; i--){
        int temp = min(X, 25);
        answer[i] += temp;
        X -= temp;
    }
    cout << answer << '\n';
    return 0;
}