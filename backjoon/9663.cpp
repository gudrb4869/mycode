#include <iostream>
using namespace std;

int n, total;
bool arr[14][14];
bool y_check[14];

bool csp(int x, int y) {
	for(int i=0;i<n;i++){
        if(arr[x][i] || arr[i][y])
        return false;
    }
    int tmpx=x,tmpy=y;
    while(tmpx>=0&&tmpy>=0){
        if(arr[tmpx--][tmpy--])
        return false;
    }
    tmpx=x, tmpy=y;
    while(tmpx<n&&tmpy<n){
        if(arr[tmpx++][tmpy++])
        return false;
    }
    tmpx=x, tmpy=y;
    while(tmpx>=0&&tmpy<n){
        if(arr[tmpx--][tmpy++])
        return false;
    }
    tmpx=x,tmpy=y;
    while(tmpx<n&&tmpy>=0){
        if(arr[tmpx++][tmpy--])
        return false;
    }
    return true;
}

void dfs(int x,int max) {
    if(max>=1){
	    for (int j = 0; j < n; j++) {
            if(!y_check[j] && csp(x,j)){
		        y_check[j]=true;
                arr[x][j]=true;
                dfs(x+1,max-1);
                y_check[j]=false;
                arr[x][j]=false;
	        }
        }
    }
    else{
        total++;
    }
}

int main() {
	cin >> n;
	dfs(0,n);
	cout << total << '\n';
	return 0;
}