#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s=="push"){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(s=="pop"){
            if(st.empty()) cout << "-1\n";
            else{
                cout << st.top() << '\n';
                st.pop();
            }            
        }
        else if(s=="top"){
            if(st.empty()) cout << "-1\n";
            else cout << st.top() << '\n';
        }
        else if(s=="empty"){
            cout << st.empty() << '\n';
        }
        else if(s=="size"){
            cout << st.size() <<'\n'; 
        }
    }
    return 0;
}