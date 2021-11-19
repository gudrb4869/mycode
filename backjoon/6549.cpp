#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(true){
        cin >> n;
        if(n==0) break;
        int *v=new int [n];
        stack<long long> s;
        long long left,right,tmp,answer=0;
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        for(int i=0;i<n;i++){
            right=i;
            while(s.size() && v[s.top()]>v[i]){
                tmp=s.top();
                s.pop();
                if(s.empty())left=0;
                else left=s.top()+1;
                answer=max(answer,v[tmp]*(right-left));
            }
            s.push(i);
        }
        right=n;
        while(s.size()){
            tmp=s.top();
            s.pop();
            if(s.empty()) left=0;
            else left=s.top()+1;
            answer=max(answer,v[tmp]*(right-left));
        }
        cout << answer << '\n';
        free(v);
    }
    return 0;
}