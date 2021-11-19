#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long N, sum, k;
bool flag;
string s, tmp;
vector<long long> num;
vector<char> op;

int main(){
    cin >> N >> s;

    for(long long i=0; i<s.size(); i++){
        if(s[i] == 'S' || s[i] == 'M' || s[i] == 'U' || s[i] == 'P' || s[i] == 'C' || i == s.size() - 1){
            if(s[i] =='C') flag = 1;
            op.push_back(s[i]);
            if(tmp.size())num.push_back(stoi(tmp));
            tmp.clear();
        }
        else tmp += s[i];
    }

    if(!flag){
        cout << "NO OUTPUT\n";
        return 0;
    }
    sum = num[0];
    for(int i=0; i<op.size(); i++)
        if(op[i] =='S') sum -= num[++k];
        else if(op[i] =='M') sum *= num[++k];
        else if(op[i] =='U'){
            if(sum < 0) sum = -(-sum/num[++k]);
            else sum /= num[++k];
        }
        else if(op[i] =='P') sum += num[++k];
        else cout << sum << ' ';
}