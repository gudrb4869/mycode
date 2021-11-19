#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000

int arr[MAX];
int n;

void input(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
}

void solution(){
    priority_queue<int> max_heap, min_heap;
    for(int i=0;i<n;i++){
        if(max_heap.size()>min_heap.size()) min_heap.push(-arr[i]);
        else max_heap.push(arr[i]);

        if(max_heap.size() && min_heap.size()){
            if(max_heap.top()>-min_heap.top()){
                int max_value=max_heap.top();
                int min_value=-min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(min_value);
                min_heap.push(-max_value);
            }
        }
        cout << max_heap.top() << '\n';
    }
}

void solve(){
    input();
    solution();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();    
    return 0;
}