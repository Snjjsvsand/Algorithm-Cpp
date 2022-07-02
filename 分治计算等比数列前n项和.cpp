#include<iostream>
#include<cstdio>
using namespace std;
// 分治(根据公式)
int a1, q, n; // an = a1 * q^(n - 1)

int quick_mi(int a, int b) { //return a^b
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int sum(int p , int c) { // sum(p , c) = 1 + p + p^2 + .... + p^c
	if (c == 0) return 1;
	if (c % 2) return (quick_mi(p, (c + 1) / 2) + 1) * sum(p, (c - 1) / 2);
	else return (quick_mi(p, c / 2) + 1) * sum(p , c / 2 - 1) + quick_mi(p , c);
}

int main() {
	cin >> a1 >> q >> n;
	cout << a1 * sum(q, n - 1) << endl;
	return 0;
}