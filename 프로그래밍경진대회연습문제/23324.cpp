#include <iostream>
using namespace std;

int parent[100001];
int n, m, k;
int src, dst;

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
    parent[x] += parent[y];
	parent[y] = x;
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
	for(int i=1; i<=n; i++)
		parent[i] = -1;

    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        if(i == k){
            src = u;
            dst = v;
            continue;
        }
        merge(u, v);
    }
    
    if(isUnion(src, dst)) cout << "0\n";
    else{
        long long result = (long long)parent[find(src)] * (long long)parent[find(dst)];
        cout << result << '\n';
    }
	return 0;
}