#include <iostream>

using namespace std;

int n, arr[1000001];

int main(){
    cin >> n;
    
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    
    for(int i=4;i<=n;i++){
        if(i%3==0){
            if(i%2==0){
                if(arr[i/3]<arr[i/2]) arr[i]=1+arr[i/3];
                else arr[i]=1+arr[i/2];
            }
            else{
                if(arr[i/3]<arr[i-1]) arr[i]=1+arr[i/3];
                else arr[i]=1+arr[i-1];
            }
        }
        else{
            if(i%2==0){
                if(arr[i-1]<arr[i/2]) arr[i]=1+arr[i-1];
                else arr[i]=1+arr[i/2];
            }
            else{
                arr[i]=1+arr[i-1];
            }
        }
    }

    cout << arr[n] << '\n';
    return 0; 
}