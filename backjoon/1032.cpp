#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    int a_len = a.size();
    for(int i=0; i<n-1; i++){
        string b;
        cin >> b;
        for(int j=0; j<a_len; j++){
            if(a[j] != b[j])
                a[j] = '?';
        }
    }
    cout << a << '\n';
    return 0;
}