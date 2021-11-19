#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int arr[1000000];
int nge[1000000];
int main(){
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        while(s.size() && arr[s.top()]<arr[i]){
            nge[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    for(int i=0;i<n;i++){
        if(nge[i]==0) cout << "-1";
        else cout << arr[nge[i]];
        cout << " ";
    }
    return 0;
}