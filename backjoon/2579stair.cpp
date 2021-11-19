#include <iostream>
#include <algorithm>
using namespace std;

int n, stairs[300], scores[300];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> stairs[i];
    }
    for(int i=0;i<n;i++){
        if(i==0)
            scores[i]=stairs[i];
        else if(i==1)
            scores[i]=stairs[i-1]+stairs[i];
        else if(i==2)
            if(stairs[i-1]>stairs[i-2])
                scores[i]=stairs[i-1]+stairs[i];
            else
                scores[i]=stairs[i-2]+stairs[i];
        else{
            if(scores[i-3]+stairs[i-1]>scores[i-2])
                scores[i]=scores[i-3]+stairs[i-1]+stairs[i];
            else
                scores[i]=scores[i-2]+stairs[i];
        }
    }
    cout << scores[n-1] << '\n';
    return 0;
}