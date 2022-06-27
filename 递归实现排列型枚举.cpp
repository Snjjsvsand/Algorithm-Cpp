#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
// A nm / n!
int n;
int order[20];
bool chosen[20];

void calc(int x) {
	if (x == n + 1) {
		for (int i = 1;i <= n;i++) {
			cout << order[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 1;i <= n;i++) {
		if (!chosen[i]) {
			chosen[i] = true;
			order[x] = i;
			calc(x + 1);
			chosen[i] = false;
		}
	}

}

int main() {
	cin >> n;
	calc(1);
	return 0;
}