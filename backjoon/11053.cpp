/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> dp(n,1);
    dp[0]=1;
    for(int j=1;j<n;j++){
        for(int i=0;i<j;i++){
            if(arr[i]<arr[j]){
                dp[j]=max(dp[j],dp[i]+1);
            }
        }
    }
    cout << *max_element(dp.begin(),dp.end()) << '\n';
    return 0;
}
*/

#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N, Arr[MAX], DP[MAX];

void Input(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> Arr[i];
}

void Solution(){
    int Answer = 0;
    for(int i=1; i<=N; i++){
        DP[i] = 1;
        for(int j=i-1; j>=1; j--){
            if(Arr[i] > Arr[j]){
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        Answer = max(DP[i], Answer);
    }
    cout << Answer << '\n';
}

void Solve(){
    Input();
    Solution();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}