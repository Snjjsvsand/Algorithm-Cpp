#include<iostream>
#include<cstdio>
using namespace std;
const int N = 20;
bool col[N] , dg[N] , udg[N]; //�Խؾ�Ψһ��ʶһ���Խ��ߺ͸��Խ��� , ����Ϊ�˱�֤�Ǹ������鿪��һ�� (10 * 2)
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
		//i - u + nΪ�˱�֤�±�Ǹ�
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