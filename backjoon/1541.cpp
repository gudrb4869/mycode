#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s;
char num[6];

int main(void){
    cin >> s;
    int result = 0;
    int j = 0;
    int flag = 0;
    for(int i = 0; i <= s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num[j++] = s[i];
        }
        else{
            if(flag == 0){
                result += stoi(num);
                if(s[i]=='-'){
                    flag = 1;
                }
            }
            else{
                result -= stoi(num);
            }
            memset(num,0,sizeof(num));
            j = 0;
        }
    }
    cout << result << '\n';
    return 0;
}