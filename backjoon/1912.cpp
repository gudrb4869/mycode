#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] + dp[i - 1] > arr[i]) dp[i] = arr[i] + dp[i - 1];
        else dp[i] = arr[i];
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}