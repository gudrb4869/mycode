#include <iostream>
using namespace std;

int n,m;
long long a[1000000],ans,lo,hi,mid,length;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    lo=0,hi=1000000000;
    while(lo<=hi){
        mid=(lo+hi)/2;
        long long count=0;
        for(int i=0;i<n;i++){
            length=a[i]-mid;
            if(length>0)
                count+=length;
        }
        if(count>=m){
            ans=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
    cout << ans << '\n';
    return 0;
}