#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
// c nm 组合公式
int n, m;
vector<int> chosen;

void calc(int x) {
	if (chosen.size() > m || n - x + 1 + chosen.size() < m) return;
	if (x == n + 1) {
		for (int i = 0;i < chosen.size();i++) {
			cout << chosen[i] << ' ';
		}
		cout << endl;
		return ;
	}

	calc(x + 1);

	chosen.push_back(x);
	calc(x + 1);
	chosen.pop_back();
}

int main() {
	cin >> n >> m;
	calc(1);
	return 0;
}