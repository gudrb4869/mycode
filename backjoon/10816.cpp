#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a.begin(),a.end());
    cin >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        cout << upper_bound(a.begin(),a.end(),x) - lower_bound(a.begin(),a.end(),x) << ' ';
    }
    cout << '\n';
    return 0;
}