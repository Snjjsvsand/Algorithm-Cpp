#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
// 递推&位运算状态压缩
int dx[5] = {0 , -1 , 0 , 1 , 0}, dy[5] = {0 , 0 , 1 , 0 , -1};
// int g[5][5] , t[5][5];
string g[5], t[5];
int n;

bool isLegal(int x , int y) {
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}
void tap(int x , int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(isLegal(nx , ny)) t[nx][ny] = t[nx][ny] == '0' ? '1' : '0';
	}
}

int main() {
	cin >> n;
	while ( n-- ) {
		for (int i = 0;i < 5;i++) {
				cin >> g[i], t[i] = g[i];
		}
		int res = 0x3f3f3f3f;
		for (int i = 0; i < 1 << 5; i++) { // 00110代表第一行 不按 不按 按 按 不按
			int temp = i , cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (temp & 1) tap(0 , 4 - j) , cnt++;
				temp >>= 1;
			}
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 5; col++) {
					if (t[row][col] == '0') tap(row + 1, col) , cnt++;
				}
			}
			bool flag = true;
			for (int col = 0; col < 5; col++) {
				if (t[4][col] == '0') {
					flag = false;
					break;
				}
			}
			if (flag) res = min(res , cnt);

			for (int i = 0;i < 5;i++)
					t[i] = g[i];
		}
		cout << (res <= 6 ? res : -1) << endl;
	}

	return 0;
}