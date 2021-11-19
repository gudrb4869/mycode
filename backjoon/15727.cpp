#include <iostream>
using namespace std;

int main(){
    int L;
    cin >> L;
    if(L%5) cout << L/5 + 1 << '\n';
    else cout << L/5 << '\n';
    return 0;
}