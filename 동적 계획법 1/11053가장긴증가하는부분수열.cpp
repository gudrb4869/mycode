// dynamic programming O(N^2)
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001], arr[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        if(dp[i] == 0) dp[i] = 1;
        for(int j=1; j<=i; j++){
            if(arr[i] > arr[j]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    cout << *max_element(dp, dp+1001) << '\n';
    return 0;
}

/* O(nlogn) n>=100000일 경우
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

vector<int> v;
int ans, N, x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    v.push_back(-INF);
    for(int i=0; i<N; i++){
        cin >> x;
        if(v.back() < x){
            v.push_back(x);
            ans++;
        }
        else{
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    cout << ans << '\n';
    return 0;
}
*/