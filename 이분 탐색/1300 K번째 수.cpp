#include <iostream>
using namespace std;

int N, k;

int binary_search(int low, int high){
    if(low > high) return low;
    int mid = (low + high) / 2, cnt = 0;
    for(int i = 1; i <= N; ++i){
        if(N > mid/i) cnt += mid/i;
        else cnt += N;
    }
    if(cnt < k) return binary_search(mid + 1, high);
    else return binary_search(low, mid - 1);
}

int main(){
    cin >> N >> k;
    cout << binary_search(1, k) << '\n';
    return 0;
}