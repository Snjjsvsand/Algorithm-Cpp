#include<iostream>
#include<cstdio>
using namespace std;
// 有N本书排成一行，已知第i本的厚度是Ai。把它们分成连续的M组，使T最小化。T表示厚度之和最大的一组的厚度。
// 二分搜索经典例题
const int N = 10010;
int n, m;
int a[N];
int l, r;

// 如果s是一个可行解，则可以分M组，让每一组书的厚度叠起来都小于等于s ， 此时，最优解可以取[l , s] , 反之，可以取(s , r]
bool valid(int s) {
	int rest = s, group = 1;
	for (int i = 0;i < n; i++) {
		if (rest >= a[i]) rest -= a[i];
		else group++, rest = s - a[i];
	}
	return group <= m;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n; i++) cin >> a[i], r += a[i];
	while (l < r) {
		int mid = l + r >> 1;
		if (valid(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl; // l == r true
	return 0;
}