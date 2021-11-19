#include <iostream>
#include <algorithm>
using namespace std;

int w[1001], dp1[1001], dp2[1001], ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> w[i];
        dp1[i] = 1;
        for(int j=1; j<=i; j++){
            if(w[i] > w[j]){
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for(int i=N; i>=1; i--){
        dp2[i] = 1;
        for(int j=N; j>=i; j--){
            if(w[i] > w[j]){
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    for(int i=1; i<=N; i++){
        ans = max(ans,dp1[i]+dp2[i]);
    }
    cout << ans - 1 << '\n';
    return 0;
}