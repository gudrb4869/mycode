#include <iostream>
#include <algorithm>
#include <string>
#define INF 2147483647
using namespace std;

string s = "+";
int n;
int dp[200001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string t;
    cin >> t;
    n = t.size();
    s += t;
    
    dp[0] = -INF;
    
    if(s[1] == '+') dp[1] = 10;
    else dp[1] = 1;
    
    if(s[1] == '+' && s[2] == '-') dp[2] = 11;
    else dp[2] = -INF;

    for(int i = 3; i <= n; i++){
        dp[i] = -INF;
        if(dp[i - 3] != -INF){
            if(s.substr(i - 2, 3) == "++-")
                dp[i] = max(dp[i], dp[i - 3] + 11);
            else if(s.substr(i - 2, 3) == "-+-")
                dp[i] = max(dp[i], dp[i - 3] - 11);
        }

        if(dp[i - 2] != -INF){
            if(s.substr(i - 1, 2) == "++")
                dp[i] = max(dp[i], dp[i - 2] + 10);
            else if(s.substr(i - 1, 2) == "-+")
                dp[i] = max(dp[i], dp[i - 2] - 10);
            else if(s.substr(i - 1, 2) == "+-")
                dp[i] = max(dp[i], dp[i - 2] + 1);
            else if(s.substr(i - 1, 2) == "--")
                dp[i] = max(dp[i], dp[i - 2] - 1);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}