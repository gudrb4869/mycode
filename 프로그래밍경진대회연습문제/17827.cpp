#include <iostream>
using namespace std;

int arr[200000];
int N, M, V, K;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> V;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int head = V - 1;
    int len = N - head;
    while(M--){
        cin >> K;
        if(K < head) cout << arr[K] << '\n';
        else cout << arr[(K - head) % len + head] << '\n';
    }
    return 0;
}