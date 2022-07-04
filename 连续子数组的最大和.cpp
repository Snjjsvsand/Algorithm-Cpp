#include<iostream>
#include<cstdio>
using namespace std;
// 前缀和 改进了纯暴力算法O(n^3)的时间复杂度
const int N = 1010;
int a[N] , n;

int main() {
	cin >> n;
	int maxN = -0x3f3f3f3f;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	for (int i = 1; i < n; i++)
		for (int j = i; j < n; j++)
			maxN = max(maxN , a[j] - a[i - 1]);
	cout << maxN << endl;
	return 0;
}