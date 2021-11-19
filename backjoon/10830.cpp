#include <iostream>
using namespace std;

int n,m1[5][5],m2[5][5],result[5][5];
long long b;

void func(long long b){
    if(b==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                result[i][j]=m1[i][j]%1000;
            }
        }
        return;
    }
    func(b/2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m2[i][j]=0;
            for(int k=0;k<n;k++){
                m2[i][j]+=result[i][k]*result[k][j];
                m2[i][j]%=1000;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[i][j]=m2[i][j];
        }
    }
    if(b%2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m2[i][j]=0;
                for(int k=0;k<n;k++){
                    m2[i][j]+=m1[i][k]*result[k][j];
                    m2[i][j]%=1000;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                result[i][j]=m2[i][j];
            }
        }
    }
}

int main(){
    cin >> n >> b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> m1[i][j];
        }
    }
    func(b);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}