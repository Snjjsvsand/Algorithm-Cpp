#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 500 + 10;
int n, m, g[N][N], d[N], res, a, b, c; //���d�Ǿ༯�ϵľ���
bool st[N];

int min(int a , int b) {
	return a < b ? a : b;
}

void prime() {
	memset(d, 0x3f, sizeof d);
	for (int i = 0;i < n;i++) { //ÿ������뵽������
		int t = 0;
		for (int j = 1;j <= n;j++) {
			if (!st[j] && (!t || d[j] < d[t])) t = j;
		}
		st[t] = true;
		if (i) res += d[t];
		if (i && d[t] == 0x3f3f3f3f) {
			cout << "impossible" << endl;
			return;
		}
		for (int j = 1;j <= n;j++) { //���µ㵽���ϵľ���
			if(!st[j]) d[j] = min(d[j], g[t][j]);
		}
	}
	cout << res << endl;
}


int main() {
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	while ( m-- ) {
		cin >> a >> b >> c;
		g[b][a] = g[a][b] = min(g[a][b], c);
	}
	
	prime();

	return 0;
}