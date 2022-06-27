#include<iostream>
#include<cstdio>
using namespace std;
const int N = 10;
int n, path[N];
bool flag[N];

void dfs(int u) {
	if (u == n) {
		for (int i = 0;i < n;i++) cout << path[i] << ' ';
		cout << endl;
		return ;
	}

	for (int i = 1;i <= n;i++) {
		if (!flag[i]) {
			path[u] = i;
			flag[i] = true;
			dfs(u + 1);
			flag[i] = false;
		}
	}
}


int main() {
	cin >> n;
	dfs(0);	
	return 0;
}

