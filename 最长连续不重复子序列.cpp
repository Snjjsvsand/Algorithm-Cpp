#include<cstdio>
#include<iostream>
using namespace std;
const int N = 100010;
int n, res, a[N], s[N]; // s[N] 用来记录a[i]出现的次数

int max(int a , int b) {
	return a >= b ? a : b;
}
/*
	1.初始[0-0]必然是连续不重复序列
	2.i指针向前走，如果出现重复，必然是a[i]重复，此时j向前走直到将a[i]相同的元素走过
	3.每次a[i]不重复都对比一下长度，长度最长的就是答案
*/
//j不会后退 ， 时间复杂度为O(n) (j最多跑n次，不是i跑一次j就跑n次)
//双指针算法 ： a指针相对于b指针具有单调性 j = f(i) 单调
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int i = 0, j = 0;i < n;i++) {
		s[a[i]]++;
		while (j<i && s[a[i]] > 1) s[a[j]]-- , j++;
		res = max(res, i - j + 1);
	}	

	cout << res << endl;

	return 0;
}