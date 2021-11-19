#include <iostream>
#include <algorithm>
using namespace std;

int a[50];
int Max, Min;

int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    Max=Min=a[0];    
    for(int i=1;i<n;i++){
        Max=max(Max, a[i]);
        Min=min(Min, a[i]);
    }

    cout << Max*Min << '\n';
    return 0;
}