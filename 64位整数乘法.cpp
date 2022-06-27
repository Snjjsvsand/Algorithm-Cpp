#include<iostream>
#include<cstdio>
using namespace std;
// 位运算&快速幂
typedef long long LL;
LL a, b, p;

LL multi64() {
	LL res = 0;
	while (b) {
		if (b & 1) res = (res + a) % p;
		a = (2 * a) % p;
		b >>= 1;
	}
	return res;
}

int main() {
	cin >> a >> b >> p;
	cout << multi64() << endl;
	return 0;
}