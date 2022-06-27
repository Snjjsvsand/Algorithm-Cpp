#include<iostream>
#include<cstdio>
using namespace std;
const int N = 20;
bool col[N] , dg[N] , udg[N]; //以截距唯一标识一个对角线和副对角线 , 由于为了保证非负，数组开大一点 (10 * 2)
int g[N] , n;

void dfs(int u) {
	if (u > n) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				cout << (g[i] == j ? 'Q' : '.');
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	for (int i = 1;i <= n;i++) {
		//i - u + n为了保证下标非负
		if (!col[i] && !dg[i - u + n] && !udg[u + i]) {
			col[i] = true, dg[i - u + n] = true, udg[u + i] = true;
			g[u] = i;
			dfs(u + 1);
			col[i] = false, dg[i - u + n] = false, udg[u + i] = false;
		}
	}

}


int main() {
	cin >> n;
	dfs(1);
}