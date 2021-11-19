#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k,a[100][100],b[100][100];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    cin >> m >> k;
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cin >> b[i][j];
        }
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<k;y++){
            int val=0;
            for(int z=0;z<m;z++){
                val+=a[x][z]*b[z][y];
            }
            cout << val << ' ';
        }
        cout << '\n';
    }
    return 0;
}