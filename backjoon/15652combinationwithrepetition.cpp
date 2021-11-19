#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

void dfs(int cnt, int start) {
	if (cnt == m) {
		print();
		return;
	}
	for (int i = start; i <= n; i++) {
		v.push_back(i);
		dfs(cnt + 1, start);
		start++;
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 1);
	return 0;
}