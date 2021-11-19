#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int m, n;
char x[101], y[101];
char result_x[101], result_y[101];
int M[101][101], P[101][101];
int penalty;

void opt(int m, int n){
    for(int i=0; i<=m; i++) M[i][0] = 3*i;
    for(int j=0; j<=n; j++) M[0][j] = 3*j;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i] == y[j]) penalty=0; else penalty=2;
            M[i][j] = min(min(M[i-1][j-1]+penalty, M[i-1][j]+3), M[i][j-1]+3);

            if(M[i][j] == M[i-1][j-1]+penalty) P[i][j] = 1;
            else if(M[i][j] == M[i-1][j]+3) P[i][j] = 2;
            else if(M[i][j] == M[i][j-1]+3) P[i][j] = 3;
        }
    }
}

void align(int m, int n){
    int p = max(m, n);
    int i = m; int j = n;
    for(int k=p; k>=1; k--){
        switch(P[i][j]){
            case 1:
            result_x[k] = x[i];
            result_y[k] = y[j];
            i--; j--; break;
            case 2:
            result_x[k] = x[i];
            result_y[k] = '-';
            i--; break;
            case 3:
            result_x[k] = '-';
            result_y[k] = y[j];
            j--; break;
            default:
            break;
        }
    }
    for(int k=1; k<=p; k++){
        cout << result_x[k];
    }
    cout << '\n';
    for(int k=1; k<=p; k++){
        cout << result_y[k];
    }
    cout << '\n';
}

int main(){
    ifstream fin("C:\\Users\\user\\Desktop\\C++WorkSpace\\algo\\input.txt");
    if(!fin){
        cerr << "File can't open.\n";
        return 0;
    }
    int t;
    fin >> t;
    while(t--){
        fin >> m;
        for(int k=1; k<=m; k++){
            fin >> x[k];
        }

        fin >> n;
        for(int k=1; k<=n; k++){
            fin >> y[k];
        }
        opt(m,n);
        align(m,n);
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                cout << M[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    fin.close();
    return 0;
}
