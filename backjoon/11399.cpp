#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());
    
    int sum = v[0];
    int temp = v[0];
    
    for(int i = 1; i < n; i++){
        temp += v[i];
        sum += temp;
    }
    
    cout << sum << '\n';
    return 0;
}