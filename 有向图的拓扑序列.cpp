#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int edge[N], ne[N], e[N], idx, inner[N] , n , m, a , b;
int q[N], h, t = -1;
bool st[N];

void add(int a, int b) {
	e[++idx] = b;
	ne[idx] = edge[a];
	edge[a] = idx;
	inner[b]++;
}

void bfs() {
	for (int i = 1;i <= n;i++) {
		if (!inner[i]) {
			q[++t] = i;
			st[i] = true;
			break;
		}
	}

	while (h<=t) {
		int node = q[h++];
		for (int i = edge[node]; i; i = ne[i]) {
			inner[e[i]]--;
			if (!inner[e[i]] && !st[e[i]]) {
				q[++t] = e[i];
				st[e[i]] = true;
			}
		} 
	}

	if (t == n - 1) {
		for (int i = 0;i < n;i++) cout << q[i] << ' ';
	}
	else {
		cout << -1;
	}


}


int main() {
	cin >> n >> m;
	while ( m-- ) {
		cin >> a >> b;
		add(a, b);
		// inner[b] ++;
	}

	bfs();

	return 0;
}