#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v, idx;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        v.push_back(a);
        idx.push_back(a);
    }

    sort(idx.begin(), idx.end());
    idx.resize(unique(idx.begin(), idx.end()) - idx.begin());
    //idx.erase(unique(idx.begin(), idx.end()), idx.end());

    for(int a : v){
        int pos = lower_bound(idx.begin(),idx.end(),a) - idx.begin();
        cout << pos << ' ';
    }
    return 0;
}