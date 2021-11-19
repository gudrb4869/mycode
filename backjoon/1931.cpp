#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second==b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < n; i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    int time = v[0].second;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(time <= v[i].first){
            time = v[i].second;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}