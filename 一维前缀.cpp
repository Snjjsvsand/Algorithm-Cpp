#include<cstdio>
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE
const int N = 100010;
int n, m;
int a[N], s[N];
//一般用来求区间和
int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	while (m--) {
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}