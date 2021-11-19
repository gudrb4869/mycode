#include <iostream>
using namespace std;

int main(){
    int l,p,arr[5];
    cin >> l >> p;
    for(int i=0;i<5;i++){
        cin >> arr[i];
        cout << arr[i]-l*p << ' ';
    }
    cout << '\n';
    return 0;
}