#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
// 离散化 , 排序

const int N = 2e5 + 10;
int n, m;
int a[N], b[N], c[N];
int lang[3 * N], uni[3 * N], res[3 * N], len1, len2;
int r1, r2, r3;

int find(int x) { // 保证有正确结果
	int l = 1, r = len2;
	while (l < r) {
		int mid = l + r >> 1;
		if (uni[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], lang[++len1] = a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i], lang[++len1] = b[i];
	for (int i = 1; i <= m; i++) cin >> c[i], lang[++len1] = c[i];

	sort(lang + 1, lang + 1 + len1);
	for (int i = 1;i <= len1; i++) if (i == 1 || lang[i] != lang[i - 1]) uni[++len2] = lang[i];

	for (int i = 1; i <= n; i++) res[find(a[i])]++;

	for (int i = 1; i <= m; i++) {
		int x = res[find(b[i])], y = res[find(c[i])];
		if (x > r2 || x == r2 && y > r3) r1 = i, r2 = x, r3 = y;
	}

	if (r1 == 0) cout << 1 << endl;
	else cout << r1 << endl;



	return 0;
}