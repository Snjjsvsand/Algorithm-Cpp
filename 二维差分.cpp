#include<cstdio>
#include<iostream>
using namespace std;
const int N = 1010;
int n, m, q;
int a[N][N], d[N][N];

void insert(int x1 , int y1 , int x2 , int y2 , int x) {
	d[x1][y1] += x;
	d[x2 + 1][y2 + 1] += x;
	
	d[x2 + 1][y1] -= x;
	d[x1][y2 + 1] -= x;
}


int main() {
	cin >> n >> m >> q;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j], insert(i , j , i , j , a[i][j]);

	while (q--) {
		int x1, y1, x2, y2, x;
		cin >> x1 >> y1 >> x2 >> y2 >> x;
		insert(x1 , y1 , x2 , y2 , x);
	}

	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + d[i][j];

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++)
			cout << d[i][j] << ' ';
		cout << endl;
	}
		
			



	return 0;
}