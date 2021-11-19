#include <iostream>
using namespace std;

int n;
long long Min=1000000001,Max=-1000000001;
int an[11];
int op_num[4];

bool check(int k){
    if(op_num[k]==0) return false;
    return true;
}

void solve(int cnt,int val){
    if(cnt==n-1){
        if(val>Max) Max=val;
        if(val<Min) Min=val;
        return;
    }
    for(int k=0;k<4;k++){
        if(check(k)){
            int tmp=val;
            if(k==0) tmp+=an[cnt+1];
            else if(k==1) tmp-=an[cnt+1];
            else if(k==2) tmp*=an[cnt+1];
            else if(k==3) tmp/=an[cnt+1];
            op_num[k]--;
            solve(cnt+1,tmp);
            op_num[k]++;
        }
    }
}

int main(){
    cin >> n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>an[i];
    }
    for(int i=0;i<4;i++){
        cin>>op_num[i];
    }
    solve(0,an[0]);
    cout << Max << '\n';
    cout << Min << '\n';
    return 0;
}