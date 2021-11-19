#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,c;
    cin >> n >> c;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    int lo=0, hi=arr.back(), ans=0;
    int mid,cnt,x1,x2,d;
    while(lo<=hi){
        mid=(lo+hi)/2;
        cnt=1;
        x1=arr.front();
        for(int i=1;i<n;i++){
            x2=arr[i];
            d=x2-x1;
            if(d>=mid){
                x1=x2;
                cnt++;
            }
        }
        if(cnt<c)
            hi=mid-1;
        else{
            ans=mid;
            lo=mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}