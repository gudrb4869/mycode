#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> abs_heap;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x) abs_heap.push({abs(x),x});
        else{
            if(abs_heap.empty()) cout << 0 << "\n";
            else{
                cout << abs_heap.top().second << '\n';
                abs_heap.pop();
            }
        }
    }
    return 0;
}