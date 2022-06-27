#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e2 + 10;
int g[N][N] , d[N][N] , n , m , h , t = -1;
pair<int, int> q[N * 2];

void bfs() {
	int dx[4] = { -1 , 0 , 1 , 0 }, dy[4] = {0 , 1 , 0 , -1};
	q[++t] = { 1 , 1 };
	d[1][1] = 0;
	while (h <= t) {
		pair<int, int> node = q[h++];
		for (int i = 0;i < 4;i++) {
			int x = node.first + dx[i], y = node.second + dy[i];
			if (x >= 1 && x <= n && y >= 1 && y <= m && d[x][y] == -1 && !g[x][y]) {
				d[x][y] = d[node.first][node.second] + 1;
				q[++t] = { x , y };
			}
		}
	}
}


int main() {
	memset(d, -1, sizeof d);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> g[i][j];
	bfs();
	cout << d[n][m] << endl;
	return 0;
}