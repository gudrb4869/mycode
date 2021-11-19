#include <iostream>
#include <algorithm>
using namespace std;

int a[10000];
int k,n;
long long answer;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i=0;i<k;i++)
        cin >> a[i];
    
    sort(a,a+k);
    
    long long lo=1,hi=a[k-1];
    
    while(lo<=hi){
        int count=0;
        long long mid=(lo+hi)/2;
        
        for(int i=0;i<k;i++)
            count+=a[i]/mid;
        
        if(count>=n){
            answer=max(answer,mid);
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
    cout << answer << '\n';
    return 0;
}