#include <iostream>
#include <string>
using namespace std;

string arr[5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0; i<5; i++){
        cin >> arr[i];
    }
    for(int i=0; i<arr[0].size(); i++){
        if(arr[1][i] == 'o'){
            arr[0][i] = 'o';
            arr[1][i] = 'w';
            arr[2][i] = 'l';
            arr[3][i] = 'n';
            arr[4][i] = '.';
        }
        else if(arr[1][i] == 'w'){
            arr[0][i] = '.';
            arr[1][i] = 'o';
            arr[2][i] = 'm';
            arr[3][i] = 'l';
            arr[4][i] = 'n';
        }
    }
    for(int i=0; i<5; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}