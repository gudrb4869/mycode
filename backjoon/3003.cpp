#include <iostream>
using namespace std;

int main(){
    int arr[6],arr2[6]={1,1,2,2,2,8};
    for(int i=0;i<6;i++){
        cin >> arr[i];
        arr2[i]-=arr[i];
        cout << arr2[i] << ' ';
    }
    cout << '\n';
    return 0;
}