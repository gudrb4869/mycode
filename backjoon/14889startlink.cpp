#include <iostream>
#include <cmath>
using namespace std;

int S[20][20];
int start[10];
int link[10];
int N,min_val=10000000;

void dfs(int si, int li, int index){
    if(si>N/2 || li >N/2) return;
    if(index==N){
        if(si!=N/2) return;
        int start_stat=0, link_stat=0, diff;

        for(int i=0;i<si;i++)
            for(int j=0;j<si;j++)
                start_stat+=S[start[i]][start[j]];

        for(int i=0;i<li;i++)
            for(int j=0;j<li;j++)
                link_stat+=S[link[i]][link[j]];

        diff=abs(start_stat-link_stat);
        if(min_val>diff) min_val=diff;
        return;
    }
    start[si]=index;
    dfs(si+1,li,index+1);
    link[li]=index;
    dfs(si,li+1,index+1);
}

int main(){

    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>S[i][j];
        }
    }

    dfs(0,0,0);
    cout << min_val<<'\n';
    return 0;
}