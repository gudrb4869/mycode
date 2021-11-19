#include <iostream>
using namespace std;
#define P 1000000007LL
typedef long long ll;

ll func(ll x, ll y){
    ll ret=1;
    while(y){
        if(y%2){
            ret*=x;
            ret%=P;
        }
        x*=x;
        x%=P;
        y/=2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    ll t1=1,t2=1;
    cin >> n >> k;

    for(int i=2;i<=n;i++){
        t1*=i; t1%=P;
    }
    for(int i=2;i<=k;i++){
        t2*=i; t2%=P;
    }
    for(int i=2;i<=n-k;i++){
        t2*=i; t2%=P;
    }

    ll result=func(t2,P-2);
    result%=P;
    result*=t1;
    result%=P;
    cout << result << '\n';
    return 0;
}