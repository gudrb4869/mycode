#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> A;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        auto it = lower_bound(A.begin(), A.end(), temp);
        if(it == A.end()) A.push_back(temp);
        else *it = temp;
    }
    cout << A.size();
    return 0;
}