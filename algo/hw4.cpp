#include <iostream>
#include <fstream>
using namespace std;

void solve(int n);
bool promising(int k, int x, int y);
int sudoku[9][9];
int num, iter;

int main()
{
    fstream fin("input.txt");
    if(!fin)
    {
        cout << "file can't open\n";
        return 0;
    }

    fin >> num;
    
    for(iter=1;iter<=num;iter++)
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                fin >> sudoku[i][j];
        solve(0);
    }
    return 0;
}

void solve(int n)
{
    if(n==81)
    {
        cout << "sudoku " << iter << '\n';
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                cout << sudoku[i][j] << ' ';
            cout << '\n';
        }
        return;
    }
    
    int x=n/9, y=n%9;
    
    if(sudoku[x][y]!=0) solve(n+1);
    else
        for(int k=1;k<=9;k++)
            if(promising(k,x,y))
            {
                sudoku[x][y]=k;
                solve(n+1);
                sudoku[x][y]=0;
            }
}

bool promising(int k, int x, int y)
{
    for(int i=0;i<9;i++)
        if(sudoku[x][i]==k || sudoku[i][y]==k) return false;
    
    int sx=(x/3)*3, sy=(y/3)*3;
    
    for(int i=sx;i<sx+3;i++)
        for(int j=sy;j<sy+3;j++)
            if(sudoku[i][j]==k) return false;

    return true;
}