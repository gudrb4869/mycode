#include <iostream>
#include <stack>
using namespace std;

stack<int> a;
int sum=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    while(k--){
        int x;
        cin >> x;
        if(x==0){
            if(!(a.empty())){
                sum-=a.top();
                a.pop();
            }
        }
        else{
            a.push(x);
            sum+=a.top();
        }
    }
    cout << sum << '\n';
    return 0;    
}