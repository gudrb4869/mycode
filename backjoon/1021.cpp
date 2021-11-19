#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> dq;
    int n,m, result=0;
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }
    for(int i=0;i<m;i++){
        int v, left=0, right=1, idx=0;
        cin >> v;
        while(dq[idx++]!=v) left++;
        idx=dq.size()-1;
        while(dq[idx--]!=v) right++;

        if(left<right){
            result+=left;
            while(left--){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            result+=right;
            while(right--){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        dq.pop_front();
    }
    cout << result << '\n';
    return 0;
}