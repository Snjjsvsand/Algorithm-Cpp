#include<cstdio>
#include<iostream>
// ���ڶ��������/����ĳЩ��Χ�м���ĳЩֵ
//������������֮��
using namespace std;
const int N = 100010;
int n, m;
int a[N], d[N];

void insert(int l , int r , int x) {
	d[l] += x;
	d[r + 1] -= x;
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i], insert(i, i, a[i]);
	while (m--) {
		int l, r , c;
		cin >> l >> r >> c;
		insert(l , r , c);
	}
	for (int i = 1;i <= n;i++) d[i] += d[i - 1] , cout << d[i] << ' ';

	return 0;
}