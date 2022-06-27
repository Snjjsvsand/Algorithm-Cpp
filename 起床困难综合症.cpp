#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
// 位运算(&,|,^,位运算由于不仅为，位之间互相不影响)
const int N = 1e5 + 10;
pair<string, int> op[N];
int n, m;

int calculate(int bit , int now) {
	for (int i = 0; i < n; i++) {
		int x = op[i].second >> bit & 1;
		if (op[i].first == "AND") now &= x;
		else if (op[i].first == "OR") now |= x;
		else now ^= x;
	}
	return now;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> op[i].first >> op[i].second;
	}
	int val = 0, res = 0;
	for (int bit = 29; bit >= 0; bit --) {
		int res0 = calculate(bit, 0);
		int res1 = calculate(bit, 1);
		if (val + (1 << bit) <= m && res1 > res0)
			val += 1 << bit, res += res1 << bit;
		else
			res += res0 << bit;
	}
	cout << res << endl;

	return 0;
}