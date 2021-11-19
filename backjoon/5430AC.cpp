#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        bool check=false, r=false;
        deque<int> dq;
        string f,arr;
        cin >> f;
        cin >> n;
        while(true){
            char c;
            cin >> c;
            if(c=='[') continue;
            else if(c==']'){
                if(arr.size()){
                dq.push_back(stoi(arr));
                arr.clear();
                }
                break;
            }
            else if(c==','){
                dq.push_back(stoi(arr));
                arr.clear();
            }
            else{
                arr+=c;
            }
        }
        for(int i=0;i<f.size();i++){
            if(f[i]=='R') r=!r;
            else if(f[i]=='D'){
                if(dq.empty()){
                    check=true;
                    break;
                }
                if(r) dq.pop_back();
                else dq.pop_front();
            }
        }
        if(check) cout << "error\n";
        else{
            cout << "[";
            while(dq.size()){
                if(r){
                    cout << dq.back();
                    dq.pop_back();
                    if(dq.size()) cout << ",";
                }
                else{
                    cout << dq.front();
                    dq.pop_front();
                    if(dq.size()) cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}