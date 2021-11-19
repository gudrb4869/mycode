#include <iostream>
#include <fstream>
#include <cstring>
#define MAX 1001

using namespace std;

int total;
int tree[MAX][2];
int cnt[MAX];

void post_order(int start){
    if(start == -1) return;
    int left = tree[start][0];
    int right = tree[start][1];
    post_order(left);
    post_order(right);
    if(cnt[left] < cnt[right]) total++;
    cnt[start] = cnt[left] + cnt[right] + 1;
}

int main(){
    ifstream fin("C:\\Users\\user\\Desktop\\C++WorkSpace\\algo\\input.txt");
    if(!fin){
        cerr <<  "File can't open.\n";
        return 0;
    }
    int t;
    fin >> t;
    while(t--){
        int N;
        fin >> N;
        for(int i=0; i<N; i++){
            int num, l, r;
            fin >> num >> l >> r;
            tree[num][0] = l;
            tree[num][1] = r;
        }

        post_order(1);
        cout << total << '\n';
        
        total = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(tree, 0, sizeof(tree));
    }
    fin.close();
    return 0;
}