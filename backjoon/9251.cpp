/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int dp[1001][1001];

int main(void){    
    getline(cin, str1);
    getline(cin, str2);
    
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    cout << dp[str1.size()][str2.size()] << '\n';
    return 0;
}
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;
int DP[1001][1001];

void Input(){
    cin >> A >> B;
}

void Solution(){
    int A_Size = A.size();
    int B_Size = B.size();

    for(int i=1; i<=A_Size; i++){
        for(int j=1; j<=B_Size; j++){
            if(A[i - 1] == B[j - 1]){
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else{
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[A_Size][B_Size] << '\n';
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