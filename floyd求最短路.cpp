#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 210;
int n, m, k , d[N][N] , a , b , c;

void floyd() {
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
	cin >> n >> m >> k;
	memset(d, 0x3f, sizeof d);
	for (int i = 1;i <= n;i++) d[i][i] = 0;
	
	while (m--) {
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b] , c);
	}
	
	floyd();

	while (k--) {
		cin >> a >> b;
		if (d[a][b] >= 0x3f3f3f3f / 2) cout << "impossible" << endl;
		else cout << d[a][b] << endl;
	}

	return 0;
}