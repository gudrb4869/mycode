#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[2001];
int cnt, sum;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=N; i++){
        if(arr[i] > arr[1]){
            sum += arr[i]-arr[1];
            cnt++;
        }
    }
    cout << sum << ' ' << cnt;
    return 0;
}