#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x, y;
    vector<pair<int, int>> wire;
    cin >> n;
    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        wire.push_back(make_pair(x, y));
    }
    
    sort(wire.begin(), wire.end());
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(wire[i].second > wire[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = -1;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i]);
    }
    cout << n - ans << '\n';
    return 0;
}