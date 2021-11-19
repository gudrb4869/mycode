#include <iostream>
using namespace std;

int arr[100][10]={0,1,1,1,1,1,1,1,1,1};
int n;
long long sum;

int main(){
    cin >> n;

    for(int i=1;i<n;i++){
        for(int j=0;j<10;j++){
            if(j==0){
                arr[i][j]=arr[i-1][j+1];
            }
            else if(j==9){
                arr[i][j]=arr[i-1][j-1];
            }
            else{
                arr[i][j]=(arr[i-1][j-1]+arr[i-1][j+1])%1000000000;
            }
        }
    }
    for(int i=0;i<10;i++){
        sum+=arr[n-1][i];
    }
    cout << sum%1000000000 << '\n';
    return 0;
}