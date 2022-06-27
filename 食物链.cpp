#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e6;
int p[N] , d[N] , n , k , D , x , y , res;

int find(int x) {
	if (p[x] != x) {
		int u = p[x];
		p[x] = find(p[x]);
		d[x] = (d[x] + d[u]) % 3;
	}
	return p[x];
}

bool addSame(int x , int y) {
	int p1 = find(x);
	int p2 = find(y);
	if (p1 == p2) return d[x] == d[y];
	p[p2] = p1;
	d[p2] = (d[x] - d[y] + 3) % 3;
	return true;
}

bool addEat(int x , int y) {
	int p1 = find(x), p2 = find(y);
	if (p1 == p2) return (d[x] + 1) % 3 == d[y];
	p[p2] = p1;
	d[p2] = (d[x] - d[y] + 1 + 3) % 3;
	return true;
}


int main() {
	cin >> n >> k;
	for (int i = 1;i <= n;i++) p[i] = i, d[i] = 0;
	while ( k-- ) {
		cin >> D >> x >> y;
		if (x > n || y > n) res++;
		else if (D == 1 && !addSame(x, y)) res++;
		else if (D == 2 && !addEat(x, y)) res++;
	}

	cout << res << endl;

	return 0;
}