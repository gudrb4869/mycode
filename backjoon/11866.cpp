#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> q;
int main(){
    int n, k;
    string str="<";
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(1){
        for(int i=1;i<k;i++){
            q.push(q.front());
            q.pop();
        }
        str += to_string(q.front());
        q.pop();
        if(q.empty()) break;
        str += ", ";
    }
    str +=">";
    cout << str;
    return 0;
}