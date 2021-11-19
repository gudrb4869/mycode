#include <iostream>
using namespace std;

int n, m;
int arr[8];

void print() {
	for (int i = 0; i < m; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void dfs(int cnt, int start) {
	if (cnt == m) {
		print();
		return;
	}
	for (int i = start +1; i <= n; i++) {
		arr[cnt] = i;
		dfs(cnt + 1, i);
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);
	return 0;
}