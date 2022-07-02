#include<iostream>
#include<cstdio>
using namespace std;
// 差分
const int N = 1e5 + 10;
int n, a[N], d[N];
long long p, q; // 差分数组中正数与负数的个数
// 差分中的Sn+1中的+1非常重要(见《算法竞赛进阶指南》)
long long longAbs(long long a) {
    return a > 0 ? a : -a;
}
//a[1~n] , 在[l , r]中的全部数据增加或减少， 可以改变d[n + 1]来描述r超过n的情况 , 改变d[1]来描述l比1小的情况
int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        d[i] = i == 1 ? a[i] : a[i] - a[i - 1];
        if (i - 1 && d[i] > 0) p += d[i]; // 从d[2]开始 d[1] = a[1]
        if (i - 1 && d[i] < 0) q -= d[i]; // d[i]为负数
    }
    for (int i = 0; i <= longAbs(p - q); i++) { // 输出可能的全部相等的a[i]的值
        cout << d[1] + i << endl;
    }
    cout << max(p, q) << endl << longAbs(p - q) + 1 << endl;
    return 0;
}