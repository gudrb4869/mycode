#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long int mincost, sum;
int main(){
    cin >> N;
    vector<long long int> dist(N-1);
    for(int i=0; i<N-1; i++){
        cin >> dist[i];
    }
    vector<long long int> cost(N);
    for(int i=0; i<N; i++){
        cin >> cost[i];
    }
    mincost = cost[0];
    sum += mincost * dist[0];
    for(int i=1; i<N-1; i++){
        mincost = min(mincost, cost[i]);
        sum += mincost * dist[i];
    }
    cout << sum << '\n';
    return 0;
}