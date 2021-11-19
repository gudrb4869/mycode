#include <iostream>
#include <algorithm>
using namespace std;

int arr[1024][1024];
int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    
    while(N>1){
        N /= 2;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int temp[4];
                temp[0] = arr[i*2][j*2];
                temp[1] = arr[i*2][j*2+1];
                temp[2] = arr[i*2+1][j*2];
                temp[3] = arr[i*2+1][j*2+1];
                sort(temp, temp+4);
                arr[i][j] = temp[2];
            }
        }
    }
    cout << arr[0][0];
    return 0;
}