#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> brr;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    
    int n;
    cin >> n;    
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    sort(arr.begin(), arr.end());
    
    int igcd = arr[1] - arr[0];
    for(int i = 2; i < arr.size(); i++){
        igcd = gcd(igcd, arr[i] - arr[i - 1]);
    }
    
    for(int i = 1; i * i <= igcd; i++){
        if(igcd % i == 0){
            if(i != 1) brr.push_back(i);
            if(i != igcd / i) brr.push_back(igcd / i);
        }
    }
    sort(brr.begin(), brr.end());
    for(int i = 0; i < brr.size(); i++){
        cout << brr[i] << " ";
    }
    cout << '\n';
    return 0;
}