#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int son[31*N][2], idx, n , res , a[N];

void insert(int x) {
	int p = 0;
	for (int i = 30;i >= 0;i--) {
		int u = x >> i & 1;
		if (!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
}

int search(int x) {
	int p = 0 , res = 0;
	for (int i = 30;i >= 0;i--) {
		int u = x >> i & 1;
		if (son[p][!u]) {
			res = res * 2 + 1;
			p = son[p][!u];
		}
		else {
			res *= 2;
			p = son[p][u];
		}
	}
	return res;
}


int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		insert(a[i]);
	}
	int res = 0;
	for (int i = 0;i < n;i++) res = max(res , search(a[i]));
	cout << res << endl;
	return 0;
}