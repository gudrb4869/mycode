#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        stack<int> a;
        string s;
        bool check = true;
        cin >> s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') a.push(0);
            else if(s[i]==')'){
                if(a.empty()){
                    check=false;
                    break;
                }
                a.pop();
            }
        }
        if(a.empty() && check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}