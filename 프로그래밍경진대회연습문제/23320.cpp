#include <iostream>
using namespace std;

int N, X, Y;
int arr[100];
int R;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    cin >> X >> Y;
    for(int i=0; i<N; i++){
        if(arr[i] >= Y) R++;
    }
    cout << int((double)N * (double)X/(double)100) << ' ' << R;
    return 0;
}