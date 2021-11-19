#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}

int main(){
    int n;
    cin >> n;
    vector<int> radius(n, 0);
    for(int i=0;i<n;i++){
        cin >> radius[i];
    }
    for(int i=1;i<n;i++){
        int g=gcd(radius[i],radius[0]);
        cout << radius[0]/g << "/" << radius[i]/g << '\n';
    }
    return 0;
}