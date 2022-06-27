#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m, a, b, c, edges[N], ne[N], e[N], idx;
int color[N]; //0未染色 ， 1 ， 2 各代表一种颜色


void add(int a , int b) {
	e[++idx] = b;
	ne[idx] = edges[a];
	edges[a] = idx;
}

bool dfs(int u , int c) {
	color[u] = c;
	for (int i = edges[u]; i; i = ne[i]) {
		if (!color[e[i]]) {
			if (!dfs(e[i], 3 - c)) return false;
		}
		else if (color[e[i]] == c) return false;
	}
	return true;
}

int main() {
	cin >> n >> m;
	while ( m-- ) {
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	bool flag = true;
	for (int i = 1;i <= n;i++) {
		if (!color[i]) {
			if (!dfs(i, 1)) {
				flag = false;
				break;
			}
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}