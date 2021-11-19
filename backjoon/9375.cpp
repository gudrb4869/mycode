#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, string> a, pair<string, string> b){
    if(a.second==b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n==0){
            cout << "0\n";
        }
        else{
            string s1, s2;
            vector<pair<string, string>> v;
        
            for(int i = 0; i < n; i++){
                cin >> s1 >> s2;
                v.push_back(pair<string, string>(s1, s2));
            }
        
            sort(v.begin(), v.end(), compare);
        
            int result=1;
            int count=2;
        
            for(int i=1;i<n;i++){
                if(v[i].second==v[i-1].second) count++;
                else{
                    result*=count;
                    count=2;
                }   
            }
        
            result*=count;
            result--;
            cout << result << '\n';
            v.clear();
        }
    }
    return 0;
}