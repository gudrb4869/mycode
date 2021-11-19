#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> s;
int n, q;
int idx = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    
    for(int i=1; i<=n; i++){
        int t;
        cin >> t;
        if(t == 1) s.insert(i);
    }

    while(q--){
        int num;
        cin >> num;
        if(num == 1){
            int i;
            cin >> i;
            if(s.find(i) != s.end()) s.erase(i);
            else s.insert(i);
        }
        else if(num == 2){
            int x;
            cin >> x;
            idx = ((idx - 1) + (x % n)) % n + 1;
        }
        else if(num == 3){
            if(s.empty()) cout << "-1\n";
            else{
                set<int>::iterator it = s.lower_bound(idx);
                if(*it >= idx && s.find(*it) != s.end()){
                    cout << *it - idx << '\n';
                }
                else{
                    it = s.lower_bound(1);
                    cout << n - idx + *it << '\n';
                }
            }
        }
    }
    return 0;
}