#include <iostream>
#include <queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int cnt=0;
        queue<pair<int,int>> q;
        priority_queue<int> p;
        for(int i=0;i<n;i++){
            int v;
            cin >> v;
            q.push(make_pair(i,v));
            p.push(v);
        }
        while(q.size()){
            int idx=q.front().first;
            int val=q.front().second;
            q.pop();
            if(p.top()==val){
                p.pop();
                cnt++;
                if(idx==m){
                    cout << cnt << '\n';
                    break;
                }
            }
            else{
                q.push(make_pair(idx,val));
            }
        }
    }
    return 0;
}