#include <iostream>
using namespace std;

int rect[2187][2187];
int p,z,m;

void func(int row, int x, int col, int y){
    bool minus=false,zero=false,plus=false;
    for(int i=row;i<x;i++){
        for(int j=col;j<y;j++){
            if(rect[i][j]==1) plus=true;
            else if(rect[i][j]==0) zero=true;
            else if(rect[i][j]==-1) minus=true;
        }
    }
    if((plus==true && zero==true) || (plus==true && minus==true) || (zero==true && minus==true)){
        func(row, row+(x-row)/3, col, col+(y-col)/3);
        func(row, row+(x-row)/3, col+(y-col)/3, col+2*(y-col)/3);
        func(row, row+(x-row)/3, col+2*(y-col)/3, y);
        
        func(row+(x-row)/3, row+2*(x-row)/3, col, col+(y-col)/3);
        func(row+(x-row)/3, row+2*(x-row)/3, col+(y-col)/3, col+2*(y-col)/3);
        func(row+(x-row)/3, row+2*(x-row)/3, col+2*(y-col)/3, y);

        func(row+2*(x-row)/3, x, col, col+(y-col)/3);
        func(row+2*(x-row)/3, x, col+(y-col)/3, col+2*(y-col)/3);
        func(row+2*(x-row)/3, x, col+2*(y-col)/3, y);
    }
    else if(plus==true && zero==false && minus==false){
        p++;
    }
    else if(plus==false && zero==true && minus==false){
        z++;
    }
    else if(plus==false && zero==false && minus==true){
        m++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> rect[i][j];
        }
    }
    func(0,n,0,n);
    cout << m << '\n' << z << '\n' << p << '\n';
    return 0;
}