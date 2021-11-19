#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    v.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>v[v.size()-1]) v.push_back(arr[i]);
        else{
            int start=0;
            int end=v.size()-1;
            while(start<end){
                int mid=(start+end)/2;
                if(v[mid]>=arr[i])
                    start=mid+1;
                else
                    end=mid-1;
                v[start]=arr[i];
            }
        }
    }
    cout << v.size() << '\n';
    return 0;
    /*vector<int> a;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        auto it = lower_bound(a.begin(),a.end(),num);
        if(it==a.end()){
            a.push_back(num);
        }
        else{
            *it=num;
        }
    }
    cout << a.size() << '\n';
    return 0;*/
}