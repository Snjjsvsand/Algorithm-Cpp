#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
// 分形经典题
typedef long long Long;
typedef pair<Long, Long> Pll;
int N, n;
Long a, b;

Pll calc(int n , Long m) {
	if (n == 0) return make_pair(0 , 0);
	Long len = 1ll << (n - 1);
	Long cnt = 1ll << (2 * n - 2);
	
	Pll pos = calc(n - 1 , m % cnt);
	Long x = pos.first, y = pos.second;
	int zone = m / cnt;

	if (zone == 0) return make_pair(-y - len, -x + len);
	else if (zone == 1) return make_pair(x + len, y + len);
	else if (zone == 2) return make_pair(x + len, y - len);
	else return make_pair(y - len , x - len);
}

int main() {
	cin >> N;
	while ( N-- ) {
		cin >> n >> a >> b;
		Pll pos1 = calc(n, a - 1);
		Pll pos2 = calc(n, b - 1);
		double dx = (double)(pos1.first - pos2.first);
		double dy = (double)(pos1.second - pos2.second);
		printf("%.0lf\n" , sqrt(dx * dx + dy * dy) * 5);
	}
	return 0;
}