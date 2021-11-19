#include <iostream>
using namespace std;

bool rect[128][128];
int white, blue;

void func(int row, int x, int col, int y){
    bool w=false,b=false;
    for(int i=row;i<x;i++){
        for(int j=col;j<y;j++){
            if(rect[i][j]==1) b=true;
            if(rect[i][j]==0) w=true;
        }
    }
    if(b==true && w==true){
        func(row,(row+x)/2,col,(col+y)/2);
        func(row,(row+x)/2,(col+y)/2,y);
        func((row+x)/2,x,col,(col+y)/2);
        func((row+x)/2,x,(col+y)/2,y);
    }
    else if(b==true && w==false){
        blue++;
    }
    else if(b==false && w==true){
        white++;
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
    cout << white << '\n' << blue << '\n';
    return 0;
}