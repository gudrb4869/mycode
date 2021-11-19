#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pair<int,int>> w;
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        w.push_back({x,y});
    }
    
    sort(w.begin(),w.end());
    vector<int> dp(n,1);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(w[i].second > w[j].second){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }
    cout << n - ans << '\n';
    return 0;
}