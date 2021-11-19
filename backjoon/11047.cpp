#include <iostream>
using namespace std;

int arr[11];

int main(void){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    int temp = k;
    while(temp){
        cnt += temp / arr[n];
        temp %= arr[n];
        n--;
    }
    cout << cnt << '\n';
    return 0;
}