#include<iostream>
#include<cstdio>
using namespace std;
// 二分搜索 + 前缀和
const int N = 1e5 + 10;
int a[N];
int n, f;
double s[N], l, r;
// 平均值常用技巧（全部减去平均值）
// 类似于连续子数组最大和中的前缀和思想， 全部减去平均数之后，小于0的区间和会为后面带来负收益
bool valid(double x) {
	double minV = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - x;
	for (int i = f; i <= n; i++) {
		minV = min(minV, s[i - f]);
		if (s[i] - minV >= 0) return true;
	}
	return false;
}

int main() {
	cin >> n >> f;
	for (int i = 1; i <= n; i++) cin >> a[i], r = max(r, (double)a[i]);
	while (r - l > 1e-5) {
		double mid = (l + r) / 2;
		if (valid(mid)) l = mid;
		else r = mid;
	}
	cout << (int)(r * 1000) << endl;
	return 0;
}