#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m, a, b, c , p[N] , res , cnt;

typedef struct {
	int a;
	int b;
	int w;
}Edge;
Edge edges[N*2];

bool compare(Edge& a , Edge& b ) {
	return a.w < b.w;
}

//每个并查集相当于一个连同分量
int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void kruskal() {
	sort(edges, edges + m, compare);
	for (int i = 0;i < m;i++) {
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		int pa = find(a), pb = find(b);
		if (pa != pb) {
			p[pa] = p b;
			cnt++;
			res += w;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) p[i] = i;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		edges[i] = { a , b , c };
	}

	kruskal();

	if (cnt == n - 1) cout << res << endl;
	else cout << "impossible" << endl;

	return 0;
}