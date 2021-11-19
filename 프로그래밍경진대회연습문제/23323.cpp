#include <iostream>
#include <cmath>
using namespace std;

long long n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        long long result = 1 + m + floor(log2(n));
        cout << result << '\n';
    }
    return 0;
}