#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(1){
        stack<int> a;
        string s;
        bool check=true;
        getline(cin, s);
        if(s==".")
            break;
        else{
            for(int i=0;i<s.size();i++){
                if(s[i]=='(' || s[i]=='[') a.push(s[i]);
                else if(s[i]==')' || s[i]==']'){
                    if(a.empty() || (a.top()=='(' && s[i]==']') || (a.top()=='[' && s[i]==')')){
                        check=false;
                        break;
                    }
                    a.pop();
                }
            }
            if(a.empty() && check) cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}