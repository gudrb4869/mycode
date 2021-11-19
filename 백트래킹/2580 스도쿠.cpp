#include <iostream>
#define Square(x, y) ((x/3)*3+y/3)
using namespace std;

int sudoku[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

void print(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Sudoku(int n){
    if(n == 81){
        print();
        exit(0);
    }
    
    int x = n/9;
    int y = n%9;
    int sqr = Square(x, y);
    if(sudoku[x][y] == 0){
        for(int i=1; i<=9; i++){
            if(!row[x][i] && !col[y][i] && !square[sqr][i]){
                row[x][i] = col[y][i] = square[sqr][i] = true;
                sudoku[x][y] = i;
                Sudoku(n+1);
                sudoku[x][y] = 0;
                row[x][i] = col[y][i] = square[sqr][i] = false;
            }
        }
    }
    else{
        Sudoku(n+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] != 0){
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                square[Square(i, j)][sudoku[i][j]] = true;
            }
        }
    }

    Sudoku(0);
    return 0;
}