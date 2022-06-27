#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int edge[N], ne[N * 2], e[N * 2], d[N] , idx, n, m, a, b , q[N] , h , t = -1;

void add(int a, int b) {
	e[++idx] = b;
	ne[idx] = edge[a];
	edge[a] = idx;
}

void bfs() {
	q[++t] = 1;
	d[1] = 0;

	while (h<=t) {
		int n = q[h++];
		for (int i = edge[n]; i ; i = ne[i]) {
			if (d[e[i]] == -1) {
				d[e[i]] = d[n] + 1;
				q[++t] = e[i];
			}
		}
	
	}
}

int main() {
	memset(d, -1, sizeof d);
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		add(a, b);
	}

	bfs();
	cout << d[n] << endl;
	return 0;
}