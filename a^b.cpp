#include<iostream>
#include<cstdio>
using namespace std;
// ¿ìËÙÃÝ
typedef long long LL;
LL a, b, p;

LL quick_mi() {
	LL res = 1 % p;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}


int main() {
	cin >> a >> b >> p;
	cout << quick_mi() << endl;
	return 0;
}