#include <iostream>
using namespace std;

int sudoku[9][9];

bool check(int x, int y, int k){
    for(int i=0;i<9;i++){
        if(sudoku[x][i]==k)
        return false;
        if(sudoku[i][y]==k)
        return false;
    }
    x=(x/3)*3, y=(y/3)*3;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(sudoku[i][j]==k)
            return false;
        }
    }
    return true;
}

void solve(int x, int y){
    if(x==9){
        cout << '\n';
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<< sudoku[i][j]<< ' ';
            }
            cout<<'\n';
        }
        exit(0);
    }
    if(sudoku[x][y]!=0){
        if(y==8) solve(x+1,0);
        else solve(x,y+1);
    }
    else{
        for(int k=1;k<=9;k++){
            if(check(x,y,k)){
                sudoku[x][y]=k;
                if(y==8) solve(x+1,0);
                else solve(x,y+1);
                sudoku[x][y]=0;
            }
        }
    }
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
        }
    }
    solve(0,0);
    return 0;
}