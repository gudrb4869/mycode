#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> w(N);
    for(int i=0; i<N; i++){
        cin >> w[i].second >> w[i].first;
    }
    sort(w.begin(), w.end());
    int end = w[0].first;
    int cnt = 1;
    for(int i=1; i<N; i++){
        if(end <= w[i].second){
            cnt++;
            end = w[i].first;
        }
    }
    cout << cnt;
    return 0;
}