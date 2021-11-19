#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, C;
    cin >> N >> C;
    
    vector<int> x(N);
    for(int i=0; i<N; i++){
        cin >> x[i];
    }
    
    sort(x.begin(), x.end());
    
    int low = 0, high = x.back(), mid;
    int cnt, ans, x1,x2, d;
    
    while(low <= high){
        mid = (low+high)/2;
        cnt = 1;
        x1 = x.front();
        
        for(int i=1; i<N; i++){
            x2 = x[i];
            d = x2- x1;
            if(d >= mid){
                x1 = x2;
                cnt++;
            }
        }

        if(cnt < C)
            high = mid -1;
        else{
            ans = mid;
            low = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}