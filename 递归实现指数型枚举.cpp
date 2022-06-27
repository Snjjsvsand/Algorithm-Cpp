#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
// 2^n
int n;
vector<int> chosen;

void calc(int x) {
	if (x == n + 1) {
		for (int i = 0;i < chosen.size();i++) {
			cout << chosen[i] << ' ';
		}
		cout << endl;
		return;
	}

	calc(x + 1);

	chosen.push_back(x);
	calc(x + 1);
	chosen.pop_back();
}

int main() {
	cin >> n;
	calc(1);
	return 0;
}