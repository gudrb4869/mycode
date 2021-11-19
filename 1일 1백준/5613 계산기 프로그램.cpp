#include <iostream>
using namespace std;

int sum, x;
char op;
int main(){
    cin >> sum;
    while(1){
        cin >> op;
        if(op=='=') break;
        cin >> x;
        if(op=='+') sum += x;
        else if(op=='-') sum -= x;
        else if(op=='*') sum *= x;
        else if(op=='/') sum /= x;
    }
    cout << sum;
    return 0;
}