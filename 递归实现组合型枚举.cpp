#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n , m;
vector<int> chosen;

void dfs(int u) {
	// #0
	if (m == 0) return;
	if (chosen.size() + n - u + 1 < m || chosen.size() > m) return;
	if (u > n) {
		for (int i = 0;i < chosen.size();i++) cout << chosen[i] << ' ';
		cout << endl;
		return;
	}
	
	chosen.push_back(u);
	dfs(u + 1);
	// 上面函数执行后返回的位置 #1
	chosen.pop_back();
	dfs(u + 1);

	// 上面函数执行后返回的位置 #2
}

int main() {
	cin >> n >> m;
	dfs(1);
	return 0;
}