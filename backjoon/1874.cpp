#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

stack<int> k;
queue<char> q;
int mv;
bool check;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        for(int i=mv+1;i<=x;i++){
            k.push(i);
            q.push('+');
        }
        if(k.top()==x){
            k.pop();
            q.push('-');
        }
        else{
            check = true;
        }
        mv=max(mv, x);
    }
    if(check){
        cout << "NO\n";
    }
    else{
        while(q.size()){
            cout << q.front() << '\n';
            q.pop();
        }
    }
    return 0;
}