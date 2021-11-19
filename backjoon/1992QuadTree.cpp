#include <cstdio>
#include <iostream>
using namespace std;

bool rect[64][64];

void func(int row, int x, int col, int y){
    bool white=false,black=false;
    for(int i=row;i<x;i++){
        for(int j=col;j<y;j++){
            if(rect[i][j]==1) black=true;
            if(rect[i][j]==0) white=true;
        }
    }
    if(black==true && white==true){
        cout << "(";
        func(row,(row+x)/2,col,(col+y)/2);
        func(row,(row+x)/2,(col+y)/2,y);
        func((row+x)/2,x,col,(col+y)/2);
        func((row+x)/2,x,(col+y)/2,y);
        cout << ")";
    }
    else if(black==true && white==false){
        cout << "1";
    }
    else if(black==false && white==true){
        cout << "0";
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&rect[i][j]);
        }
    }
    func(0,n,0,n);
    return 0;
}