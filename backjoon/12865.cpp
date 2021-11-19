#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int n,k,w,v;
int main(){
    cin >> n >> k;
    while(n--){
        cin >> w >> v;
        for(int i = k; i >= w; i--){
            arr[i] = max(arr[i], arr[i - w] + v);
        }
    }
    cout << arr[k] << '\n';
    return 0;
}

/*int dp[101][100001];
int a[101][2];

int main(void){
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j >= a[i][0]) dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - a[i][0]]) + a[i][1]);
            else dp[i][j] = dp [i - 1][j];
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}*/