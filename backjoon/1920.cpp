#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int *a = new int [n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int m;
    cin >> m;
    int *num = new int [m];
    for(int i=0;i<m;i++){
        cin >> num[i];
        int lo=0, hi=n;
        while(true){
            int mid=(lo+hi)/2;
            if(num[i]==a[mid]){
                cout << "1\n";
                break;
            }
            else if(num[i]<a[mid]){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
            if(hi<lo || lo>hi){
                cout <<
                 "0\n";
                break;
            }
        } 
    }
    free(a);
    free(num);
    return 0;
}