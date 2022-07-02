#include<iostream>
#include<cstdio>
using namespace std;
const int N = 5010;
int n, r;
int x, y, w;
int maxX, maxY;
int a[N][N];

int main() {
	cin >> n >> r;
	maxX = maxY = r;
	while ( n-- ) {
		cin >> x >> y >> w;
		a[++x][++y] += w;
		maxX = max(maxX, x) , maxY = max(maxY, y);
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
		}
	}

	if (r >= N) cout << a[N - 1][N - 1] << endl;
	else {
		int res = -0x3f3f3f3f; // -1061109567
		for (int i = r; i < N; i++) {
			for (int j = r; j < N; j++) {
				res = max(res, a[i][j] - a[i - r][j] - a[i][j - r] + a[i - r][j - r]);
			}
		}
		cout << res << endl;
	}

	return 0;
}