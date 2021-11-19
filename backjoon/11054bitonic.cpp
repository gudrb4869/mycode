#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000],dp1[1000],dp2[1000];
int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        dp1[i]=1;
        dp2[i]=1;
    }
    dp1[0]=1;
    dp2[n-1]=1;
    for(int k=0;k<n;k++){
        for(int i=0;i<k;i++){
            if(arr[i]<arr[k]){
                dp1[k]=max(dp1[k],dp1[i]+1);
            }
        }
    }
    for(int k=n-1;k>=0;k--){
        for(int i=n-1;i>k;i--){
            if(arr[k]>arr[i]){
                dp2[k]=max(dp2[k],dp2[i]+1);
            }   
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp1[i]+dp2[i]);
    }
    cout << ans-1 << '\n';
    return 0;
}