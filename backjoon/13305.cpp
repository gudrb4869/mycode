#include <iostream>
using namespace std;

int dist[99999];
int city[100000];

int main(void){
    int n;
    int lower = 1000000001;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> dist[i];
    }
    long long val = 0;
    for(int i = 0; i < n; i++){
        cin >> city[i];
        if(lower > city[i]) lower = city[i];
        val += 1LL * lower * dist[i];
    }
    cout << val << '\n';
    return 0;
}